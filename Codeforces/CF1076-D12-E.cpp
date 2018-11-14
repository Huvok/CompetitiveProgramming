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
// Maintain for each query which node will give the amount and on wich level this effect will end, then do a dfs
// and when reaching node u, iterate over all its queries and sum those values to the acummulated score, then
// add to another structure the level when this effect will end. After that, iterate over all the ending effects
// on the current level. Just before going up in the recursion, eliminate the effect on the "ending effects" structure by
// reiterating over it.

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
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ii, ll>> viii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
vi adj[300005];
map<ll, ll> levels[300005];
vii bads[300005];
vi goods[300005];
map<ll, ll> curBad;
ll levelOf[300005];

void dfs(ll i, ll level, ll p) {
	levelOf[i] = level;
	FOR(j, 0, sz(adj[i])) {
		ll v = adj[i][j];
		if (v != p) {
			dfs(v, level + 1, i);
		}
	}
}

ll ans[300005];
void getAns(ll i, ll level, ll p, ll cum) {
	for (auto it : goods[i])
		cum += it;
	for (auto it : bads[i]) {
		curBad[it.first] += it.second;
	}

	if (curBad.find(level) != curBad.end())
		cum -= curBad[level];
	ans[i] = cum;
	FOR(j, 0, sz(adj[i])) {
		ll v = adj[i][j];
		if (v != p) {
			getAns(v, level + 1, i, cum);
		}
	}
	for (auto it : bads[i]) {
		curBad[it.first] -= it.second;
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	
	ll n;
	cin >> n;
	FOR(i, 0, n - 1) {
		ll x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1, 1, -1);

	ll m;
	cin >> m;
	FOR(i, 0, m) {
		ll v, d, x;
		cin >> v >> d >> x;
		ll limit = min(n, levelOf[v] + d);
		levels[levelOf[v]][v] += x;
		goods[v].pb(x);
		bads[v].pb(ii(limit + 1, x));
	}

	getAns(1, 1, -1, 0);
	FOR(i, 1, n + 1)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}