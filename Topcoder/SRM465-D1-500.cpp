#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Solvable by min-cut. An edge from source to every base with capacity of the closest canon, an edge
// from each plant to sink with capacity of the closest canon and an edge from every plant to every base
// that are in range with infinite capacity. The min-cut will look for the cheapest way to
// either destroy a base directly or by destroying all the possible flow through its energy plants.

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
class GreenWarfare {
public:
	struct Edge {
	ll t, rev, cap, f;
	
	Edge(ll _t, ll _rev, ll _cap) {
		t = _t;
		rev = _rev;
		cap = _cap;
		f = 0;
	}
};

vector<Edge> graph[500];
ll dist[500];
ll ptr[500];
ll Q[500];

void addEdge(ll s, ll t, ll cap) {
	graph[s].pb(Edge(t, sz(graph[t]), cap));
	graph[t].pb(Edge(s, sz(graph[s]) - 1, 0));
}

bool dinicBfs(ll src, ll dest) {
	mem(dist, -1);
	dist[src] = 0;
	mem(Q, 0);
	ll sizeQ = 0;
	Q[sizeQ++] = src;
	FOR(i, 0, sizeQ) {
		ll u = Q[i];
		for (Edge e : graph[u]) {
			if (dist[e.t] < 0 && e.f < e.cap) {
				dist[e.t] = dist[u] + 1;
				Q[sizeQ++] = e.t;
			}
		}
	}

	return dist[dest] >= 0;
}

ll dinicDfs(ll dest, ll u, ll f) {
	if (u == dest)
		return f;

	for (; ptr[u] < sz(graph[u]); ++ptr[u]) {
		Edge &e = graph[u][ptr[u]];
		if (dist[e.t] == dist[u] + 1 && e.f < e.cap) {
			ll df = dinicDfs(dest, e.t, min(f, e.cap - e.f));
			if (df > 0) {
				e.f += df;
				graph[e.t][e.rev].f -= df;
				return df;
			}
		}
	}

	return 0;
}

ll maxFlow(ll src, ll dest) {
	ll flow = 0;
	mem(dist, 0);
	while (dinicBfs(src, dest)) {
		mem(ptr, 0);
		while (true) {
			ll pushed = dinicDfs(dest, src, INT_MAX);
			if (pushed == 0)
				break;
			flow += pushed;
		}
	}

	return flow;
}

	ll dst(ll x1, ll y1, ll x2, ll y2) {
		ll x = abs(x1 - x2);
		x = x * x;
		ll y = abs(y1 - y2);
		y = y * y;
		return x + y;
	}

	int minimumEnergyCost(vector <int> canonX, vector <int> canonY, vector <int> baseX, vector <int> baseY, vector <int> plantX, vector <int> plantY, int energySupplyRadius) {
		FOR(i, 0, sz(baseX)) {
			ll champ = oo;
			ll idx = -1;
			FOR(j, 0, sz(canonX)) {
				ll d = dst(baseX[i], baseY[i], canonX[j], canonY[j]);
				if (d < champ) {
					champ = d;
					idx = j;
				}
			}

			addEdge(0, 1 + i, champ);
		}

		FOR(i, 0, sz(plantX)) {
			ll champ = oo;
			ll idx = -1;
			FOR(j, 0, sz(canonX)) {
				ll d = dst(plantX[i], plantY[i], canonX[j], canonY[j]);
				if (d < champ) {
					champ = d;
					idx = j;
				}
			}

			addEdge(sz(baseX) + 1 + i, sz(baseX) + 1 + sz(plantX), champ);
		}

		FOR(i, 0, sz(baseX)) {
			FOR(j, 0, sz(plantX)) {
				ll d = dst(baseX[i], baseY[i], plantX[j], plantY[j]);
				double dd = sqrt(d);
				if (dd <= energySupplyRadius) {
					addEdge(1 + i, sz(baseX) + 1 + j, oo);
				}
			}
		}

		return maxFlow(0, sz(baseX) + sz(plantX) + 1);
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	
	

	return 0;
}