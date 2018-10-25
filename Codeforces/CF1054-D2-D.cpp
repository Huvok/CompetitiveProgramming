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
// Minimize number of subarrays with xor 0 and substract this from n choose 2. Calculate prefix xors and forget about original
// array, since changing a[i] changes everything on the prefix array equally, and you can get every combination of values for
// the prefix array (the original p[i] or its counterpart with bits toggled). Now count the appearances of each element in p and
// the best way to change them is to part them in half, where one half is the original value and the other half is the toggled one.

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
ll dp[200005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, k;
	cin >> n >> k;

	dp[0] = 0;
	FOR(i, 1, n + 1) {
		ll x;
		cin >> x;
		dp[i] = x ^ dp[i - 1];
	}

	FOR(i, 1, n + 1)
		dp[i] = min(dp[i], dp[i] ^ ((1LL << k) - 1));
	
	map<ll, ll> m;
	FOR(i, 0, n + 1)
		m[dp[i]]++;

	ll ans = n * (n + 1) / 2;
	for (auto it : m) {
		ll mid = it.second / 2;
		ans -= mid * (mid - 1) / 2;
		if (it.second & 1)
			ans -= mid * (mid + 1) / 2;
		else
			ans -= mid * (mid - 1) / 2;
	}

	cout << ans << endl;

	return 0;
}