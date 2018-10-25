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
#  define __builtin_popcountll __popcnt64
#endif

using namespace std;

//                                          //AUTHOR: Hugo Garcia
// dp[i][0] is the number of ways of having a subtree rooted at i such that it does not contain any black node,
// but every other subtree under i that is not the subtree at i has one black node. dp[i][1] is the same but for one black
// node on the subtree rooted at i. We process each child and we see than, when processing child v,
// the new dp[u][0] is dp[u][0] * dp[v][0] and dp[u][1] = dp[u][1] * dp[v][0] + dp[u][0] * dp[v][1] if we add the child v to the subtree,
// since we only want white nodes/only one black node AND we sum to dp[u][0], dp[u][0] * dp[v][1] and to dp[u][1], dp[u][1] * dp[v][1],
// meaning that we won't take child v into the subtree.

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
#define sz(x) (ll)(x).size()
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
vi adj[100005];
ll a[100005];
ll dp[100005][2];

void dfs(ll u) {
	if (a[u])
		dp[u][1] = 1;
	else
		dp[u][0] = 1;

	FOR(j, 0, sz(adj[u])) {
		ll v = adj[u][j];
		dfs(v);

		ll black = 0, white = 0;
		white += dp[u][0] * dp[v][0];
		white %= MOD;
		black += (dp[u][1] * dp[v][0]) % MOD + (dp[u][0] * dp[v][1]) % MOD;
		black %= MOD;

		white += dp[u][0] * dp[v][1];
		white %= MOD;
		black += dp[u][1] * dp[v][1];
		black %= MOD;

		dp[u][0] = white;
		dp[u][1] = black;
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;
	FOR(i, 0, n - 1) {
		ll x;
		cin >> x;
		adj[x].pb(i + 1);
	}

	FOR(i, 0, n)
		cin >> a[i];

	dfs(0);

	cout << dp[0][1] << endl;

	return 0;
}