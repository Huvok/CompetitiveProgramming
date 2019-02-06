#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <queue>
#include <string.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

vii adj[100005];
ll mini = 1e15;
ll s, d, a, b, w;
ll v, e;

class UnionFind
{
private:
	vi p, rank;

public:
	UnionFind(ll N)
	{
		rank.assign(N, 0);
		p.assign(N, 0);

		for (ll i = 0; i < N; ++i)
		{
			p[i] = i;
		}
	}

	ll findSet(ll i)
	{
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(ll i, ll j)
	{
		return findSet(i) == findSet(j);
	}

	void unionSet(ll i, ll j)
	{
		if (!isSameSet(i, j))
		{
			ll x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y])
			{
				p[y] = x;
			}
			else
			{
				p[x] = y;

				if (rank[x] == rank[y])
				{
					rank[y]++;
				}
			}
		}
	}
};

ll dist[100005];

void dijkstra(ll intSrc)
{
	priority_queue<ii, vii, greater<ii>> pq;
	FOR(intI, 1, v + 1) dist[intI] = 1e15;
	pq.push(mp(0, intSrc));
	dist[intSrc] = 0;

	while (!pq.empty())
	{
		ll u = pq.top().second;
		pq.pop();

		FOR(intI, 0, adj[u].size())
		{
			ll v = adj[u][intI].first;
			ll w = adj[u][intI].second;

			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push(mp(dist[v], v));
			}
		}
	}
}

bool cmp(pair<ll, ii> a, pair<ll, ii> b)
{
	return a.first > b.first;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> v >> e;

	cin >> s >> d;
	vector<pair<ll, ii>> edges;
	FOR(i, 0, e)
	{
		cin >> a >> b >> w;
		adj[a].pb(mp(b, w));
		adj[b].pb(mp(a, w));
		edges.pb(mp(w, mp(a, b)));
	}

	sort(all(edges), cmp);

	UnionFind uf(v + 1);
	ll idx = 0;
	while (!uf.isSameSet(s, d))
	{
		mini = edges[idx].first;
		uf.unionSet(edges[idx].second.first, edges[idx].second.second);
		idx++;
	}

	mini *= 2;
	FOR(i, 0, v + 1)
	{
		FOR(j, 0, adj[i].size())
		{
			adj[i][j].second = max(0LL, mini - adj[i][j].second);
		}
	}

	dijkstra(s);
	if (s == d)
		mini = 0;
	cout << mini / 2 << " " << dist[d] << '\n';

	return 0;
}
