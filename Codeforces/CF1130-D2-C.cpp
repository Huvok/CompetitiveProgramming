#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia

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
ll mat[55][55];
ll vis[55][55];
ll n;
set<ii> a, b;

void dfs1(ll i, ll j) {
	if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || mat[i][j] == 1)
		return;

	vis[i][j] = 1;
	a.insert(ii(i, j));
	dfs1(i + 1, j);
	dfs1(i - 1, j);
	dfs1(i, j + 1);
	dfs1(i, j - 1);
}

void dfs2(ll i, ll j) {
	if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || mat[i][j] == 1)
		return;

	vis[i][j] = 1;
	b.insert(ii(i, j));
	dfs2(i + 1, j);
	dfs2(i - 1, j);
	dfs2(i, j + 1);
	dfs2(i, j - 1);
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	cin >> n;
	ll x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	FOR(i, 0, n) {
		string str;
		cin >> str;
		FOR(j, 0, n) {
			if (str[j] == '1')
				mat[i][j] = 1;
		}
	}
	x1--; x2--; y1--; y2--;
	dfs1(x1, y1);
	mem(vis, 0);
	dfs2(x2, y2);

	for (auto it : a) {
		if (b.find(it) != b.end()) {
			cout << 0 << endl;
			return 0;
		}
	}

	ll ans = oo;
	for (auto it1 : a) {
		for (auto it2 : b) {
			ll x = abs(it1.first - it2.first);
			ll y = abs(it1.second - it2.second);
			ll cand = x * x + y * y;
			ans = min(ans, cand);
		}
	}

	cout << ans << endl;

	return 0;
}