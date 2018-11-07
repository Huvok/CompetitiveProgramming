#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// Start by counting all the possible ways to "give" n flowers to k boxes, which is n + k - 1 choose k - 1,
// however some boxes will be given (or taken) more flowers than they should, so use inclusion-exlusion to substract/add answers.
// Iterate over bitmask of boxes and if the ith box-bit is on, then you will count the amount of answers
// such that this box exceeds its limit (if the number of excess boxes is odd, substract, if even add).
// If there are some boxes with excess, the amount of solutions is n + k - 1 - x choose k - 1, where
// x is the sum of f[i] + 1 of each box, where f[i] is the amount of flowers of the ith box.

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
ll a[25];

ll rfac[1000005];

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
	if (k > n) return 0;
	if (n - k < k) k = n - k;
	n %= MOD;
	ll ret = 1;
	FOR(i, 0, k) {
		ret = (ret * (n - i)) % MOD;
		ret = (ret * rfac[i + 1]) % MOD;
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	ll n, s;
	cin >> n >> s;
	FOR(i, 0, n)
		cin >> a[i];

	FOR(i, 1, 25)
		rfac[i] = fastPow(i, MOD - 2);

	ll ans = 0;
	ll limit = 1LL << n;
	FOR(mask, 0, limit) {
		ll x = s;
		ll cnt = 0;
		FOR(i, 0, n) {
			if (mask & (1LL << i)) {
				x -= (a[i] + 1);
				cnt++;
			}
		}

		if (x < 0)
			continue;
		ll aux = NK(x + n - 1, n - 1);
		if (cnt & 1)
			ans = (ans - aux + MOD) % MOD;
		else
			ans = (ans + aux) % MOD;
	}

	cout << ans << endl;

	return 0;
}

