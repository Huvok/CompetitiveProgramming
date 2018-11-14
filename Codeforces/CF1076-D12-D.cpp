#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Run dijkstra and record the last edge that updated the distance to a node (the edge that makes the shortest path to that node)
// and when visiting the current node, put this edge into a vector of answers, stop then the size of the vector reaches k.

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
viii adj[300005];
ll dist[300005];
ll vis[300005];
ll v;
ll winner[300005];
vi ans;
ll k;

void dijkstra(ll src) {
	priority_queue<ii, vii, greater<ii>> pq;
	mem(vis, false);
	FOR(i, 1, v + 1) dist[i] = oo;
	pq.push(mp(0, src));
	dist[src] = 0;
	while (!pq.empty()) {
		ll u = pq.top().second;
		pq.pop();

		if (vis[u])
			continue;
		vis[u] = true;
		if (sz(ans) == k)
			break;
		if (u != src)
			ans.pb(winner[u]);
		FOR(i, 0, adj[u].size()) {
			ll v = adj[u][i].first.first;
			ll w = adj[u][i].first.second;

			if (!vis[v] && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				winner[v] = adj[u][i].second;
				pq.push(mp(dist[v], v));
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, m;
	cin >> n >> m >> k;
	v = n;
	FOR(i, 0, m) {
		ll s, d, w;
		cin >> s >> d >> w;
		adj[s].pb(iii(ii(d, w), i));
		adj[d].pb(iii(ii(s, w), i));
	}
	
	dijkstra(1);
	cout << sz(ans) << endl;
	FOR(i, 0, sz(ans)) {
		cout << ans[i] + 1 << " ";
	}

	cout << endl;

	return 0;
}