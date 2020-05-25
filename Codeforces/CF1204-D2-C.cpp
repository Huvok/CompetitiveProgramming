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
ll adj[105][105];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;
	FOR(i, 0, n) {
		string str;
		cin >> str;
		FOR(j, 0, n) {
			if (str[j] == '1')
				adj[i + 1][j + 1] = 1;
			else
				adj[i + 1][j + 1] = oo;

			if (i == j)
				adj[i + 1][j + 1] = 0;
		}
	}

	FOR (k, 1, n + 1) {
		FOR(i, 1, n + 1) {
			FOR(j, 1, n + 1) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	ll hue;
	cin >> hue;
	vi p;
	FOR(i, 0, hue) {
		ll x;
		cin >> x;
		p.pb(x);
	}

	vi ans;
	ans.pb(p[0]);
	FOR(i, 2, sz(p)) {
		if (adj[ans[ans.size() - 1]][p[i]] < adj[ans[ans.size() - 1]][p[i - 1]] + adj[p[i - 1]][p[i]])
			ans.pb(p[i - 1]);
	}

	ans.pb(p[p.size() - 1]);
	cout << ans.size() << endl;
	FOR(i, 0, ans.size())
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}