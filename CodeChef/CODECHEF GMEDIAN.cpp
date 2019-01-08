#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Let's substract bad subsets from all subsets. Only even size subsets can be bad. For a subset to be
// good, the middle elements must be equal, so iterate over every possible i and fix it
// as the middle-left element. If it has frequency m[a[i]] and there are sm strictly smaller
// elements in the array, then the number of bad subsets is NK(i - 1, x - 1) * NK(n - m[a[i]] - sm, x),
// which is the number of ways to take x - 1 elements from the left of the ith element times number of ways
// of taking x elements from the remaining strictly greater elements.

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
ll a[1005];

ll fac[1000005], rfac[1000005];

ll fastPow(ll x, ll n) {
	ll ret = 1;
	while (n) {
		if (n & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return ret;
}

ll NK(ll n, ll k) {
	if (k > n)
		return 0;
	return fac[n] * rfac[k] % MOD*rfac[n - k] % MOD;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll t;
	cin >> t;

	fac[0] = 1;

	FOR(i, 1, 1000001) {
		fac[i] = fac[i - 1] * i % MOD;
	}

	FOR(i, 0, 1000001) {
		rfac[i] = fastPow(fac[i], MOD - 2);
	}

	while (t--) {
		ll n;
		cin >> n;
		map<ll, ll> m;
		FOR(i, 0, n) {
			cin >> a[i];
			m[a[i]]++;
		}

		sort(a, a + n);

		ll ans = fastPow(2, n) - 1;
		ll smaller = 0;
		FOR(i, 0, n - 1) {
			if (i) {
				if (a[i - 1] != a[i])
					smaller += m[a[i - 1]];
			}
			FOR(j, 1, n / 2 + 1) {
				ll cur = NK(i, j - 1);
				cur = (cur * NK(n - smaller - m[a[i]], j)) % MOD;
				ans = ans - cur;
				ans = (ans + MOD) % MOD;
			}
		}

		cout << ans << endl;
	}
	

	return 0;
}