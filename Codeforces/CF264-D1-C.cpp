#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Define dp[col[i]] as the answer for a subsequence that ends with the color of the ith ball.
// Maintain the two highest values overall, and the color of the highest value. This
// way you can check if the next ball is the same color than the best answer yet.

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
ll dp[100005];
ll col[100005], val[100005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, q;
	cin >> n >> q;

	FOR(i, 0, n)
		cin >> val[i];

	FOR(i, 0, n)
		cin >> col[i];

	while (q--) {
		mem(dp, 0);
		ll a, b;
		cin >> a >> b;
		ll cand1 = 0, candCol = 0, cand2 = -oo;
		FOR(i, 0, n + 1)
			dp[i] = -oo;

		FOR(i, 0, n) {
			ll ans;
			if (col[i] == candCol)
				ans = max(cand1 + a * val[i], cand2 + b * val[i]);
			else
				ans = max(cand1 + b* val[i], dp[col[i]] + a * val[i]);
			
			if (ans > cand1) {
				if (candCol != col[i])
					cand2 = cand1;
				cand1 = ans;
				candCol = col[i];
			}
			else if (col[i] != candCol &&
				ans > cand2)
				cand2 = ans;
			
			dp[col[i]] = max(dp[col[i]], ans);
		}

		cout << cand1 << endl;
	}

	return 0;
}