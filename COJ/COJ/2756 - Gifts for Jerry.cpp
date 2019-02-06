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

typedef int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
class UnionFind
{
private:
	vi p, rank;

public:
	vi sizes;
	UnionFind(ll N)
	{
		rank.assign(N, 0);
		p.assign(N, 0);
		sizes.assign(N, 1);

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
				sizes[x] += sizes[y];;
			}
			else
			{
				p[x] = y;
				sizes[y] += sizes[x];
				if (rank[x] == rank[y])
				{
					rank[y]++;
				}
			}
		}
	}
};

//----------------------------------------------------------------------------------------------------------------------
ll ans[100005];

int main()
{
	sync;

	ll m;
	while (cin >> m)
	{
		ll s, d, t;
		vector<pair<ll, ii>> edges;
		vii queries;
		edges.reserve(100000);
		queries.reserve(100000);
		FOR(i, 0, m)
		{
			cin >> s >> d >> t;
			edges.pb(mp(t, mp(s, d)));
		}

		sort(all(edges));

		ll sum = 0;
		ll k;
		cin >> k;
		FOR(i, 0, k)
		{
			cin >> t;
			queries.pb(mp(t, i));
		}

		sort(all(queries));
		ll idx = 0;
		UnionFind uf((1LL << 15) + 1);
		FOR(i, 0, sz(queries))
		{
			ll x = queries[i].first;
			while (idx < sz(edges) &&
				x >= edges[idx].first)
			{
				if (!uf.isSameSet(edges[idx].second.first, edges[idx].second.second))
				{
					ll x = uf.sizes[uf.findSet(edges[idx].second.first)];
					ll y = uf.sizes[uf.findSet(edges[idx].second.second)];
					if (x != 1)
					{
						sum -= ((x - 1) * x) / 2;
					}

					if (y != 1)
					{
						sum -= ((y - 1) * y) / 2;
					}
					uf.unionSet(edges[idx].second.first, edges[idx].second.second);
					ll it = uf.findSet(edges[idx].second.first);
					ll cur = uf.sizes[it];
					sum += ((cur - 1) * cur) / 2;
				}

				idx++;
			}

			ans[queries[i].second] = sum;
		}

		FOR(i, 0, k)
			cout << ans[i] << endl;
	}
	
	return 0;
}

//======================================================================================================================