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
//                                          //IDEA: Do a rolling hash from the beggining (and its reverse hash) and
//                                          //      compare them at every step to see if they are equal. In the end,
//                                          //      use the last answer of this comparison to add the last n - ans 
//                                          //      characters to the initial string.

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
#define BASE 53LL
#define BASE_INV1 56603774LL
#define BASE_INV2 188679247LL

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

//----------------------------------------------------------------------------------------------------------------------

int main() {
	sync;

	string str;
	while (cin >> str) {
		ll code1 = 0, revCode1 = 0, code2 = 0, revCode2 = 0, len = 0, ans = 0;
		ROF(i, sz(str) - 1, 0) {
			code1 = shiftLeft(code1, MOD1);
			code1 = addAt(code1, 0, str[i], MOD1);
			revCode1 = addAt(revCode1, len, str[i], MOD1);
			code2 = shiftLeft(code2, MOD2);
			code2 = addAt(code2, 0, str[i], MOD2);
			revCode2 = addAt(revCode2, len, str[i], MOD2);

			if (code1 == revCode1 &&
				code2 == revCode2)
				ans = sz(str) - i;

			len++;
		}

		cout << str;
		ROF(i, sz(str) - ans - 1, 0)
			cout << str[i];

		cout << endl;
	}

	return 0;
}

//======================================================================================================================