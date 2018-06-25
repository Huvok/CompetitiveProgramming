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
//                                          //IDEA: Instead of removing edges, lets solve it backwards and keep adding
//                                          //      them. Lets use Disjoint Set Union Find, first add those edges that
//                                          //      will never me removed and answer queries backwards. If it is a Q,
//                                          //      add ans to a vector, if it is an R, substract from ans the size of
//                                          //      the set of each node times n - size of set of the node, i.e. the
//                                          //      number of ways of chosing a valid non connected pair, then add
//                                          //      the product of the sets of both nodes (inclusion-exclusion), then
//                                          //      unite the sets, then add the size of the new set times n - sz(new).

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
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, VA_ARGS), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 100000000000000000

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

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
				sizes[x] += sizes[y];
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

bool bads[20005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll t;
	cin >> t;

	while (t--)
	{
		ll n;
		cin >> n;
		vii a;

		FOR(i, 0, n - 1)
		{
			ll s, d;
			cin >> s >> d;
			a.pb(ii(s, d));
		}

		ll q;
		cin >> q;
		vi queries;
		FOR(i, 0, q)
		{
			char c;
			cin >> c;
			if (c == 'Q')
			{
				queries.pb(-1);
			}
			else
			{
				ll x;
				cin >> x;
				x--;
				queries.pb(x);
				bads[x] = true;
			}
		}

		reverse(all(queries));
		UnionFind uf(n + 1);
		ll ans = n * (n - 1) / 2;
		FOR(i, 0, n - 1)
		{
			if (bads[i] == false)
			{
				ll u = a[i].first;
				ll v = a[i].second;
				ans -= (uf.sizes[uf.findSet(u)] * (n - uf.sizes[uf.findSet(u)]));
				ans -= (uf.sizes[uf.findSet(v)] * (n - uf.sizes[uf.findSet(v)]));
				ans += (uf.sizes[uf.findSet(u)] * uf.sizes[uf.findSet(v)]);
				uf.unionSet(u, v);
				ans += (uf.sizes[uf.findSet(u)] * (n - uf.sizes[uf.findSet(u)]));
			}
		}

		vi vans;
		FOR(i, 0, sz(queries))
		{
			if (queries[i] == -1)
				vans.pb(ans);
			else
			{
				ll u = a[queries[i]].first;
				ll v = a[queries[i]].second;
				ans -= (uf.sizes[uf.findSet(u)] * (n - uf.sizes[uf.findSet(u)]));
				ans -= (uf.sizes[uf.findSet(v)] * (n - uf.sizes[uf.findSet(v)]));
				ans += (uf.sizes[uf.findSet(u)] * uf.sizes[uf.findSet(v)]);
				uf.unionSet(u, v);
				ans += (uf.sizes[uf.findSet(u)] * (n - uf.sizes[uf.findSet(u)]));
			}
		}

		FOR(i, 0, sz(vans))
			cout << vans[sz(vans) - 1 - i] << endl;
		cout << endl;
	}

	return 0;
}

//======================================================================================================================