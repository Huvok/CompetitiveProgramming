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
#  define __builtin_popcount __popcnt
#endif

using namespace std;

//                                          //AUTHOR: Hugo Garcia
//                                          //IDEA: Run Dijkstra for every pair of nodes i, j, i < j. Maintain the list
//                                          //      of pointers for every node to its optimal path and at the end of
//                                          //      every Dijkstra run a dfs starting from the destination node and
//                                          //      ending on the source node, counting every edge you pass.

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
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, VA_ARGS), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 100000000000000000

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll v, e, s, d, w;
vii adj[105];
ll dist[105];
ll cnt[105][105];
vi p[105];
bool vis[105];

void dfs(ll i, ll src)
{
	if (i == src)
		return;

	vis[i] = true;
	FOR(j, 0, sz(p[i]))
	{
		ll v = p[i][j];
		cnt[i][v]++;
		cnt[v][i]++;
		if (!vis[v])
			dfs(v, src);
	}
}

void dijkstra(ll src, ll dst)
{
	priority_queue<ii, vii, greater<ii>> pq;
	FOR(i, 1, v + 1) dist[i] = 1e17;
	pq.push(mp(0, src));
	dist[src] = 0;
	FOR(i, 1, v + 1)
		p[i].clear();

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
				p[v].clear();
				p[v].pb(u);
			}
			else if (dist[v] == dist[u] + w)
				p[v].pb(u);
		}
	}

	mem(vis, false);
	dfs(dst, src);
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	while (cin >> v >> e)
	{
		vii edges;
		FOR(i, 1, v + 1)
		{
			adj[i].clear();
		}

		FOR(i, 0, e)
		{
			cin >> s >> d >> w;
			adj[s].pb(ii(d, w));
			adj[d].pb(ii(s, w));
			edges.pb(ii(s, d));
		}

		mem(cnt, 0);

		FOR(i, 1, v + 1)
		{
			FOR(j, i + 1, v + 1)
			{
				dijkstra(i, j);
			}
		}

		ll champ = 0;
		FOR(i, 1, v + 1)
		{
			FOR(j, 1, v + 1)
			{
				champ = max(champ, cnt[i][j]);
			}
		}

		FOR(i, 0, sz(edges))
		{
			if (cnt[edges[i].first][edges[i].second] == champ)
				cout << (i + 1) << (i < sz(edges) - 1 ? " " : "");
		}

		cout << endl;
	}

	return 0;
}

//======================================================================================================================