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
//                                          //IDEA: Lets define a dp state as dp[i][j] where i is the current room and
//                                          //      j is the amount of people considered until this point, which will
//                                          //      always be less or equal than x[i]. To get to the dp[i][j] state
//                                          //      we need to check all the ways to getting there, we will always
//                                          //      consider only the last room (i - 1) obviously, but we need to
//                                          //      consider all possible j from which we could get here, which are
//                                          //      those in range j - y[i] <= k <= j where sum[i] is the sum of
//                                          //      x[i] until this room inclusive. This means that is we have n 
//                                          //      people to be considered (j) and this room capacity is y[i], we can
//                                          //      only get to this state if we already assigned at least j - y[i]
//                                          //      people and at most sum[i] people (otherwise we would have more
//                                          //      assigned people that the amount we want to calculate for this state,
//                                          //      j. So for every k in the range, the amount of people to consider is
//                                          //      (sum[i] - k) choose (j - k) * dp[i - 1][k], i.e. the amount of ways
//                                          //      of choosing the amount of people we need to get to j people, having
//                                          //      sum[i] - k people not assigned, multiplied by the amount of ways to
//                                          //      get to the state we are coming from.

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
ll dp[105][1005], x[105], y[105], sum[105], fact[1005], rfact[1005];
#define MOD 1000000007

ll NK(ll n, ll k)
{
	return (fact[n] % MOD * rfact[n - k] % MOD * rfact[k] % MOD) % MOD;
}

ll fastPow(ll x, ll n)
{
	ll ret = 1;
	while (n)
	{
		if (n & 1) 
			ret = ret * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	fact[0] = fact[1] = 1;
	FOR(i, 2, 1005)
	{
		fact[i] = (i % MOD * fact[i - 1] % MOD) % MOD;
	}

	ROF(i, 1004, 0)
	{
		rfact[i] = fastPow(fact[i], MOD - 2);
	}

	ll n;
	cin >> n;

	FOR(i, 1, n + 1)
		cin >> x[i];

	FOR(i, 1, n + 1)
		cin >> y[i];

	FOR(i, 1, n + 1)
		sum[i] = x[i] + sum[i - 1];

	FOR(i, 0, x[1] + 1)
		dp[1][i] = NK(x[1], i);

	FOR(i, 2, n + 1)
	{
		FOR(j, 0, sum[i] + 1)
		{
			ll start = max(0LL, j - y[i]);
			FOR(k, start, j + 1)
			{
				dp[i][j] += (NK(sum[i] - k, j - k) % MOD * dp[i - 1][k] % MOD) % MOD;
				dp[i][j] %= MOD;
			}
		}
	}

	ll ans = dp[n][sum[n]];
	FOR(i, 1, n + 1)
	{
		ans = (ans % MOD * NK(sum[n] - sum[i - 1], x[i]) % MOD) % MOD;
	}

	cout << ans << endl;

	return 0;
}

//======================================================================================================================