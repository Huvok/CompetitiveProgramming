#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Lets think recursively. For the next block, the only choices are size a or size
// a - 1, because if we take a block of size a, we are left with m - a³, if we take a - 1,
// we are left with a³ - 1 - (a - 1)³ since m must be one unit lower than a³. If we
// take a - 2 or lower, the remaining m would be smaller.

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
ii ans;

ll fastPow(ll n) {
	return n * n * n;
}

void solve(ll m, ll blocks, ll x) {
	if (m == 0) {
		ans = max(ans, ii(blocks, x));
		return;
	}

	ll cur = 1;
	while (fastPow(cur + 1) <= m) {
		cur++;
	}

	solve(m - fastPow(cur), blocks + 1, x + fastPow(cur));
	solve(fastPow(cur) - 1 - fastPow(cur - 1), blocks + 1, x + fastPow(cur - 1));
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll m;
	cin >> m;
	solve(m, 0, 0);
	cout << ans.first << " " << ans.second << endl;
	return 0;
}