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
//                                          //IDEA: Define dp[t1][t2][i] as the best answer when you have t1 and t2
//                                          //      items left to test and you are on the ith facility. In every state
//                                          //      do a linear scan over the amount of items m in each facility, let j
//                                          //      be the iteration variable, if you have at least j t1 items and
//                                          //      m - j t2 items, recurse to dp[t1 - j][t2 - (m - j)][i + 1].

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
ll costs[35][3][25], dp[305][305][35], dpk[305][305][35];
ll cnt[35];
ll n;

ll solve(ll t1, ll t2, ll i)
{
	if (t1 + t2 == 0)
		return 0;

	if (i >= n)
		return 1e9;

	if (dp[t1][t2][i] != -1)
		return dp[t1][t2][i];

	ll ret = 1e9;
	ll retk = 0;
	if (t2 >= cnt[i])
		ret = costs[i][2][cnt[i]] + solve(t1, t2 - cnt[i], i + 1);

	ll aux = 0;
	ll last = ret;
	FOR(j, 1, cnt[i] + 1)
	{
		if (t1 >= j)
		{
			if (t2 < cnt[i] - j)
				continue;

			if (j < cnt[i])
				aux = costs[i][2][cnt[i] - j];
			else
				aux = 0;

			ret = min(ret, costs[i][1][j] + aux + solve(t1 - j, t2 - (cnt[i] - j), i + 1));

			if (ret != last)
			{
				last = ret;
				retk = j;
			}
		}
		else
			break;
	}

	dpk[t1][t2][i] = retk;
	return dp[t1][t2][i] = ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll t1, t2;
	while (true)
	{
		cin >> t1 >> t2;

		if (!(t1 + t2))
			break;

		cin >> n;
		FOR(i, 0, n)
		{
			ll m;
			cin >> m;
			cnt[i] = m;

			FOR(j, 1, m + 1)
				cin >> costs[i][1][j];

			FOR(j, 1, m + 1)
				cin >> costs[i][2][j];
		}

		mem(dp, -1);
		mem(dpk, -1);
		cout << solve(t1, t2, 0) << endl;

		FOR(i, 0, n)
		{
			ll x = dpk[t1][t2][i];
			cout << x << " ";
			t1 -= x;
			t2 -= cnt[i] - x;
		}

		cout << endl;
		cout << endl;
	}

	return 0;
}

//======================================================================================================================