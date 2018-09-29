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
// dp[i][j][k] means the ith prefix, we have built j houses and k = 1 means we will build a house here. If k = 1, we
//      update dp[i + 1][j + 1][1] with the current plus the difference between the house on i + 1 and the minimum
//      house between i and i + 2 (since we are building one yes, one no and one yes). Also we update the i + 2 just
//      as we woulnd't build a house there. For k = 0 it is similar, we go to i + 1 and try to build a house there and
//      not.

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
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll a[5005];
ll dp[5005][5005][2];

ll get(ll i, ll v)
{
	v--;
	return max(0LL, a[i] - v);
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;

	ll n;
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];

	mem(dp, 0x3f3f3f3f);

	dp[0][0][0] = 0;
	dp[0][1][1] = 0;
	ll limit = n / 2 + (n & 1);
	FOR(i, 0, n)
	{
		FOR(j, 0, limit + 1)
		{
			FOR(k, 0, 2)
			{
				ll d = dp[i][j][k];
				if (!k)
				{
					dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], dp[i][j][0] + get(i, a[i + 1]));
					dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][0]);
				}
				else
				{
					dp[i + 2][j + 1][1] = min(dp[i + 2][j + 1][1], dp[i][j][1] + get(i + 1, min(a[i], a[i + 2])));
					dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][1] + get(i + 1, a[i]));
				}
			}
		}
	}

	FOR(i, 1, (n + 1) / 2 + 1)
	{
		cout << min(dp[n - 1][i][0], dp[n - 1][i][1]) << " ";
	}

	cout << endl;

	return 0;
}

//======================================================================================================================