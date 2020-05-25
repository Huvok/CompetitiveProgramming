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

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
vi adj[300005];
ll op[300005];
ll dp[300005];

ll solve(ll u, ll p) {
	if (adj[u].size() == 1 &&
		adj[u][0] == p) {
		dp[u] = 1;
	}
	else if (op[u] == 1) {
		for (auto v : adj[u]) {
			if (v != p)
				dp[u] = min(solve(v, u), dp[u]);
		}
	}
	else {
		dp[u] = 0;
		for (auto v : adj[u]) {
			if (v != p)
				dp[u] += solve(v, u);
		}
	}

	return dp[u];
}

ll leaf[300005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> op[i + 1];
		dp[i + 1] = oo;
	}
	mem(leaf, true);
	ll k = n;
	FOR(i, 0, n - 1) {
		ll x;
		cin >> x;
		adj[i + 2].pb(x);
		adj[x].pb(i + 2);
		if (leaf[x]) {
			leaf[x] = false;
			k--;
		}
	}

	ll ans = solve(1, -1);
	cout << k - ans + 1 << endl;

	return 0;
}