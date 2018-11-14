#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <queue>
#include <bitset>
#include <sstream>
#include <set>
#include <iomanip>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <iterator>
#include <complex>

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

using namespace std;

//                                          //AUTHOR: Hugo Garcia
//                                          //IDEA: We start with one segment inside a set that starts at 0 and has a
//                                          //      size of n. Sort the distances and start from the biggest one, say k,
//                                          //      k + 1 is a possible answer, lets iterate to the smaller ones, now k
//                                          //      is smaller and possibly divides the segment into two parts, so cut
//                                          //      and delete the segment from the set, then add the one(s) that are 
//                                          //      created/updated. On every iteration keep track of the size of the
//                                          //      segments in an array. If at some time the size of the created
//                                          //      segments is equal to the size of the set and the set is at least
//                                          //      as big as the last answer, update the answer.

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, VA_ARGS), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 100000000000000000

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ii a[100005], b[100005];
ll cnt[100005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i].first;
		a[i].second = i;
		b[i] = a[i];
	}

	sort(b, b + n);

	ll bestk = b[n - 1].first + 1;
	ll bestsz = 1;
	set<ii> s;
	s.insert(mp(0, n));
	cnt[n] = 1;
	ROF(i, n - 1, 1)
	{
		auto x = s.lower_bound(mp(b[i].second, -1));
		if (x == s.end() ||
			x->first > b[i].second)
			x--;

		cnt[x->second]--;
		ii aux = ii(-1, -1);
		ii bux = ii(-1, -1);
		if (x->first != b[i].second)
		{
			ll length = b[i].second - x->first;
			aux = mp(x->first, length);
			cnt[length]++;
		}

		if (x->first + x->second - 1 != b[i].second)
		{
			ll length = x->first + x->second - b[i].second - 1;
			bux = mp(b[i].second + 1, length);
			cnt[length]++;
		}

		s.erase(x);
		if (aux.first != -1)
			s.insert(aux);
		if (bux.first != -1)
			s.insert(bux);
		if (sz(s) > 0 &&
			cnt[s.begin()->second] == sz(s) &&
			sz(s) >= bestsz)
		{
			bestsz = sz(s);
			bestk = b[i - 1].first + 1;
		}
	}

	cout << bestk << endl;

	return 0;
}

//======================================================================================================================