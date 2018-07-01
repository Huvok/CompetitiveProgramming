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
//                                          //IDEA: Lets process the numbers one by one. First we take the answer out of
//                                          //      our acumulative array, then process the number x. Split it into the
//                                          //      middle representation and have an array called cnt[i][j][k] that
//                                          //      represents the amount of numbers that have a hamming dist with i
//                                          //      of k units and their right part is equal to j. Then for the answer
//                                          //      iterate for j from 0 to 255 and for k from 0 to 8, and sum to the
//                                          //      answer that corresponds to ans[k + dist(right part, j)], cnt[left
//                                          //      part][j][k], which means that you will add the numbers that differ
//                                          //      on x of distance (all this cases are covered in the iterations by
//                                          //      k and j) and these answers are located on the acum array for numbers
//                                          //      that differ from the left part on exactly k places and their right
//                                          //      part is equal to j, since you already know the right part differs on
//                                          //      dist(right part, j), the only difference left is k.

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
ll a[200005], dp[260][260][10], dist[260];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n, m;
	cin >> n >> m;

	FOR(i, 0, 256)
		dist[i] = __builtin_popcount(i);

	FOR(i, 0, n)
		cin >> a[i];

	FOR(i, 0, n)
	{
		ll le = a[i] >> 8;
		ll ri = a[i] & 255;

		ll ans[20] = { 0 };
		FOR(j, 0, 256) 
		{
			FOR(k, 0, 9)
			{
				ans[k + dist[ri ^ j]] += dp[le][j][k];
			}
		}

		FOR(j, 0, 256)
		{
			dp[j][ri][dist[le ^ j]]++;
		}

		FOR(i, 0, m + 1)
		{
			cout << ans[i] << " ";
		}

		cout << endl;
	}

	return 0;
}

//======================================================================================================================