#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Precalc sparse table, there are many cases: if both a and b are equal the answer is n,
// if they are at the same level, the answer is n - cnt[ap] - cnt[bp], where ap and bp are
// the first sons of their LCA, meaning everything except their subtrees.
// Last case is when both are on different levels. The answer is the subtree that is
// located at the middle of the path from a to b.

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define lld I64d
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ii, ll>> viii;

#define MOD 998244353

//----------------------------------------------------------------------------------------------------------------------
vi adj[200005];
ll n, l;
ll sparse[200005][30];
ll ancestor[200005];
ll L[200005];
ll cnt[200005];
ll parents[200005];
ll tin[200005], tout[200005];
ll cur = 0;

void precalcSparse() {
	mem(sparse, -1);
	FOR(i, 1, n + 1)
		sparse[i][0] = ancestor[i];
	sparse[1][0] = 1;
	FOR(j, 1, l + 1) {
		FOR(i, 1, n + 1) {
			sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
		}
	}
}

void dfs(ll u, ll level, ll p) {
	L[u] = level;
	tin[u] = cur;
	cur++;
	cnt[u] = 1;
	ancestor[u] = p;
	for (ll v : adj[u]) {
		if (v != p) {
			dfs(v, level + 1, u);
			cnt[u] += cnt[v];
		}
	}
	tout[u] = cur;
	cur++;
}

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

bool isancestor(ll a, ll l) {
	if (a == -1) return true;
	return tin[a] <= tin[l] && tout[l] <= tout[a];
}

ll go(ll a, ll l) {
	ROF(i, 29, 0) {
		if (!isancestor(sparse[a][i], l)) {
			a = sparse[a][i];
		}
	}

	return a;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	cin >> n;
	FOR(i, 0, n - 1) {
		ll a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	l = ceil(log2(n));
	dfs(1, 0, 1);
	precalcSparse();

	ll q;
	cin >> q;
	FOR(i, 0, q) {
		ll x, y;
		cin >> x >> y;

		ll l = LCA(x, y);
		if (x == y)
			cout << n << endl;
		else if (L[x] - L[l] == L[y] - L[l]) {
			x = go(x, l);
			y = go(y, l);
			cout << n - cnt[x] - cnt[y] << endl;
		}
		else {
			if (L[x] < L[y])
				swap(x, y);

			ll to = x;
			ll dst = L[x] + L[y] - 2 * L[l];
			if (dst % 2 == 1)
				cout << 0 << endl;
			else {
				dst /= 2;
				dst--;

				ROF (i, 29, 0) {
					if ((1LL << i) <= dst) {
						to = sparse[to][i];
						dst -= (1LL << i);
					}
				}

				ll m = sparse[to][0];
				cout << cnt[m] - cnt[to] << endl;
			}
		}
	}

	return 0;
}