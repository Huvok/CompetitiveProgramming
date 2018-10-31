#include <bits/stdc++.h>

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// Create a graph, for query 1 add the trivial edge. For query 2, add an edge from the origin vertex
// to a vertex in a segment tree that represents the range. For query 3, add edge from the vertex on the segment
// tree of the range to the vertex in the original graph. Also add edges of cost 0 between the nodes of the
// segment tree and leaves to the original vertexes in the graph. Finally run dijkstra on everything.

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
ll v, e, s;
#define maxN 100005
vii adj[800005];
ll dist[800005];

void dijkstra(ll src)
{
	priority_queue<ii, vii, greater<ii>> pq;
	FOR(i, 0, 800005) dist[i] = oo;
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

ll ss;
ll segmentTree[2][4 * 100005];
ll nx;

void precalcSegmentTree()
{
	FOR(i, 1, ss) {
		segmentTree[0][i] = nx++;
		segmentTree[1][i] = nx++;
	}

	FOR(i, 0, v) {
		segmentTree[0][ss + i] = nx++;
		segmentTree[1][ss + i] = nx++;
		adj[segmentTree[0][ss + i]].pb(ii(i, 0));
		adj[i].pb(ii(segmentTree[1][ss + i], 0));
	}

	for (ll i = ss - 1; i; i--) {
		adj[segmentTree[0][i]].pb(ii(segmentTree[0][i << 1], 0));
		adj[segmentTree[0][i]].pb(ii(segmentTree[0][i << 1 | 1], 0));
		adj[segmentTree[1][i << 1]].pb(ii(segmentTree[1][i], 0));
		adj[segmentTree[1][i << 1 | 1]].pb(ii(segmentTree[1][i], 0));
	}
}

void update(ll n, ll l, ll r, ll d, ll start, ll w, ll t) {
	if (l > r)
		return;
	if (!l &&
		r == d - 1) {
		if (!t)
			adj[start].pb(ii(segmentTree[0][n], w));
		else
			adj[segmentTree[1][n]].pb(ii(start, w));
		return;
	}

	d /= 2;
	update(n << 1, l, min(d - 1, r), d, start, w, t);
	update(2 * n + 1, max(0LL, l - d), r - d, d, start, w, t);
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	cin >> v >> e >> s;
	s--;
	nx = v;
	ss = 1LL << (ll)ceil(log2(v));
	precalcSegmentTree();

	FOR(i, 0, e) {
		ll t;
		cin >> t;
		if (t == 1) {
			ll a, b, w;
			cin >> a >> b >> w;
			a--; b--;
			adj[a].pb(ii(b, w));
		}
		else {
			ll a, l, r, w;
			cin >> a >> l >> r >> w;
			a--;
			l--;
			r--;
			update(1, l, r, ss, a, w, t - 2);
		}
	}

	dijkstra(s);
	FOR(i, 0, v) {
		if (dist[i] == oo)
			cout << -1 << " ";
		else
			cout << dist[i] << " ";
	}
	cout << endl;

	return 0;
}

