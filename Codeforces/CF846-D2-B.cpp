#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Try to have every task done, from 0 to n, and if you have time left, greedely take the
// subtasks that take the least time.

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
ll a[50];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, k, m;
	cin >> n >> k >> m;
	ll sum = 0;
	FOR(i, 0, k) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + k);
	ll ans = 0;
	FOR(i, 0, n + 1) {
		if (sum * i <= m) {
			ll points = i * k + i;
			ll left = m - sum * i;
			FOR(j, 0, k) {
				FOR(l, i, n) {
					if (left - a[j] < 0)
						break;
					points++;
					left -= a[j];
				}
			}

			ans = max(ans, points);
		}
	}

	cout << ans << endl;

	return 0;
}