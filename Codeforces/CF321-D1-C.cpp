#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// If you find the centroid of a tree, and assign it A, then all its children can't contain A. You can repeat the
// process for each of them and in the worst case you will divide the tree in two equal parts, achieving a height of
// logs(N).

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
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
vi adj[100005];
ll ans[100005];
vi cmp;
ll D[100005];
ll cnt[100005];

void dfs(ll u, ll p) {
	cmp.pb(u);
	cnt[u] = 1;
	FOR(i, 0, sz(adj[u])) {
		ll v = adj[u][i];
		if (v == p) continue;
		if (D[v]) continue;
		dfs(v, u);
		cnt[u] += cnt[v];
	}
}

void build(ll u, ll cur) {
	cmp.clear();
	dfs(u, -1);
	while (cnt[u] > sz(cmp) / 2 + 1) {
		ll id = -1;
		ll mx = -1;
		FOR(i, 0, sz(adj[u])) {
			ll v = adj[u][i];
			if (D[v]) continue;
			if (cnt[v] > cnt[u]) continue;
			if (cnt[v] > mx) {
				mx = cnt[v];
				id = v;
			}
		}

		if (mx <= sz(cmp) / 2)
			break;
		u = id;
	}

	ans[u] = cur;
	D[u] = 1;
	FOR(i, 0, sz(adj[u])) {
		ll v = adj[u][i];
		if (D[v]) continue;
		build(v, cur + 1);
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;
	FOR(i, 0, n - 1) {
		ll s, d;
		cin >> s >> d;
		s--; d--;
		adj[s].pb(d);
		adj[d].pb(s);
	}

	build(0, 0);
	FOR(i, 0, n)
		cout << (char)(ans[i] + 'A') << " ";
	cout << endl;

	return 0;
}

