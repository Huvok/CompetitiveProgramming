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
//                                          //IDEA: dp[i][j] is the answer for the subtree on i for k = x. To calculate
//                                          //      the [j] for a node, you multiply all dp[u] where u is a son of i.
//                                          //      Just like a polynom, the degree (j) would be the number of ways of
//                                          //      choosing nodes while selecting j red nodes.

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
#define oo 100000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
vi adj[200005];
bool red[200005];

vi solve(ll i)
{
	vi ans;
	if (sz(adj[i]) > 0)
		ans = solve(adj[i][0]);

	FOR(j, 1, sz(adj[i]))
	{
		vi cur = solve(adj[i][j]);
		vi nxt(sz(ans) + sz(cur) - 1, 0);
		FOR(a, 0, sz(ans))
		{
			FOR(b, 0, sz(cur))
			{
				nxt[a + b] += (ans[a] * cur[b] % MOD);
				nxt[a + b] %= MOD;
			}
		}

		swap(nxt, ans);
	}

	if (sz(ans) == 0)
		ans.pb(1);
	if (red[i])
	{
		if (sz(ans) == 1)
			ans.pb(0);
		ans[1]++;
	}
	else
		ans[0]++;

	return ans;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n, m;
	cin >> n >> m;
	FOR(i, 0, n - 1)
	{
		ll x;
		cin >> x;
		adj[x].pb(i + 2);
	}

	FOR(i, 0, m)
	{
		ll x;
		cin >> x;
		red[x] = true;
	}

	vi ans = solve(1);
	FOR(i, 0, m + 1)
	{
		if (i >= sz(ans))
			cout << 0 << endl;
		else
			cout << ans[i] << endl;
	}

	return 0;
}

//======================================================================================================================