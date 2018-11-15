#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Calculate the sparse table for ancestors and LCAs. In a rangle [l, r] the only options that COULD
// modify the segment LCA are the "leftmost" and "rightmost" nodes i.e. the first you touch in an euler tour and
// the last one. Maintian a segment tree with the euler tour marks and query for min and max, and then
// if those nodes are a and b, test the new LCA segments of LCA([l, a - 1], [a + 1, r]) and the same
// for b, and take the best answer.

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
vi adj[200005];
ll n, l;
ll sparse[200005][20];
ll ancestor[200005];
ll L[200005];
ll tin[200005];
ll timer = 0;
ll sparseLCA[200005][20];

ll LCA(ll a, ll b) {
	if (L[a] < L[b])
		swap(a, b);
	
	ROF(i, l, 0) {
		if (L[a] - (1LL << i) >= L[b])
			a = sparse[a][i];
	}

	if (a == b)
		return b;
	
	ROF(i, l, 0) {
		if (sparse[a][i] != sparse[b][i]) {
			a = sparse[a][i];
			b = sparse[b][i];
		}
	}

	return ancestor[a];
}

void precalcSparse() {
	mem(sparse, -1);
	FOR(i, 1, n + 1) {
		sparse[i][0] = ancestor[i];
		sparseLCA[i][0] = i;
	}

	FOR(j, 1, l + 1) {
		FOR(i, 1, n + 1) {
			sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
		}
	}

	FOR(j, 1, l + 1) {
		FOR(i, 1, n + 1) {
			sparseLCA[i][j] = LCA(sparseLCA[i][j - 1], sparseLCA[i + (1LL << (j - 1))][j - 1]);
		}
	}
}

void dfs(ll u, ll level, ll p) {
	L[u] = level;
	ancestor[u] = p;
	tin[u] = ++timer;
	for (ll v : adj[u]) {
		if (v != p)
			dfs(v, level + 1, u);
	}
}

#define maxN 100005
pair<ii, ii> segmentTree[3 * maxN];
ll ss;

void precalcSegmentTree() {
	FOR(i, 0, n) {
		segmentTree[ss + i] = mp(ii(tin[i + 1], i + 1), ii(tin[i + 1], i + 1));
	}

	for (ll i = ss - 1; i; i--) {
		if (segmentTree[i << 1].first.first < segmentTree[i << 1 | 1].first.first)
			segmentTree[i].first = segmentTree[i << 1].first;
		else
			segmentTree[i].first = segmentTree[i << 1 | 1].first;
		if (segmentTree[i << 1].second.first > segmentTree[i << 1 | 1].second.first)
			segmentTree[i].second = segmentTree[i << 1].second;
		else
			segmentTree[i].second = segmentTree[i << 1 | 1].second;
	}
}

pair<ii, ii> query(ll n, ll l, ll r, ll d) 
{
	if (l > r) 
		return mp(ii(oo, 0), ii(-oo, 0));

	if (!l && 
		r == d - 1)
		return segmentTree[n];

	d /= 2;
	pair<ii, ii> ret, a, b;
	a = query(n << 1, l, min(d - 1, r), d);
	b = query(n << 1 | 1, max(0LL, l - d), r - d, d);
	if (a.first.first < b.first.first)
		ret.first = a.first;
	else
		ret.first = b.first;
	
	if (a.second.first > b.second.first)
		ret.second = a.second;
	else
		ret.second = b.second;
	return ret;
}

ll LCAquery(ll l, ll r) {
	ll lg = log2((r - l + 1));
	if (lg < 0) lg = 0;
	return LCA(sparseLCA[l][lg], sparseLCA[r - (1LL << lg) + 1][lg]);
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	
	ll q;
	cin >> n >> q;
	FOR(i, 0, n - 1) {
		ll p;
		cin >> p;
		adj[i + 2].pb(p);
		adj[p].pb(i + 2);
	}

	l = ceil(log2(n));
	dfs(1, 0, 1);
	precalcSparse();
	ss = 1LL << (ll)ceil(log2(n));
	precalcSegmentTree();

	FOR(i, 0, q) {
		ll l, r;
		cin >> l >> r;
		pair<ii, ii> ret = query(1, l - 1, r - 1, ss);
		ll ans = oo;
		ll a = oo, b = oo;
		ll who;
		if (ret.first.second != l)
			a = LCAquery(l, ret.first.second - 1);
		if (ret.first.second != r)
			b = LCAquery(ret.first.second + 1, r);
		if (a != oo && b != oo)
			a = LCA(a, b);
		if (a == oo)
			swap(a, b);
		ans = L[a];
		who = ret.first.second;

		a = oo, b = oo;
		if (ret.second.second != l)
			a = LCAquery(l, ret.second.second - 1);
		if (ret.second.second != r)
			b = LCAquery(ret.second.second + 1, r);
		if (a != oo && b != oo)
			a = LCA(a, b);
		if (a == oo)
			swap(a, b);
		if (L[a] > ans) {
			ans = L[a];
			who = ret.second.second;
		}

		cout << who << " " << ans << endl;
	}

	return 0;
}