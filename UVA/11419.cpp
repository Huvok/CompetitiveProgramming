#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// Form a bipartite graphs with edges between rows and columns of enemies. The answer is the minimum vertex cover (max.
// bipartite matching). To reconstruct the answer, all edges of matching go from right to left, and the rest
// go from left to right. Do a dfs/bfs from all left vertices that are not in the matching, and the min vertex cover
// is all unmarked left vertices and all marked right vertices.

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
#define MAX 2005
#define NIL 0
#define INF (1<<28)

vector< int > G[MAX];
int n, m, match[MAX], dist[MAX];

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
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
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

ll vis[2005];

void dfs(ll u) {
	vis[u] = true;

	FOR(j, 0, sz(G[u])) {
		ll v = G[u][j];
		if (u <= n) {
			if (match[u] != v &&
				!vis[v])
				dfs(v);
		}
		else {
			if (match[u] == v &&
				!vis[v])
				dfs(v);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	//sync;

	ll r, c, h;
	while (true) {
		cin >> r >> c >> h;
		if (r + c + h == 0) break;
		FOR(i, 0, r + c + 2)
			G[i].clear();
		n = r;
		m = c;
		mem(match, 0);
		mem(dist, 0);
		FOR(i, 0, h) {
			ll a, b;
			cin >> a >> b;
			G[a].pb(r + b);
			G[r + b].pb(a);
		}

		ll x = hopcroft_karp();
		cout << x << " ";
		mem(vis, false);
		vi roots;
		FOR(i, 1, n + 1) {
			if (match[i] == 0)
				roots.pb(i);
		}

		for (auto it : roots) {
			if (!vis[it])
				dfs(it);
		}

		vi ans;
		FOR(i, 1, n + 1) {
			if (!vis[i])
				ans.pb(i);
		}

		FOR(i, n + 1, n + m + 1) {
			if (vis[i])
				ans.pb(i);
		}

		for (auto it : ans) {
			if (it <= n)
				cout << "r" << it << " ";
			else
				cout << "c" << it - n << " ";
		}

		cout << endl;
	}


	return 0;
}

