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

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }

const double EPS = .000000001;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
struct edge
{
	ll v, w, bs, bp;

	edge(ll V, ll W, ll BS, ll BP)
	{
		v = V;
		w = W;
		bs = BS;
		bp = BP;
	}
};

vector<edge> adj[10005];
ll v, e, b, p;

ll dist[10005];

bool dijkstra(ll t)
{
	priority_queue<ii, vii, greater<ii>> pq;
	FOR(i, 1, v + 1)
		dist[i] = 1e15;

	pq.push(mp(t, 1));
	dist[1] = t;

	while (!pq.empty())
	{
		ll u = pq.top().second;
		pq.pop();

		FOR(i, 0, sz(adj[u]))
		{
			ll v = adj[u][i].v;
			ll w = adj[u][i].w;
			ll bs = adj[u][i].bs;
			ll bp = adj[u][i].bp;

			ll time;
			time = dist[u];
			if (time < bs)
				time = (bs - time);
			else
				time = (bp - ((time - bs) % bp)) % bp;

			time += w;

			if (dist[v] > dist[u] + time)
			{
				dist[v] = dist[u] + time;
				pq.push(mp(dist[v], v));
			}
		}
	}

	return dist[v] <= p;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;
	cin >> v >> e >> b >> p;

	ll s, d, w;
	FOR(i, 0, e)
	{
		cin >> s >> d >> w;
		adj[s].pb(edge(d, w, 0, 1));
		adj[d].pb(edge(s, w, 0, 1));
	}

	ll t, r, c1, c2;
	FOR(i, 0, b)
	{
		cin >> s >> t >> r;
		cin >> c1;
		FOR(j, 1, r)
		{
			cin >> c2;
			adj[c1].pb(edge(c2, 1, s + j - 1, t));
			c1 = c2;
		}
	}

	if (dijkstra(0))
	{
		ll l = 0, r = p, m;
		while (l < r)
		{
			m = ((r - l) >> 1) + l + 1;

			if (dijkstra(m))
				l = m;
			else
				r = m - 1;
		}

		cout << l << endl;
	}
	else
		cout << "sleep at the UCf" << endl;
	
	return 0;
}

//======================================================================================================================