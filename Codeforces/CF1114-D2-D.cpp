#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// dp[l][r][k] means the number of operations needed if the part from l to r has the color of
// a[l] if k = 0 or a[r] if k = 1.

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

#define MOD 998244353

//----------------------------------------------------------------------------------------------------------------------
ll a[5005];
ll dp[5005][5005][2];
//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> a[i];
	}

	FOR(i, 0, n) {
		FOR(j, 0, n) {
			dp[i][j][0] = dp[i][j][1] = (i == j ? 0 : oo);
		}
	}

	FOR(r, 0, n) {
		ROF(l, r, 0) {
			FOR(k, 0, 2) {
				ll c = (k == 0 ? a[l] : a[r]);
				if (l)
					dp[l - 1][r][0] = min(dp[l - 1][r][0], dp[l][r][k] + (c != a[l - 1]));
				
				if (r + 1 != n) {
					dp[l][r + 1][1] = min(dp[l][r + 1][1], dp[l][r][k] + (c != a[r + 1]));
				}
			}
		}
	}

	cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << endl;

	return 0;
}