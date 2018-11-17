#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// dp[i][j] is the answer when you are in the ith picture and have j repostings left and you have reposted the ith picture.
// The answer for dp[i][j] is dp[d][j + 1] where k goes from i - k  to i - 1. You can make it efficient by
// maintaining a max queue in that range since each time i changes only one element enters and one goes out.

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
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ii, ll>> viii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll a[5005];
ll dp[5005][5005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, k, x;
	cin >> n >> k >> x;
	FOR(i, 0, n)
		cin >> a[i];
	
	mem(dp, -1);
	deque<ll> dq, mdq;
	FOR(i, 0, k)
		dp[i][x - 1] = a[i];
	
	ROF(j, x - 2, 0) {
		dq.clear();
		mdq.clear();
		FOR(i, 0, n) {
			ll besto = 0;
			if (!mdq.empty())
				besto = mdq.front();
			if (besto == -1)
				dp[i][j] = -1;
			else
				dp[i][j] = besto + a[i];

			dq.push_back(dp[i][j + 1]);
			while (!mdq.empty() && mdq.back() < dp[i][j + 1]) {
				mdq.pop_back();
			}
			mdq.push_back(dp[i][j + 1]);
			if (i >= k) {
				if (mdq.front() == dq.front())
					mdq.pop_front();
				dq.pop_front();
			}
		}
	}

	ll ans = -1;
	FOR(i, n - k, n) {
		FOR(j, 0, x + 1) {
			ans = max(ans, dp[i][0]);
		}
	}

	cout << ans << endl;

	return 0;
}