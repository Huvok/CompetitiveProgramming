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
// change x == x^2 mod m to x * (x - 1) = km, since x - x and x^2 - x must be divisible by m. Also x = ac and (x - 1) =
//      bd, and cd = m. Using the two first equations, we get x - (x - 1) = ac - cd -> 1 = cd - ac, we can use
//      extended gcd to solve this, and c and d must be divisors of m, and coprime because of bezout identity.

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
class QuadraticIdentity {
public:
	ll m;
	vector<ll> factors, ans;
	ll ultragcd(ll a, ll b) {
		ll s = 0, olds = 1, t = 1, oldt = 0, r = b, oldr = a;
		while (r != 0) {
			ll q = oldr / r, z;
			z = oldr; oldr = r; r = z - q * r;
			z = olds; olds = s; s = z - q * s;
			z = oldt; oldt = t; t = z - q * t;
		}

		ll ans = b * oldt;
		if (ans < 0)
			ans += m;
		return ans;
	}

	void generate(ll a, ll b, ll i) {
		if (i == sz(factors))
			ans.pb(ultragcd(a, b));
		else {
			generate(a * factors[i], b, i + 1);
			generate(a, b * factors[i], i + 1);
		}
	}

	vector<ll> getFixedPoints(ll M) {
		this->m = M;
		ll N = M;
		for (ll i = 2; i * i <= M; i++) {
			if (N % i == 0) {
				ll P = 1;
				while (N % i == 0) {
					N /= i;
					P *= i;
				}
				factors.pb(P);
			}
		}

		if (N != 1)
			factors.pb(N);

		generate(1, 1, 0);
		sort(all(ans));
		if (ans[0] == 1)
			ans[0] = 0;
		while (sz(ans) > 500) {
			vi aux;
			FOR(i, 0, sz(ans)) {
				if (i % 2 == 0)
					aux.pb(ans[i]);
			}
			swap(aux, ans);
		}
		return ans;
	}
};

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;

	while (true) {
		ll n;
		cin >> n;
		QuadraticIdentity q;
		vector<ll> a = q.getFixedPoints(n);
		for (auto it : a)
			cout << it << " ";
		cout << endl;
	}

	return 0;
}

//======================================================================================================================