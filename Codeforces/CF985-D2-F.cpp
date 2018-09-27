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
//                                          //IDEA: For every character generate a prefix sum of hashes on base 2, for 
//                                          //      example for character a, hash 101 means it appears in the 0th and
//                                          //      2nd index of the string. Now for every query you can get the hash
//                                          //      of the range by using hash[x + len - 1] - 2^len * hash[x - 1]. 
//                                          //      Get those hashes for every character in range, then sort all of
//                                          //      them (you will end up with 26 numbers for x and 26 for y), both
//                                          //      arrays must be equal, meaning that if you have [1, 6] and [1, 6], 
//                                          //      there is a character that appears in the 0th index on both queries
//                                          //      and another on the 1st and 2nd (001 and 110).

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
#define EPS 1e-9

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD1 1000000007LL
#define MOD2 1000000009LL
#define BASE 2LL

//----------------------------------------------------------------------------------------------------------------------
ll fastPow(ll x, ll n, ll m) {
	ll ret = 1;
	while (n) {
		if (n & 1)
			ret = ret * x % m;

		x = x * x % m;
		n >>= 1;
	}

	return ret;
}

ll removeAt(ll code, ll idx, ll val, ll m) {
	return (code - (val * fastPow(BASE, idx, m)) % m + m) % m;
}

ll addAt(ll code, ll idx, ll val, ll m) {
	return (code + (val * fastPow(BASE, idx, m)) % m) % m;
}

ll shiftLeft(ll code, ll m) {
	return code * BASE % m;
}

ll shiftRight(ll code, ll m, ll baseInv) {
	return code * baseInv % m;
}

ll getVal(string pat, ll m) {
	ll code = 0;
	FOR(i, 0, sz(pat)) {
		code = shiftLeft(code, m);
		code = addAt(code, 0, pat[i], m);
	}
	return code;
}

ll pots1[200005], pots2[200005], vals1[200005][26], vals2[200005][26];
ll a[26], b[26], c[26], d[26];
string str;

bool solve(ll x, ll y, ll len) {
	FOR(ch, 0, 26) {
		a[ch] = (vals1[x + len - 1][ch] - vals1[x - 1][ch] * pots1[len] % MOD1 + MOD1) % MOD1;
		b[ch] = (vals1[y + len - 1][ch] - vals1[y - 1][ch] * pots1[len] % MOD1 + MOD1) % MOD1;
		c[ch] = (vals2[x + len - 1][ch] - vals2[x - 1][ch] * pots2[len] % MOD2 + MOD2) % MOD2;
		d[ch] = (vals2[y + len - 1][ch] - vals2[y - 1][ch] * pots2[len] % MOD2 + MOD2) % MOD2;
	}

	sort(a, a + 26);
	sort(b, b + 26);
	sort(c, c + 26);
	sort(d, d + 26);
	FOR(i, 0, 26) {
		if (a[i] != b[i] ||
			c[i] != d[i])
			return false;
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------------

int main() {
	sync;

	pots1[0] = 1;
	pots2[0] = 1;
	FOR(i, 1, 200005) {
		pots1[i] = pots1[i - 1] * 2 % MOD1;
		pots2[i] = pots2[i - 1] * 2 % MOD2;
	}

	ll n, m;
	cin >> n >> m;
	cin >> str;

	FOR(c, 0, 26) {
		ll code1 = 0, code2 = 0;
		FOR(i, 1, n + 1) {
			code1 = shiftLeft(code1, MOD1);
			code1 = addAt(code1, 0, str[i - 1] == 'a' + c ? 1 : 0, MOD1);
			vals1[i][c] = code1;

			code2 = shiftLeft(code2, MOD2);
			code2 = addAt(code2, 0, str[i - 1] == 'a' + c ? 1 : 0, MOD2);
			vals2[i][c] = code2;
		}
	}

	while (m--) {
		ll x, y, len;
		cin >> x >> y >> len;
		if (solve(x, y, len))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}

//======================================================================================================================