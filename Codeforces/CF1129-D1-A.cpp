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
ll best[5005];
ll cnt[5005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, m;
	cin >> n >> m;

	FOR(i, 0, n) {
		best[i] = oo;
	}
	FOR(i, 0, m) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		cnt[a]++;
		ll len;
		if (b < a)
			len = n - a + b;
		else
			len = b - a;

		best[a] = min(best[a], len);
	}

	FOR(i, 0, n) {
		ll ans = 0;
		FOR(j, i, n) {
			if (cnt[j]) {
				ans = max(ans, (j - i) + n * (cnt[j] - 1) + best[j]);
			}
		}

		FOR(j, 0, i) {
			if (cnt[j]) {
				ans = max(ans, (n - i + j) + n * (cnt[j] - 1) + best[j]);
			}
		}

		cout << ans << " ";
	}
	
	return 0;
}