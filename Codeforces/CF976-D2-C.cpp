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
//                                          //IDEA: Sort segments first ascending by left side, then descending by
//                                          //      right side, then maintain the rightmost segment in a variable.
//                                          //      If you meet a segment while iterating them that its right side is
//                                          //      smaller or equal than the one you maintain, then thats the answer
//                                          //      since they are ordered by their left sides.

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
pair<ii, ll> a[300005];

bool cmp(pair<ii, ll> p, pair<ii, ll> q)
{
	if (p.first.first == q.first.first)
		return p.first.second > q.first.second;

	return p.first.first < q.first.first;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n;
	cin >> n;

	FOR(i, 0, n)
	{
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second = i + 1;
	}

	sort(a, a + n, cmp);

	ll champ = a[0].first.second;
	ll idx = a[0].second;;
	FOR(i, 1, n)
	{
		if (champ >= a[i].first.second)
		{
			cout << a[i].second << " " << idx << endl;
			return 0;
		}
		else
		{
			champ = a[i].first.second;
			idx = a[i].second;
		}
	}

	cout << -1 << " " << -1 << endl;

	return 0;
}

//======================================================================================================================