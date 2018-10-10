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
// Each digit contributes to the answer its value di * 10^l, where l is the spaces until the next +, and after that
//      you need to place k - 1 signs in n - l - 1 places (l since you don't want any sign between the digit and l, and
//      one since l + 1 is a plus sign. Also, if there are no signs after the current digit, it contributes di * 10 ^ 
//      n - i - 1 and the number of ways to place k signs in i places. Just rearrange this sums and you'll notice
//      you can skip a loop by using prefix sums.

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
#define sz(x) (ll)(x).size()
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
ll dp[100005];

ll fac[100005], rfac[100005];

ll NK(ll n, ll k)
{
	return fac[n] * rfac[k] % MOD*rfac[n - k] % MOD;
}

ll fastPow(ll x, ll n) {
	ll ret = 1;
	while (n) {
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

	ll n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	dp[0] = str[0] - '0';
	FOR(i, 1, n)
		dp[i] = (dp[i - 1] + (str[i] - '0')) % MOD;

	fac[0] = 1;

	FOR(i, 1, 100001)
	{
		fac[i] = fac[i - 1] * i % MOD;
	}

	FOR(i, 0, 100001)
	{
		rfac[i] = fastPow(fac[i], MOD - 2);
	}

	ll ans = 0;
	FOR(l, 0, n - 1) {
		if (n - 2 - l < k - 1)
			break;
		ans = (ans + fastPow(10, l) % MOD * NK(n - 2 - l, k - 1) % MOD * dp[n - l - 2] % MOD) % MOD;

	}

	FOR(i, k, n) {
		ans = (ans + (str[i] - '0') * fastPow(10, n - 1 - i) % MOD * NK(i, k) % MOD) % MOD;

	}

	cout << ans << endl;

	return 0;
}

//======================================================================================================================