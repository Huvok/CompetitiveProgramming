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
//                                          //IDEA: Build a graph connecting every boy to its girl and then connect
//                                          //      chair 1 to chair 2, 3 to 4 and so on. This will ensure two things:
//                                          //      every boy will be adjacent to its partner and every three adjacent
//                                          //      chairs will be connected. The graph will be bipartite since you can
//                                          //      put chair 1 on the left side, its partner and connected chair into
//                                          //      the left one, the connected chair of its partner into the right one
//                                          //      and so on, getting back to the connected chair of the chair number
//                                          //      1 if and only if the cycle is of even length. We can proove that
//                                          //      every cycle will be of even length (there will always be an answer)
//                                          //      by induction: Every node has a partner and a neighbor, so every
//                                          //      node is of degree 2 (unless there are only two nodes, for which
//                                          //      there is also an answer), so having k nodes where k is even will
//                                          //      generate a graph of k edges i.e. an even amount of edges and this
//                                          //      holds for k + 2 since it is also even.

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
vi adj[200005];
ll colors[200005];
ii queries[100005];
bool vis[200005];

void dfs(ll i, ll c)
{
	colors[i] = c;
	vis[i] = true;

	FOR(j, 0, sz(adj[i]))
	{
		ll v = adj[i][j];

		if (!vis[v])
		{
			if (c == 1)
				dfs(v, 2);
			else
				dfs(v, 1);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n;
	cin >> n;
	ll s, d;
	FOR(i, 0, n)
	{
		cin >> s >> d;
		adj[s].pb(d);
		adj[d].pb(s);
		queries[i] = ii(s, d);
		adj[2 * i + 1].pb(2 * i + 2);
		adj[2 * i + 2].pb(2 * i + 1);
	}

	FOR(i, 1, 2 * n + 1)
	{
		if (!vis[i])
		{
			dfs(i, 1);
		}
	}

	FOR(i, 0, n)
	{
		cout << colors[queries[i].first] << " " << colors[queries[i].second] << endl;
	}

	return 0;
}

//======================================================================================================================