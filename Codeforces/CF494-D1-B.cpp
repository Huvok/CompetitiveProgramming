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
// dp[i] is the amount of ways of taking one or many substrings such that the last one ends at s[i].
// Use KMP and if at s[i] does NOT end an appearance of t, dp[i] = dp[i - 1] since ending at s[i] is the same as ending
// in s[i - 1]. If s[i] is the ending of an appearance, then dp[i] is the sum of two parts. The first one is i - t.size() + 1,
// since you can just take the last t.size() characters to get a valid substring in i - t.size() + 1 ways (only
// one substring taken). The second part is the sum of the sum of dp[j], 0 <= j <= i - t.size() since it HAS to end
// at s[i], so if we fix the last t.size() characters, we are left with dp[i - t.size()] but we
// can ignore characters from there to dp[0].

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
ll p[200005];
int pp = -1, ansKMP = -1;

void kmp(string a, string b) {
	p[0] = -1;
	FOR(i, 0, a.length()) {
		while (pp >= 0 && a[pp] != a[i]) 
			pp = p[pp];
		p[i + 1] = ++pp;
	}
}

ll dp[100005], sumDp[100005], sumsumDp[100005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	string s, t;
	cin >> s >> t;

	kmp(t + "$" + s, t);
	if (sz(t) == 1 &&
		s[0] == t[0])
		dp[0] = 1;
	sumDp[0] = sumsumDp[0] = dp[0];
	FOR(i, 1, sz(s)) {
		if (i >= sz(t) - 1) {
			if (p[i + 2 + sz(t)] == sz(t)) {
				dp[i] = ((((dp[i] + i) % MOD - sz(t) + MOD) % MOD) + 2) % MOD;
				if (i >= sz(t))
					dp[i] += (sumsumDp[i - sz(t)]);
				dp[i] %= MOD;
			}
			else
				dp[i] = dp[i - 1];
		}
		else
			dp[i] = dp[i - 1];

		sumDp[i] = (sumDp[i - 1] + dp[i]) % MOD;
		sumsumDp[i] = (sumsumDp[i - 1] + sumDp[i]) % MOD;
	}

	ll ans = 0;
	FOR(i, 0, sz(s)) {
		ans += dp[i];
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}