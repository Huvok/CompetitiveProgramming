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
// The best cases will always be when two colors turn to one side and one to the other. Try ignoring each color and
// consider the other two. To have the graph work, you need to destroy all edges between these two colors, and the
// constrains make this two color graph bipartite. In other words, you are asked to destroy the minimum amount of
// nodes, such that all edges are destroyed. This is the minimum vertex cover (by korig's theorem, max flow in bip. graph).

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
class GearsDiv1 {
public:
#define MAX 1001
#define NIL 0
#define INF (1<<28)

	vector< int > G[MAX];
	int n, m, match[MAX], dist[MAX];

	bool bfs() {
		int i, u, v, len;
		queue< int > Q;
		for (i = 1; i <= n; i++) {
			if (match[i] == NIL) {
				dist[i] = 0;
				Q.push(i);
			}
			else dist[i] = INF;
		}
		dist[NIL] = INF;
		while (!Q.empty()) {
			u = Q.front(); Q.pop();
			if (u != NIL) {
				len = G[u].size();
				for (i = 0; i < len; i++) {
					v = G[u][i];
					if (dist[match[v]] == INF) {
						dist[match[v]] = dist[u] + 1;
						Q.push(match[v]);
					}
				}
			}
		}
		return (dist[NIL] != INF);
	}

	bool dfs(int u) {
		int i, v, len;
		if (u != NIL) {
			len = G[u].size();
			for (i = 0; i < len; i++) {
				v = G[u][i];
				if (dist[match[v]] == dist[u] + 1) {
					if (dfs(match[v])) {
						match[v] = u;
						match[u] = v;
						return true;
					}
				}
			}
			dist[u] = INF;
			return false;
		}
		return true;
	}

	int hopcroft_karp() {
		int matching = 0, i;
		mem(match, 0);
		mem(dist, 0);
		while (bfs())
			for (i = 1; i <= n; i++)
				if (match[i] == NIL && dfs(i))
					matching++;
		return matching;
	}

	int getmin(string color, vector<string> graph) {
		vector<int> v[3];
		FOR(i, 0, sz(color)) {
			if (color[i] == 'R')
				v[0].pb(i);
			else if (color[i] == 'G')
				v[1].pb(i);
			else
				v[2].pb(i);
		}
		
		int ans = oo;
		FOR(i, 0, 3) {
			int a = (i ? 0 : 1);
			int b = (a ? 2 : (i == 2 ? 1 : 2));

			FOR(i, 0, 105)
				G[i].clear();

			FOR(j, 0, sz(v[a])) {
				FOR(k, 0, sz(v[b])) {
					if (graph[v[a][j]][v[b][k]] == 'Y') {
						G[j + 1].pb(k + sz(v[a]) + 1);
						G[k + sz(v[a]) + 1].pb(j + 1);
					}
				}
			}

			n = sz(v[a]);
			m = sz(v[b]);
			ans = min(ans, hopcroft_karp());
		}

		return ans;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	GearsDiv1 g;
	vector<string> hue = { "NYNN","YNYN","NYNY","NNYN" };
	cout << g.getmin("RGBR", hue) << endl;
	
	return 0;
}

//======================================================================================================================