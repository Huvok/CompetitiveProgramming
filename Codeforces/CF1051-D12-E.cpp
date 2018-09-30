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
// dp[i] is the answer for the suffix from i to n of the string a. The answer would be the sum of dp from L to R, and L is
//      the first position where the string from i to L is valid (>= l) and R is the opposite for r. To get L, we get
//      the substring from i of size l and check if it is greater than l using the z function, and the same for r.

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
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, VA_ARGS), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 998244353

//----------------------------------------------------------------------------------------------------------------------
ll n, dp[1000005], sdp[1000005];

vi zf(string s) {
	ll n = sz(s);
	vi z(n);
	for (ll i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);

		while (i + z[i] < n &&
			s[z[i]] == s[i + z[i]])
			z[i]++;

		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}

	return z;
}

string s, l, r;
char cmp(vi &zf, string &t, ll pos) {
	ll len = sz(t);
	if (sz(s) - pos < len)
		return '<';

	ll x = zf[len + 1 + pos];
	if (x == len)
		return '=';
	else if (s[pos + x] < t[x])
		return '<';
	else
		return '>';
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;

	cin >> s >> l >> r;
	n = sz(s);
	vi zl = zf(l + "#" + s);
	vi zr = zf(r + "#" + s);

	sdp[n] = dp[n] = 1;
	ROF(i, n - 1, 0) {
		if (s[i] == '0') {
			if (l == "0")
				dp[i] = dp[i + 1];
			else
				dp[i] = 0;
			sdp[i] = (dp[i] + sdp[i + 1]) % MOD;
		} else {
			ll L = i + sz(l);
			char cl = cmp(zl, l, i);
			if (cl == '<')
				L++;

			ll R = i + sz(r);
			char cr = cmp(zr, r, i);
			if (cr == '>')
				R--;

			ll cur = 0;
			if (L <= R && L <= n) {
				R = min(R, n);
				cur = sdp[L];
				if (R != n)
					cur = (cur - sdp[R + 1] + MOD) % MOD;
			}

			dp[i] = cur;
			sdp[i] = (dp[i] + sdp[i + 1]) % MOD;
		}
	}

	cout << dp[0] << endl;

	return 0;
}

//======================================================================================================================