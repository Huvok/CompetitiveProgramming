#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// dp[i][j] means the best answer from the ith character and taking j characters from there into consideration.
// To calculate it, you must take the minimum from dp[i][k] + dp[i + k][j - k], i.e. part the segment
// into two already calculated parts. The only thing is that there could be a cycle in string(i, i + j - 1),
// so check it naively (for every k, where k is the period and k should divide j) and if there is a cycle you
// must also take the possible minimum of dp[i][k] + cntDigits(j / k) + 2, i.e. if the period is k starting
// from i, take that answer and add the number of digits of the repetitions and the two parenthesis.

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
ll dp[205][205];
string str;

ll cntDigits(ll x) {
	ll ret = 0;
	while (x > 0) {
		ret++;
		x /= 10;
	}

	return ret;
}

bool cycle(ll i, ll j, ll p) {
	ll len = (j - i + 1) / p;
	FOR(l, 0, p) {
		FOR(hue, 1, len) {
			if (str[l + i] != str[l + hue * p + i])
				return false;
		}
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	
	ll t;
	cin >> t;
	while (t--) {
		cin >> str;

		FOR(i, 0, sz(str) + 1) {
			FOR(j, 0, sz(str) + 1) {
				dp[i][j] = oo;
			}
		}
		FOR(i, 0, sz(str)) {
			dp[i][1] = 1;
			dp[i][0] = 0;
		}
		
		FOR(j, 2, sz(str) + 1) {
			FOR(i, 0, sz(str)) {
				if (i + j > sz(str))
					break;

				FOR(k, 1, j) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[i + k][j - k]);

					if (j % k == 0 &&
						cycle(i, i + j - 1, k)) {
						dp[i][j] = min(dp[i][j], dp[i][k] + cntDigits(j / k) + 2);
					}
				}
			}
		}

		cout << dp[0][sz(str)] << endl;
	}

	return 0;
}