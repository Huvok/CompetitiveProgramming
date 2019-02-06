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

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }

const double EPS = .000000001;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
ll dp[2005][2005];
#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;

	ll n, l, m, t;
	cin >> t;

	while (t--)
	{
		cin >> n >> l >> m;

		mem(dp, 0);

		FOR(i, 1, l + 1)
		{
			FOR(j, 1, n + 1)
			{
				if (i == 1)
					dp[i][j] = j;
				else
				{
					dp[i][j] = (j + m <= n ? dp[i - 1][j + m] : dp[i - 1][n]) - (j - m - 1 >= 0 ? dp[i - 1][j - m - 1] : 0);
					dp[i][j] = (dp[i][j] + MOD) % MOD;
					dp[i][j] += dp[i][j - 1];
					dp[i][j] %= MOD;
				}
			}
		}

		cout << dp[l][n] << endl;
	}
	
	return 0;
}

//======================================================================================================================