#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Iterate over everything and each time you get to a (, calculate the new possibilities,
// which are NK(x + y - 1, x), meaning the number of ways of taking x parenthesis out of
// x and y, which are the number of openings (x) and endings(y);

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define lld I64d
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
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ii, ll>> viii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll pre[200005], suf[200005];
ll fac[1000005], rfac[1000005];

ll fastPow(ll x, ll n) {
	ll ret = 1;
	while (n) 
	{
		if (n & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return ret;
}

ll NK(ll n, ll k) {
	return fac[n] * rfac[k] % MOD * rfac[n - k] % MOD;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	fac[0] = 1;

	FOR(i, 1, 1000001) {
		fac[i] = fac[i - 1] * i % MOD;
	}

	FOR(i, 0, 1000001) {
		rfac[i] = fastPow(fac[i], MOD - 2);
	}

	string str;
	cin >> str;

	if (str[0] == '(')
		pre[0] = 1;
	if (str[sz(str) - 1] == ')')
		suf[sz(str) - 1] = 1;
	
	FOR(i, 1, sz(str)) {
		pre[i] = pre[i - 1] + (str[i] == '(' ? 1 : 0);
	}

	ROF(i, sz(str) - 2, 0) {
		suf[i] = suf[i + 1] + (str[i] == ')' ? 1 : 0);
	}

	ll ans = 0;
	FOR(i, 0, sz(str)) {
		if (str[i] == ')') continue;
		ll x = pre[i];
		ll y = suf[i + 1];
		ans += NK(x + y - 1, x);
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}