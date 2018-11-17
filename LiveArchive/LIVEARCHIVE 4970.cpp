#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// Connect every knight to a source, every end position to a sink, and every knight with every
// end position with an edge of cap 1 and cost min movements to get that knight to that position,
// which is a O(1) formula

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
ll knightDistance(ll x1, ll y1, ll x2, ll y2) {
	ll dx = abs(x1 - x2);
	ll dy = abs(y1 - y2);
	if (dx > dy) swap(dx, dy);
	if (dx == 0 && dy == 1) return 3;
	if (dx == 2 && dy == 2) return 4;
	ll d = max((dy + 1) / 2, (dx + dy + 2) / 3);
	if (d % 2 != (dx + dy) % 2) d++;
	return d;
}


const int mxN = 400;
const ll inf = LLONG_MAX;
struct Edge
{
    ll to, cap, cost, flow, backEdge;
};
struct MCMF
{
    ll s, t, n;
    vector<Edge> g[mxN];
    MCMF(ll _s, ll _t, ll _n)
    {
        s = _s, t = _t, n = _n;
    }
    void addEdge(ll u, ll v, ll cap, ll cost)
    {
        Edge e1 = { v, cap, cost, 0, g[v].size() };
        Edge e2 = { u, 0, -cost, 0, g[u].size() };
        g[u].push_back(e1);
        g[v].push_back(e2);
    }
    pair<ll, ll> minCostMaxFlow()
    {
        ll flow = 0, cost = 0;
        vector<ll> state(n), from(n), from_edge(n), d(n);
        deque<ll> q;
        while (true)
        {
            for (ll i = 0; i < n; i++)
                state[i] = 2, d[i] = inf, from[i] = -1;
            state[s] = 1;
            q.clear();
            q.push_back(s);
            d[s] = 0;
            while (!q.empty())
            {
                ll v = q.front();
                q.pop_front();
                state[v] = 0;
                for (ll i = 0; i < (ll) g[v].size(); i++)
                {
                    Edge e = g[v][i];
                    if (e.flow >= e.cap || d[e.to] <= d[v] + e.cost)
                        continue;
                    ll to = e.to;
                    d[to] = d[v] + e.cost;
                    from[to] = v;
                    from_edge[to] = i;
                    if (state[to] == 1) continue;
                    if (!state[to] || (!q.empty() && d[q.front()] > d[to]))
                        q.push_front(to);
                    else q.push_back(to);
                    state[to] = 1;
                }
            }
            if (d[t] == inf) break;
            ll it = t, addflow = inf;
            while (it != s)
            {
                addflow = min(addflow,
                              g[from[it]][from_edge[it]].cap
                              - g[from[it]][from_edge[it]].flow);
                it = from[it];
            }
            it = t;
            while (it != s)
            {
                g[from[it]][from_edge[it]].flow += addflow;
                g[it][g[from[it]][from_edge[it]].backEdge].flow -= addflow;
                cost += g[from[it]][from_edge[it]].cost * addflow;
                it = from[it];
            }
            flow += addflow;
        }
        return {cost,flow};
    }
};


ii st[25], en[25];

//----------------------------------------------------------------------------------------------------------------------
int main() {


	ll n;
	ll cse = 1;
	while (true) {
		cin >> n;
		if (n == 0) break;

		MCMF f(0, 2 * n + 1, 2 * n + 2);

		FOR(i, 0, n) {
			cin >> st[i].first >> st[i].second;
			f.addEdge(0, i + 1, 1, 0);
		}

		FOR(i, 0, n) {
			cin >> en[i].first >> en[i].second;
			f.addEdge(n + 1 + i, 2 * n + 1, 1, 0);
		}

		FOR(i, 0, n) {
			FOR(j, 0, n) {
				ll dst = knightDistance(st[i].first, st[i].second, en[j].first, en[j].second);
				f.addEdge(i + 1, n + 1 + j, 1, dst);
			}
		}

		ii ans = f.minCostMaxFlow();
		cout << cse << ". " << ans.first << endl;
		cse++;
	}

	return 0;
}

