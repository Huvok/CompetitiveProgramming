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

vector<pair<ll, ii>> edges;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll n, m;
	while (true)
	{
		cin >> n >> m;
		if (n + m == 0)
			break;

		ll s, d, w;

		edges.clear();
		FOR(i, 0, m)
		{
			cin >> s >> d >> w;
			edges.pb(mp(-w, mp(s, d)));
		}

		sort(all(edges));
		UnionFind uf(n + 1);
		ll champ = 1e18;
		FOR(i, 0, sz(edges))
		{
			if (!uf.isSameSet(edges[i].second.first, edges[i].second.second))
			{
				uf.unionSet(edges[i].second.first, edges[i].second.second);
				champ = min(champ, edges[i].first * -1);
			}
		}

		bool can = true;
		FOR(i, 1, n)
		{
			if (!uf.isSameSet(1, i))
			{
				cout << "IMPOSSIBLE" << endl;
				can = false;
				break;
			}
		}

		if (can)
			cout << champ << endl;
	}

	return 0;
}