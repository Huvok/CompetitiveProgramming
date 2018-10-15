#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <queue>
#include <bitset>
#include <sstream>
#include <set>
#include <iomanip>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <iterator>
#include <complex>

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcountll __popcnt64
#endif

using namespace std;

//                                          //AUTHOR: Hugo Garcia
// Standard dp[i][j][k], means on the ith day, you use jth algorithm and the i - 1th day you used the kth one.

//======================================================================================================================

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
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll a[4][1005];
ll dp[1005][4][4];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll q;
	cin >> q;
	while (q--) {
		ll w;
		cin >> w;

		FOR(i, 0, w)
			cin >> a[0][i] >> a[1][i] >> a[2][i] >> a[3][i];

		mem(dp, 0);
		dp[0][0][0] = a[0][0];
		dp[0][1][1] = a[1][0];
		dp[0][2][2] = a[2][0];
		dp[0][3][3] = a[3][0];

		FOR(i, 1, w) {
			FOR(j, 0, 4) {
				FOR(k, 0, 4) {
					if (j != k)
					{
						FOR(l, 0, 4) {
							if (j != l)
								dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][l]);
						}

						dp[i][j][k] += a[j][i];
					}
				}
			}
		}

		ll ans = 0;
		FOR(i, 0, 4) {
			FOR(j, 0, 4) {
				ans = max(ans, dp[w - 1][i][j]);
			}
		}

		cout << ans << endl;
	}

	return 0;
}

//======================================================================================================================