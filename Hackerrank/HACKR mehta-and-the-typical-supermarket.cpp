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
//                                          //IDEA: By inclusion exclusion, define f(xi) as the numbers in the range
//                                          //      [L, R] divided by xi (0<=i<n). f(xi) = f(x0) + f(x1) - f(x0, x1)...
//                                          //      And f(x0, x1) = f(lcm(x0, x1)) so we can precalculate all f and for
//                                          //      every query try all subsets (2^17 is around 150k, so 2^n*d is fine).

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

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll a[20];
ll f[1LL << 18];
ll n;

ll gcd(ll a, ll b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	a = a / gcd(a, b);
	if (a <= oo / b)
		return a * b;
	return oo;
}

void precalc()
{
	ll limit = 1LL << n;
	
	FOR(i, 1, limit)
	{
		ll ret = 1;
		FOR(j, 0, n)
		{
			if (i & (1LL << j))
			{
				ret = lcm(ret, a[j]);
			}
		}

		f[i] = ret;
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	cin >> n;

	FOR(i, 0, n)
		cin >> a[i];

	precalc();

	ll q;
	cin >> q;
	ll l, r;
	ll limit = 1LL << n;

	FOR(i, 0, q)
	{
		cin >> l >> r;

		ll ans = 0;

		FOR(j, 1, limit)
		{
			if (__builtin_popcount(j) % 2 == 0)
				ans -= (r / f[j]) - ((l - 1) / f[j]);
			else
				ans += (r / f[j]) - ((l - 1) / f[j]);
		}

		cout << ans << endl;
	}

	return 0;
}

//======================================================================================================================