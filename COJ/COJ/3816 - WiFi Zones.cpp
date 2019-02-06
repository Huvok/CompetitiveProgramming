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

pair<double, double> arr[105];
vector<pair<double, ii>> edges;

double dist(ll i, ll j)
{
	double x = abs(arr[i].first - arr[j].first);
	double y = abs(arr[i].second - arr[j].second);
	return sqrt(x * x + y * y);
}

int main()
{
	ll n;

	cin >> n;

	double x, y;
	FOR(i, 0, n)
	{
		cin >> x >> y;
		arr[i] = mp(x, y);
	}

	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			if (i == j)
				continue;
			edges.pb(mp(dist(i, j), mp(i, j)));
		}
	}

	sort(all(edges));

	double ret = 0;
	UnionFind uf(n);
	FOR(i, 0, (ll)edges.size())
	{
		pair<double, ii> front = edges[i];
		if (!uf.isSameSet(front.second.first, front.second.second))
		{
			ret += front.first;
			uf.unionSet(front.second.first, front.second.second);
		}
	}

	cout << fixed << setprecision(2) << ret << endl;

	return 0;
}