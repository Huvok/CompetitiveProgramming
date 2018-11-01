#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <queue>
#include <bitset>
#include <sstream>
#include <set>
#include <iomanip>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <iterator>
#include <complex>

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcountll __popcnt64
#endif

using namespace std;

//                                          //AUTHOR: Hugo Garcia
// Run dijkstra to calculate distances to all nodes from s. Then, for every edge check if there exists a point on that edge,
// but be careful to check how many points, since there can be at most two points for every edge and they can overlap.

//======================================================================================================================

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
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll v, e, s, d, w;
vii adj[100005];
ll dist[100005];

void dijkstra(ll src)
{
	priority_queue<ii, vii, greater<ii>> pq;
	FOR(i, 1, v + 1) dist[i] = INT_MAX;
	pq.push(mp(0, src));
	dist[src] = 0;

	while (!pq.empty())
	{
		ll u = pq.top().second;
		pq.pop();

		FOR(i, 0, adj[u].size())
		{
			ll v = adj[u][i].first;
			ll w = adj[u][i].second;

			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push(mp(dist[v], v));
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	cin >> v >> e >> s;
	vector<pair<ii, ll>> edges;
	FOR(i, 0, e) {
		ll a, b;
		cin >> a >> b >> w;
		adj[a].pb(ii(b, w));
		adj[b].pb(ii(a, w));
		edges.pb(mp(ii(a, b), w));
	}

	ll l;
	cin >> l;
	dijkstra(s);
	ll ans = 0;
	FOR(i, 0, e) {
		ll u = edges[i].first.first;
		ll v = edges[i].first.second;
		ll w = edges[i].second;
		if (l > dist[u] &&
			l < dist[u] + w &&
			w - (l - dist[u]) + dist[v] > l)
			ans++;

		if (l > dist[v] &&
			l < dist[v] + w &&
			w - (l - dist[v]) + dist[u] > l)
			ans++;

		if (l > dist[u] &&
			l > dist[v] &&
			dist[u] + dist[v] + w == l * 2)
			ans++;
	}

	FOR(i, 1, v + 1) {
		if (dist[i] == l)
			ans++;
	}

	cout << ans << endl;

	return 0;
}