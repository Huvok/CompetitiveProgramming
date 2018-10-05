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
// Iterate over all possible sizes for the array A. Lets say you are at size x, iterate over all windows of this size
//     and get the sum of the best one (smallest sum). Now use double pointers over b to get the best result.

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
ll a[2005], b[2005];

ll init(ll x) {
	ll ret = 0;
	FOR(i, 0, x) {
		ret += a[i];
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;

	ll n, m;
	cin >> n >> m;

	FOR(i, 0, n)
		cin >> a[i];
	FOR(i, 0, m)
		cin >> b[i];

	ll x;
	cin >> x;
	ll ans = 0;
	FOR(i, 1, n + 1) {
		ll s = init(i);
		ll curs = s;
		FOR(r, i, n) {
			s = min(s, curs);
			curs = curs + a[r] - a[r - i];
		}

		ll cur = 0;
		ll l = 0, r = -1;
		while (r < m) {
			if (cur <= x) {
				ans = max(ans, (r - l + 1) * i);
				r++;
				if (r >= m)
					break;

				cur += s * b[r];
			}
			else {
				cur -= s * b[l];
				l++;
			}
		}
	}



	cout << ans << endl;

	return 0;
}

//======================================================================================================================