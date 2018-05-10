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
//                                          //IDEA: You can build a graph between matrices dimensions, for example:
//                                          //      a matrix 4x6 means adding an edge from the node 4 to the node 6,
//                                          //      meaning that your dimension "changes" from 4 to 6. Lets have two
//                                          //      matrices axb and bxc, the graph would be a->b->c, so if we
//                                          //      start at a and end at c, we have a matrix of axc dimensions, so the
//                                          //      edges represent the lost of our rightmost dimension in the
//                                          //      multiplication chain in order to add another matrix. We can only
//                                          //      multiply every matrix if we have an eulerian path and this is only
//                                          //      possible if we have at most two nodes of degree -1 or 1. A node
//                                          //      of degree 1 (incoming edges: -1, outgoing: +1) means that we have
//                                          //      to start at that node, so the first dimension would be that node
//                                          //      and we can end the path on any other node so we would choose the
//                                          //      biggest one. It is impossible to have only one node of odd degree
//                                          //      so if we have one of each, we should start and end on them. If we
//                                          //      have only nodes of degree 0, we can choose the biggest one^2 since
//                                          //      the graph is an eulerian cycle. Remember to check of many
//                                          //      components.

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
class OrderDoesMatter
{
public:
	vi adj[1005];
	bool vis[1005];
	ll degrees[1005];
	ll roots[1005];

	void dfs(ll i)
	{
		vis[i] = true;
		degrees[i] += sz(adj[i]);
		FOR(j, 0, sz(adj[i]))
		{
			ll v = adj[i][j];
			degrees[v]--;
			if (!vis[v])
				dfs(v);
		}
	}

	int getOrder(vector <int> N, vector <int> M)
	{
		mem(vis, false);
		mem(degrees, 0);
		mem(roots, 0);
		int champ = 0;
		FOR(i, 0, sz(N))
		{
			adj[N[i]].pb(M[i]);
			if (N[i] != M[i])
				roots[M[i]] = 1;
			champ = max(champ, N[i]);
			champ = max(champ, M[i]);
		}

		ll comps = 0;
		FOR(i, 0, 1005)
		{
			if (roots[i] == 0 &&
				adj[i].size() > 0)
			{
				if (!vis[i])
					dfs(i);
				comps++;
			}
		}

		FOR(i, 0, 1005)
		{
			if (adj[i].size() > 0)
			{
				if (!vis[i])
				{
					dfs(i);
					comps++;
				}
			}
		}

		if (comps != 1)
			return -1;

		vi odds;
		FOR(i, 0, 1005)
		{
			if (degrees[i] == 1 ||
				degrees[i] == -1)
				odds.pb(i);
			else if (degrees[i] != 0)
				return -1;
		}

		if (sz(odds) == 0)
			return champ * champ;
		else if (sz(odds) == 1)
		{
			champ = 0;
			FOR(i, 0, 1005)
			{
				if (odds[0] != i &&
					adj[i].size() != 0)
				{
					champ = i;
				}
			}

			return champ * odds[0];
		}
		else if (sz(odds) == 2)
			return odds[0] * odds[1];
		else
			return -1;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	vector<int> a = { 342, 896, 734, 460, 896, 610, 533, 442, 442, 610, 610, 896, 40, 610, 342, 734, 896, 610, 533, 460 };
	vector<int> b = { 342, 442, 460, 610, 896, 896, 610, 533, 342, 533, 896, 896, 610, 610, 40, 734, 610, 460, 442, 896 };

	OrderDoesMatter o;
	cout << o.getOrder(a, b) << endl;

	return 0;
}

//======================================================================================================================