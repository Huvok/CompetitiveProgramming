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
// dp[i][s] is the expected number of people with score s after i games. In the end, the answer is 1 + dp[n][s] for
// every s less than the total score of the character. dp[i][s] is equal to dp[i - 1][k] for every k strictly less than
// the score on round i, divided by m - 1, since it means that one of the dp[i - 1][k] persons scored t points,
// getting to dp[i][k + t = s], and the expected value of people of score k doing that is dp[i - 1][k] / (m - 1).
// Note that you need to skip the k such that k + t = s and t is the score of the character in that round.

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
double dp[105][100005], sdp[105][100005];
ll score[1005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, m;
	cin >> n >> m;

	if (m == 1) {
		cout << 1. << endl;
		return 0;
	}

	ll sum = 0;
	FOR(i, 0, n) {
		cin >> score[i];
		sum += score[i];
	}

	mem(dp, 0.);
	dp[0][0] = m - 1;
	sdp[0][0] = m - 1;
	FOR(i, 1, n * m + 1)
		sdp[0][i] = sdp[0][i - 1];

	FOR(i, 1, n + 1) {
		FOR(j, 1, n * m + 1) {
			dp[i][j] += sdp[i - 1][j - 1];
			
			if (j - m - 1 >= 0)
				dp[i][j] -= sdp[i - 1][j - m - 1];
			
			if (j >= score[i - 1])
				dp[i][j] -= (dp[i - 1][j - score[i - 1]]);
			dp[i][j] /= (m - 1);
			sdp[i][j] = sdp[i][j - 1] + dp[i][j];
		}
	}

	double ans = 1.;
	FOR(i, 1, sum)
		ans += dp[n][i];

	cout << fixed << setprecision(10) << ans << endl;
	
	return 0;
}