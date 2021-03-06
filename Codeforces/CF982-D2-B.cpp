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
//                                          //IDEA: Use two priority queues, one for the introverts and one for the 
//                                          //      extroverts. The first one is full and the second one empty. When an
//                                          //      introvert comes, pop out one from their queue and push it into the
//                                          //      another one. When one extrovert comes, pop from their queue and 
//                                          //      print it.

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
ll a[200005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n;
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];

	string s;
	cin >> s;

	priority_queue<ii> introvert, extrovert;
	FOR(i, 0, n)
	{
		introvert.push(mp(-a[i], i + 1));
	}

	FOR(i, 0, 2 * n)
	{
		if (s[i] == '0')
		{
			cout << introvert.top().second << " ";
			ii x = introvert.top();
			introvert.pop();
			extrovert.push(mp(x.first * -1, x.second));
		}
		else
		{
			ii x = extrovert.top();
			extrovert.pop();
			cout << x.second << " ";
		}
	}
	cout << endl;

	return 0;
}

//======================================================================================================================