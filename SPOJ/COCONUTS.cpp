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
// Flow problem. Connect every 1 to source, every 0 to index and every edge in the input with a capacity of 1. The answer
//      is the minimum cut since cutting an edge between source/dest to a node means the nodes changes value, and
//      cutting an edge between two nodes means you are "accepting" their disagreement.

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
struct Edge
{
	ll t, rev, cap, f;

	Edge(ll _t, ll _rev, ll _cap)
	{
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

void addEdge(ll s, ll t, ll cap)
{
	graph[s].pb(Edge(t, sz(graph[t]), cap));
	graph[t].pb(Edge(s, sz(graph[s]) - 1, 0));
}

bool dinicBfs(ll src, ll dest)
{
	mem(dist, -1);
	dist[src] = 0;
	mem(Q, 0);
	ll sizeQ = 0;
	Q[sizeQ++] = src;
	FOR(i, 0, sizeQ)
	{
		ll u = Q[i];
		for (Edge e : graph[u])
		{
			if (dist[e.t] < 0 && e.f < e.cap)
			{
				dist[e.t] = dist[u] + 1;
				Q[sizeQ++] = e.t;
			}
		}
	}

	return dist[dest] >= 0;
}

ll dinicDfs(ll dest, ll u, ll f)
{
	if (u == dest)
		return f;

	for (; ptr[u] < sz(graph[u]); ++ptr[u])
	{
		Edge &e = graph[u][ptr[u]];
		if (dist[e.t] == dist[u] + 1 && e.f < e.cap)
		{
			ll df = dinicDfs(dest, e.t, min(f, e.cap - e.f));
			if (df > 0)
			{
				e.f += df;
				graph[e.t][e.rev].f -= df;
				return df;
			}
		}
	}

	return 0;
}

ll maxFlow(ll src, ll dest)
{
	ll flow = 0;
	mem(dist, 0);
	while (dinicBfs(src, dest))
	{
		mem(ptr, 0);
		while (true)
		{
			ll pushed = dinicDfs(dest, src, INT_MAX);
			if (pushed == 0)
				break;
			flow += pushed;
		}
	}

	return flow;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n, m;
	while (true) {
		cin >> n >> m;
		if (n + m == 0)
			break;

		FOR(i, 0, n + 2) {
			graph[i].clear();
		}

		FOR(i, 0, n) {
			ll x;
			cin >> x;
			if (x) {
				addEdge(0, i + 1, 1);
			}
			else {
				addEdge(i + 1, n + 1, 1);
			}
		}

		FOR(i, 0, m) {
			ll s, d;
			cin >> s >> d;
			addEdge(s, d, 1);
			addEdge(d, s, 1);
		}

		cout << maxFlow(0, n + 1) << endl;
	}

	return 0;
}

//======================================================================================================================