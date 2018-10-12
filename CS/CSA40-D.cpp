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
#  define __builtin_popcount __popcnt
#endif

using namespace std;

//                                          //AUTHOR: Hugo Garcia
// dp[i][j], you added the element i in the index j. The answer is, if i should go after i - 1, then is the answer
// of dp[i - 1][k] where k is an index BEFORE j, if i should go before i - 1, then the answer is dp[i - 1][k] where k
// is an index equal or after j (its like you are pushing i-1 to the j + 1 index).

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
ll a[2005];
ll dp[2005][2005], sdp[2005][2005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;
	FOR(i, 0, n - 1)
		cin >> a[i + 1];

	dp[1][0] = 1;
	sdp[1][0] = 1;
	FOR(i, 2, n + 1) {
		FOR(j, 0, i) {
			if (a[i - 1])
				dp[i][j] = (j ? sdp[i - 1][j - 1] : 0);
			else
				dp[i][j] = (sdp[i - 1][i - 2] - (j ? sdp[i - 1][j - 1] : 0) + MOD) % MOD;

			if (j)
				sdp[i][j] = (dp[i][j] + sdp[i][j - 1]) % MOD;
			else
				sdp[i][j] = dp[i][j];
		}
	}

	cout << sdp[n][n - 1] << endl;
	
	return 0;
}

//======================================================================================================================