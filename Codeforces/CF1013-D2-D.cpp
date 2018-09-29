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

//                                          //AUTHOR: Hugo Garcia (Huvok)

// We'll have a bipartite graph by connecting the i row with the j column of every taken cell. Then, the answer is the
//		number of components. This is true due that if three cells are connected (like in the example) there will be 
//		four total nodes connected in the graph and we would be lacking one edge, which represents the cell we will
//      get for free. If we had only zero, one or two edges, there would be a cell disconnected.

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
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
vi adj[400005];
bool vis[400005];

void dfs(ll i)
{
	vis[i] = true;

	FOR(j, 0, adj[i].size())
	{
		ll v = adj[i][j];
		if (!vis[v])
			dfs(v);
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{	
	sync;

	ll n, m, q;
	cin >> n >> m >> q;

	FOR(i, 0, q)
	{
		ll s, d;
		cin >> s >> d;
		s--;
		d--;
		d += n;
		adj[s].pb(d);
		adj[d].pb(s);
	}

	ll ans = -1;
	FOR(i, 0, n + m)
	{
		if (!vis[i])
		{
			ans++;
			dfs(i);
		}
	}

	cout << ans << endl;

	return 0;
}

//======================================================================================================================