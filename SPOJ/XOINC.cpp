#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// dp[i][j][k] is a pair that stores the answer for both players taking into account the last i coins, where
// the last player took j coins and the current turn is the player k. The answer for dp[i][j][k] is the maximum of all
// dp[i - cur][cur][1 - k] where cur is a possible amount of coins to be taken. If the current turn is k = 0, then
// you take the dp that gives you the max answer for the first element of the pair, if not you take the maximum of
// the second element. You can iterate in increasing order of j's so that you reuse cur and prevent an extra loop.

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
ll a[2005];
ii dp[2005][2005][2];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];

	reverse(a, a + n);
	mem(dp, 0);
	FOR(i, 1, n + 1) {
		FOR(k, 0, 2) {
			ll cur = 1;
			ll sum = 0;
			ii champ(0, 0);
			FOR(j, 1, n + 1) {
				while (cur <= j * 2 && i - cur >= 0) {
					sum += a[i - cur];

					if (!k) {
						if (champ.first < dp[i - cur][cur][1].first + sum) {
							champ.first = dp[i - cur][cur][1].first + sum;
							champ.second = dp[i - cur][cur][1].second;
						}
					}
					else {
						if (champ.second < dp[i - cur][cur][0].second + sum) {
							champ.second = dp[i - cur][cur][0].second + sum;
							champ.first = dp[i - cur][cur][0].first;
						}
					}

					cur++;
				}

				dp[i][j][k] = champ;
			}
		}
	}

	cout << dp[n][1][0].first << endl;

	return 0;
}

