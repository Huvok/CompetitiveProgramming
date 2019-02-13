#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// You can only ask for numbers of the same mass, so you need to find the maximum number of the same
// elements which can be obtained uniquely. It is a dp[i][j] which means the number of ways of choosing i objects
// with a weight of k.

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
ll NK[105][105], dp[105 * 105][105];
ll a[105], cnt[105];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	FOR(i, 0, 101) {
		FOR(j, 0, i + 1) {
			if (j == 0 || j == i) NK[i][j] = 1;
			else NK[i][j] = NK[i - 1][j - 1] + NK[i - 1][j];
		}
	}

	ll n;
	cin >> n;
	ll sum = 0, unique = 0;
	FOR(i, 1, n + 1) {
		cin >> a[i];
		cnt[a[i]]++;
		sum += a[i];
		if (cnt[a[i]] == 1)
			unique++;
	}

	if (unique <= 2)
		cout << n << endl;
	else {
		dp[0][0] = 1;
		FOR(i, 1, n + 1) {
			ROF(j, sum, a[i]) {
				FOR(k, 1, n + 1) {
					dp[j][k] += dp[j - a[i]][k - 1];
				}
			}
		}

		ll ans = 0;
		FOR(i, 1, 101) {
			if (cnt[i]) {
				FOR(j, 1, cnt[i] + 1) {
					if (dp[i * j][j] == NK[cnt[i]][j]) {
						ans = max(ans, j);
					}
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}