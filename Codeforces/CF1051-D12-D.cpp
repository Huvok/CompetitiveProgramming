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
//                                          //IDEA: dp[i][k][u][d] means the prefix i, we have k components left, the
//                                          //      last i had its upper square of color u and lower one of color d.
//                                          //      When we go to the next i we try all 4 posibilities of coloring the
//                                          //      two new squares and if we are starting a new component (i.e. u = 1,
//                                          //      d = 0 and we will color upper with 0 and lower with 1, we are starting
//                                          //      two new components) we substract the amount from k. If we reach the
//                                          //      end with k = 0, the answer is 1 way of coloring.

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

#define MOD 998244353

//----------------------------------------------------------------------------------------------------------------------
ll n;
ll dp[1005][2005][2][2];

ll solve(ll i, ll k, ll up, ll down)
{
	if (k < 0)
		return 0;
	if (k == 0 && i >= n)
		return 1;
	if (i >= n)
		return 0;

	if (dp[i][k][up][down] != -1)
		return dp[i][k][up][down];

	ll ans = 0;
	if (up == 0 && down == 0)
	{
		ans = (ans + solve(i + 1, k, 0, 0)) % MOD;
		ans = (ans + solve(i + 1, k - 1, 0, 1)) % MOD;
		ans = (ans + solve(i + 1, k - 1, 1, 0)) % MOD;
		ans = (ans + solve(i + 1, k - 1, 1, 1)) % MOD;
	}
	else if (up == 0 && down == 1)
	{
		ans = (ans + solve(i + 1, k, 0, 0)) % MOD;
		ans = (ans + solve(i + 1, k, 0, 1)) % MOD;
		ans = (ans + solve(i + 1, k - 2, 1, 0)) % MOD;
		ans = (ans + solve(i + 1, k, 1, 1)) % MOD;
	}
	else if (up == 1 && down == 0)
	{
		ans = (ans + solve(i + 1, k, 0, 0)) % MOD;
		ans = (ans + solve(i + 1, k - 2, 0, 1)) % MOD;
		ans = (ans + solve(i + 1, k, 1, 0)) % MOD;
		ans = (ans + solve(i + 1, k, 1, 1)) % MOD;
	}
	else if (up == 1 && down == 1)
	{
		ans = (ans + solve(i + 1, k - 1, 0, 0)) % MOD;
		ans = (ans + solve(i + 1, k - 1, 0, 1)) % MOD;
		ans = (ans + solve(i + 1, k - 1, 1, 0)) % MOD;
		ans = (ans + solve(i + 1, k, 1, 1)) % MOD;
	}

	return dp[i][k][up][down] = (ans % MOD);
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;

	ll k;
	cin >> n >> k;
	mem(dp, -1);
	ll ans = solve(1, k - 1, 0, 0) % MOD;
	ans = (ans + solve(1, k - 2, 0, 1)) % MOD;
	ans = (ans + solve(1, k - 2, 1, 0)) % MOD;
	ans = (ans + solve(1, k - 1, 1, 1)) % MOD;

	if (n == 1)
	{
		ans = 2;
	}

	cout << ans << endl;

	return 0;
}

//======================================================================================================================