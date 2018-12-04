#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// dp[i][j] is the answer for the first ith elements and a sequence of size j. The answer is
// the sum of dp[n][j] for all j from 1 to n. dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] which is
// take the ith element if it is divisible by j and ignore it. Since the answer always
// recurse to i - 1, you can ignore one dimension.

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
ll dp[1000005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	
	ll n;
	cin >> n;
	dp[0] = 1;
	FOR(i, 0, n) {
		ll x;
		cin >> x;
		vi divs;
		for (ll j = 1; j * j <= x; j++) {
			if (x % j == 0) {
				divs.pb(j);
				if (j != x / j)
					divs.pb(x / j);
			}
		}

		sort(all(divs));
		ROF(j, sz(divs) - 1, 0) {
			dp[divs[j]] += dp[divs[j] - 1];
			dp[divs[j]] %= MOD;
		}
	}

	ll ans = 0;
	FOR(i, 1, n + 1) {
		ans += dp[i];
		ans %= MOD;
	}
	
	cout << ans << endl;

	return 0;
}