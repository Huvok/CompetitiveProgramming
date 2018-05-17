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
//                                          //IDEA: If n is odd it is impossible (trivial to prove). Root the tree at
//                                          //      1 and lets say it has 3 children trees, two with even amount of
//                                          //      nodes and one with odd amount, so you can pair the root with
//                                          //      its odd child and disconnect the other ones. Repeat this greedily,
//                                          //      disconnecting all even childs, and answer is this amount. This is
//                                          //      the same if you have more than one odd child, you just leave the
//                                          //      root connected to it.

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
vi adj[100005];
ll vis[100005];
ll rem = 0;

ll dfs(ll i)
{
	vis[i] = true;

	ll cnt = 1;

	FOR(j, 0, sz(adj[i]))
	{
		ll v = adj[i][j];

		if (!vis[v])
		{
			ll x = dfs(v);
			cnt += x;
			if (x % 2 == 0)
				rem++;
		}
	}

	return cnt;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n;
	cin >> n;
	FOR(i, 0, n - 1)
	{
		ll s, d;
		cin >> s >> d;
		adj[s].pb(d);
		adj[d].pb(s);
	}

	if (n & 1)
		cout << -1 << endl;
	else
	{
		dfs(1);

		cout << rem << endl;
	}

	return 0;
}

//======================================================================================================================