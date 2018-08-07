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
//                                          //IDEA: 

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
#define oo 100000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
const int MAXN = 10000;
typedef ll tf;
typedef ll tc;
const tf INFFLUJO = 1e14;
const tc INFCOSTO = 1e14;
struct edge {
	int u, v;
	tf cap, flow;
	tc cost;
	tf rem() { return cap - flow; }

	edge(int _u, int _v, int _cap, int _flow, int _cost)
	{
		u = _u;
		v = _v;
		cap = _cap;
		flow = _flow;
		cost = _cost;
	}
};
int nodes; //numero de nodos
vector<int> G[MAXN]; // limpiar!
vector<edge> e;  // limpiar!
void addEdge(int u, int v, tf cap, tc cost) {
	G[u].pb(sz(e)); e.pb(edge(u, v, cap, 0, cost));
	G[v].pb(sz(e)); e.pb(edge(v, u, 0, 0, -cost));
}
tc dist[MAXN], mnCost;
int pre[MAXN];
tf cap[MAXN], mxFlow;
bool in_queue[MAXN];
void flow(int s, int t) {
	mem(in_queue, 0);
	mxFlow = mnCost = 0;
	while (1) {
		fill(dist, dist + nodes, INFCOSTO); dist[s] = 0;
		memset(pre, -1, sizeof(pre)); pre[s] = 0;
		mem(cap, 0); cap[s] = INFFLUJO;
		queue<int> q; q.push(s); in_queue[s] = 1;
		while (sz(q)) {
			int u = q.front(); q.pop(); in_queue[u] = 0;
			for (auto it : G[u]) {
				edge &E = e[it];
				if (E.rem() && dist[E.v] > dist[u] + E.cost + 1e-9) { // ojo EPS
					dist[E.v] = dist[u] + E.cost;
					pre[E.v] = it;
					cap[E.v] = min(cap[u], E.rem());
					if (!in_queue[E.v]) q.push(E.v), in_queue[E.v] = 1;
				}
			}
		}
		if (pre[t] == -1) break;
		mxFlow += cap[t];
		mnCost += cap[t] * dist[t];
		for (int v = t; v != s; v = e[pre[v]].u) {
			e[pre[v]].flow += cap[t];
			e[pre[v] ^ 1].flow -= cap[t];
		}
	}
}


int u[MAXN], v[MAXN];
ll cst[MAXN], D, K;

ll mat[85][85];
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n, m;
	cin >> n >> m;

	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			cin >> mat[i][j];
		}
	}

	nodes = n * m + 1;
	int s = 0;
	int t = nodes;
	nodes++;
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if ((i + j) % 2 == 0)
			{
				if (i > 0)
				{
					if (mat[i][j] == mat[i - 1][j])
						addEdge(i * m + j + 1, (i - 1) * m + j + 1, 1, 0);
					else
						addEdge(i * m + j + 1, (i - 1) * m + j + 1, 1, 1);
				}

				if (j < m - 1)
				{
					if (mat[i][j] == mat[i][j + 1])
						addEdge(i * m + j + 1, i * m + j + 2, 1, 0);
					else
						addEdge(i * m + j + 1, i * m + j + 2, 1, 1);
				}

				if (i < n - 1)
				{
					if (mat[i][j] == mat[i + 1][j])
						addEdge(i * m + j + 1, (i + 1) * m + j + 1, 1, 0);
					else
						addEdge(i * m + j + 1, (i + 1) * m + j + 1, 1, 1);
				}

				if (j > 0)
				{
					if (mat[i][j] == mat[i][j - 1])
						addEdge(i * m + j + 1, i * m + j, 1, 0);
					else
						addEdge(i * m + j + 1, i * m + j, 1, 1);
				}

				addEdge(s, i * m + j + 1, 1, 0);
			}
			else
				addEdge(i * m + j + 1, t, 1, 0);
		}
	}

	flow(s, t);

	cout << mnCost << endl;

	return 0;
}

//======================================================================================================================