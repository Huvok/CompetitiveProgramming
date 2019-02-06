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
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a) - 1; i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

vii adj[1005];
bool can[1005];
vi dfs_num, dfs_low, S, visited;
ll dfsNumberCounter, numSCC;
unordered_set<ll> sets[1005];

vi comps[1005];

void tarjanSCC(ll u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.pb(u);
	visited[u] = 1;
	FOR(j, 0, sz(adj[u]))
	{
		ii v = adj[u][j];
		if (dfs_num[v.first] == -1)
			tarjanSCC(v.first);
		if (visited[v.first])
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
	}

	if (dfs_low[u] == dfs_num[u])
	{
		while (1)
		{
			ll v = S.back();
			comps[numSCC].pb(v);
			sets[numSCC].insert(v);
			S.pop_back();
			visited[v] = 0;
			if (u == v)
				break;
		}

		++numSCC;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t;
	cin >> t;

	while (t--)
	{
		ll n, m;
		cin >> n >> m;

		FOR(i, 0, n)
		{
			adj[i].clear();
			comps[i].clear();
			sets[i].clear();
		}

		mem(can, 0);

		ll s, d, w;
		FOR(i, 0, m)
		{
			cin >> s >> d >> w;
			adj[s].pb(mp(d, w));
		}

		dfs_num.assign(n, -1);
		dfs_low.assign(n, 0);
		visited.assign(n, 0);
		dfsNumberCounter = numSCC = 0;
		FOR(i, 0, n)
		{
			if (dfs_num[i] == -1)
				tarjanSCC(i);
		}

		vi negs;
		vi dist(n, 1e18);
		FOR(l, 0, numSCC)
		{
			dist[comps[l][0]] = 0;
			FOR(i, 0, sz(comps[l]) - 1)
			{
				FOR(o, 0, sz(comps[l]))
				{
					ll u = comps[l][o];
					FOR(j, 0, sz(adj[u]))
					{
						ii v = adj[u][j];
						if (sets[l].find(v.first) != sets[l].end())
						{
							dist[v.first] = min(dist[v.first], dist[u] + v.second);
						}
					}
				}
			}

			bool neg = false;
			FOR(o, 0, sz(comps[l]))
			{
				ll u = comps[l][o];
				FOR(j, 0, sz(adj[u]))
				{
					ii v = adj[u][j];
					if (sets[l].find(v.first) != sets[l].end() &&
						dist[v.first] > dist[u] + v.second)
					{
						neg = true;
						o = sz(comps[l]);
						break;
					}
				}
			}

			if (neg)
				negs.pb(l);
		}

		FOR(i, 0, sz(negs))
		{
			FOR(j, 0, sz(comps[negs[i]]))
			{
				can[comps[negs[i]][j]] = 1;
			}
		}

		FOR(i, 0, n)
			cout << can[i] << " ";
		cout << endl;
	}

	return 0;
}