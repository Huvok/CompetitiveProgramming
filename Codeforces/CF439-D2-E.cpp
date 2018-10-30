#include <bits/stdc++.h>

using namespace std;

//                                          //AUTHOR: Hugo Garcia
// The number of ways of putting "balls" into "urns", and at least one ball per urn, is NK(k - 1, n - 1), so we want all those
// ways and substract those ways in which gcd of all is something different than 1, so we can calculate
// dp[j] which is the number of ways for putting n candies into f friends, which is NK(k - 1, n - 1) - dp[n / d] where d
// is all the divisors of n, this is true because if a gcd is, say, 2, we would be compressing all candies into n / 2 candies,
// so each candy we place now is like placing two of them.

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

typedef int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll dp[100005];
vi divisors[100005];

void sieve() {
	FOR(i, 2, 100005) {
		for (ll j = i; j < 100005; j += i) {
			divisors[j].pb(i);
		}
	}
}

ll fac[100005], rfac[100005];

ll fastPow(ll x, ll n)
{
	ll ret = 1;
	while (n)
	{
		if (n & 1) ret = (long long)ret * x % MOD;
		x = (long long)(x) * x % MOD;
		n >>= 1;
	}
	return ret;
}

ll NK(ll n, ll k)
{
	return (long long)fac[n] * rfac[k] % MOD*rfac[n - k] % MOD;
}

ll q;
ll mark[100005];
ll solve(ll n, ll f) {
	if (n == f)
		return 1;
	if (n < f)
		return 0;

	if (mark[n] == q)
		return dp[n];

	ll ret = NK(n - 1, f - 1);

	FOR(i, 0, sz(divisors[n])) {
		ll it = divisors[n][i];
		ret = (ret - solve(n / it, f) + MOD) % MOD;
	}

	mark[n] = q;
	return dp[n] = ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	sieve();
	fac[0] = 1;

	FOR(i, 1, 100001)
	{
		fac[i] = (long long)fac[i - 1] * i % MOD;
	}

	FOR(i, 0, 100001)
	{
		rfac[i] = fastPow(fac[i], MOD - 2);
	}

	cin >> q;
	mem(mark, -1);
	while (q--) {
		ll n, f;
		cin >> n >> f;
		cout << solve(n, f) << endl;
	}

	return 0;
}

