#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// dp[i][1] is the answer for subtree at i if you are going to go back to i and then up, dp[i][0] is the answer but if you going to finish the path in the subtree.
// dp[i][1] is trivial, is the best k - 1 answers for all children u (dp[u][1]). For dp[i][0] you have to iterate over all children u and take the best answer
// from dp[u][0] + sum(best k - 1 dp[j][1] that are not u).

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
vii adj[100005];
ll dp[100005][2];
ll n, k;

void solve(ll u, ll p) {

	vii cands;
	FOR(j, 0, sz(adj[u])) {
		ii v = adj[u][j];
		if (v.first != p) {
			solve(v.first, u);
			cands.pb(ii(dp[v.first][1] + v.second, v.first));
		}
	}

	sort(all(cands), greater<ii>());
	set<ll> s;
	bool flag = false;
	ll sum = 0;
	ll summ1 = 0;
	FOR(i, 0, min(k - 1, sz(cands))) {
		dp[u][1] += cands[i].first;
		sum += cands[i].first;
		summ1 += cands[i].first;
		s.insert(cands[i].second);
	}

	if (sz(cands) >= k)
		summ1 += cands[k - 1].first;

	FOR(j, 0, sz(adj[u])) {
		ii v = adj[u][j];
		if (v.first != p) {
			if (s.find(v.first) != s.end()) {
				dp[u][0] = max(dp[u][0], dp[v.first][0] + summ1 - dp[v.first][1]);
			}
			else {
				dp[u][0] = max(dp[u][0], dp[v.first][0] + v.second + sum);
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	
	cin >> n >> k;
	FOR(i, 0, n - 1) {
		ll u, v, c;
		cin >> u >> v >> c;

		adj[u].pb(ii(v, c));
		adj[v].pb(ii(u, c));
	}

	solve(0, -1);
	
	cout << dp[0][0] << endl;

	return 0;
}