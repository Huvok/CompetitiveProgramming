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
// Generate the preorder visit order so that every query for a subtree is now a query on a range. Now traverse again
// in preorder and when you visit a node v, apply every query that involve v by adding a 1 in the range of the queries,
// then count the number of nodes that are positive and finally, when exiting the node, revert all the queries.

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
vi queries[100005];
ii rangeOf[100005];
ll ans[100005];
bool vis[100005];

#define maxN 200005
ll segmentTree[3 * maxN], deltas[3 * maxN], ss;

void precalcSegmentTree()
{
	memset(deltas, 0, sizeof(deltas));
	mem(segmentTree, 0);
}

void query3(ll n, ll l, ll r, ll d, ll x)
{
	if (l > r)
		return;

	if (!l && r == d - 1)
	{
		deltas[n] += x;
	}
	else {
		query3(n << 1, l, min(d / 2 - 1, r), d / 2, x);
		query3(2 * n + 1, max(0LL, l - d / 2), r - (d / 2), d / 2, x);
	}

	if (deltas[n] > 0)
		segmentTree[n] = d;
	else {
		if (n >= ss)
			segmentTree[n] = 0;
		else
			segmentTree[n] = segmentTree[n << 1] + segmentTree[n << 1 | 1];
	}
}

ll cnt = 0;
void dfs(ll i) {
	vis[i] = true;
	rangeOf[i].first = cnt;
	cnt++;

	FOR(j, 0, sz(adj[i])) {
		ll v = adj[i][j];
		if (!vis[v])
			dfs(v);
	}

	rangeOf[i].second = cnt;
	cnt++;
}

ll n, q;
void solve(ll i) {
	vis[i] = true;
	FOR(j, 0, sz(queries[i])) {
		ll v = queries[i][j];
		query3(1, rangeOf[i].first, rangeOf[i].second, ss, 1);
		query3(1, rangeOf[v].first, rangeOf[v].second, ss, 1);
	}

	ans[i] = segmentTree[1] / 2;
	if (ans[i] > 0)
		ans[i]--;
	FOR(j, 0, sz(adj[i])) {
		ll v = adj[i][j];
		if (!vis[v])
			solve(v);
	}

	FOR(j, 0, sz(queries[i])) {
		ll v = queries[i][j];
		query3(1, rangeOf[i].first, rangeOf[i].second, ss, -1);
		query3(1, rangeOf[v].first, rangeOf[v].second, ss, -1);
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	cin >> n >> q;

	FOR(i, 0, n - 1) {
		ll s, d;
		cin >> s >> d;
		adj[s].pb(d);
		adj[d].pb(s);
	}

	FOR(i, 0, q) {
		ll a, b;
		cin >> a >> b;
		queries[a].pb(b);
		queries[b].pb(a);
	}

	dfs(1);
	mem(vis, false);

	ss = 1LL << (ll)ceil(log2(2 * n));
	precalcSegmentTree();

	solve(1);

	FOR(i, 1, n + 1)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}

//======================================================================================================================