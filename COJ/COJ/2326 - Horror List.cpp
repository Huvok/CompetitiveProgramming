﻿#include <cmath>
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

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
vii adj[1005];
ll dist[1005];
ll n, h, l;

void dijkstra(ll intSrc)
{
	priority_queue<ii, vii, greater<ii>> pq;
	FOR(intI, 0, n + 1) dist[intI] = INT_MAX;
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

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;
	vi bads;
	cin >> n >> h >> l;
	FOR(i, 0, h)
	{
		ll x;
		cin >> x;
		bads.pb(x);
	}

	ll s, d;
	FOR(i, 0, l)
	{
		cin >> s >> d;
		adj[s].pb(mp(d, 1));
		adj[d].pb(mp(s, 1));
	}

	ll root = n;
	FOR(i, 0, sz(bads))
	{
		adj[root].pb(mp(bads[i], 1));
		adj[bads[i]].pb(mp(root, 1));
	}

	dijkstra(root);
	ll champ = 0, idx = 0;
	FOR(i, 0, n)
	{
		if (dist[i] > champ)
		{
			champ = dist[i];
			idx = i;
		}
	}

	cout << idx << endl;

	return 0;
}

//======================================================================================================================