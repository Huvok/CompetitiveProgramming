#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// Corner cases when m = k and n = l, then ans is 1, if m = k OR n = l, answer is 0. The answer is m choose k * n choose l * extra,
// where extra is the number of ways of filling the rest of the cells such that in no column nor row there are all zeroes.
// We can calculate extra with inclusion-exclusion. Take all possible answers (except where you take all zeros), if n
// is the rest of rows and m the rest of columns, then the possibilities are (2^m - 1)^n, but you are
// counting some invalid answers, so you have to substract the number of ways of taking m - 1 columns and filling those columns
// with any number except all zeroes.

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
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll fac[1000005], rfac[1000005];
#define MOD 1000000007

ll fastPow(ll x, ll n)
{
	ll ret = 1;
	while (n)
	{
		if (n & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return ret;
}

ll NK(ll n, ll k)
{
	return fac[n] * rfac[k] % MOD*rfac[n - k] % MOD;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	fac[0] = 1;

	FOR(i, 1, 1000001)
	{
		fac[i] = fac[i - 1] * i % MOD;
	}

	FOR(i, 0, 1000001)
	{
		rfac[i] = fastPow(fac[i], MOD - 2);
	}

	ll m, n, k, l;
	cin >> m >> n >> k >> l;

	ll ans = NK(m, k) * NK(n, l) % MOD;
	m -= k;
	n -= l;
	if (!n && !m)
		cout << ans << endl;
	else if (!n || !m)
			cout << 0 << endl;
	else {
		ll cur = 2;
		ll aux = 0;
		ll b = (m - 1) & 1;
		FOR(i, 1, m + 1) {
			ll x = NK(m, i) * fastPow(cur - 1, n) % MOD;
			if (b % 2 == 0)
				aux = (aux + x) % MOD;
			else
				aux = (aux - x + MOD) % MOD;

			cur = cur * 2 % MOD;
			b = 1 - b;
		}

		cout << ans * aux % MOD << endl;
	}

	return 0;
}

