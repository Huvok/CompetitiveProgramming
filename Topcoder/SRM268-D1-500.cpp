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
//                                          //IDEA: The basic idea is to get an eulerian path with the minimum added
//                                          //      edges, so we need to connect the graph and have at most two odd
//                                          //      degree vertices. The handshaking lemma tells us that any non
//                                          //      directed graph will have an even number of odd degree nodes, so we
//                                          //      can count the number of odd degree nodes per component with dfs and
//                                          //      connect every component using one of their odd degree vertices in
//                                          //      a line. If there are components with no odd degree vertices, we can
//                                          //      connect it to two other components using the same edge (or, like
//                                          //      my code, just fake the situation by adding 2 odd degree vertices
//                                          //      to the component, wich would be basically the same. Then we just
//                                          //      connect every pair of odd degree vertex until there are at most two
//                                          //      left. We can proof this works by induction: we have k odd degree
//                                          //      vertices and everytime we connect two components k decreases by two
//                                          //      and it is even everytime. It doesn't matter when we connect the zero
//                                          //      odd degree vertices components since we will "create" two odd degree
//                                          //      vertices at some time and it doesn't matter what components we
//                                          //      connect as long as we use n - 1 edges where n is the component count
//                                          //      meaning that after n - 1 connections the graph must be connected,
//                                          //      if we don't do this, we risk the optimal answer. This is true for
//                                          //      k + 2 since k will always be greater than n - 1, so in the end
//                                          //      we are left again with an even k and now we can just greedily
//                                          //      connect the odd degree vertices left since the graph is already
//                                          //      connected.

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
class MaxTrip
{
public:
	vi adj[30];
	ll degrees[30];
	bool vis[30];

	void dfs(ll i)
	{
		vis[i] = true;
		degrees[i] = sz(adj[i]);

		FOR(j, 0, sz(adj[i]))
		{
			ll v = adj[i][j];

			if (!vis[v])
				dfs(v);
		}
	}

	int minBuy(string portA, string portB)
	{
		mem(vis, false);
		FOR(i, 0, 30)
			adj[i].clear();
		mem(degrees, 0);
		FOR(i, 0, sz(portA))
		{
			adj[portA[i] - 'A'].pb(portB[i] - 'A');
			adj[portB[i] - 'A'].pb(portA[i] - 'A');
		}

		vi odds;
		FOR(i, 0, sz(portA))
		{
			mem(degrees, 0);
			if (!vis[portA[i] - 'A'])
			{
				dfs(portA[i] - 'A');
				ll cnt = 0;
				FOR(i, 0, 30)
				{
					if (degrees[i] & 1)
						cnt++;
				}

				odds.pb(cnt);
			}
		}

		ll ans = 0;
		FOR(i, 0, sz(odds))
		{
			if (odds[i] == 0)
				odds[i] = 2;
		}

		FOR(i, 0, sz(odds) - 1)
		{
			odds[i]--;
			odds[i + 1]--;
			ans++;
		}

		ll left = 0;
		FOR(i, 0, sz(odds))
		{
			left += odds[i];
		}

		if (left > 0)
			left -= 2;
		ans += left / 2;

		return ans;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	MaxTrip mt;
	cout << mt.minBuy("AAX", "CBY") << endl;
	cout << mt.minBuy("AAAAA", "CBXYQ") << endl;

	return 0;
}

//======================================================================================================================