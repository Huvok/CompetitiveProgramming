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
//                                          //IDEA: If we had 2^3, we know that there are 3 / t bases which have at
//                                          //      t trailing zeroes, all of them multiples of 2. This is because
//                                          //      to have at least t trailing zeroes you need your LSB to be 
//                                          //      of a power of the number (2^3 in this case). We multiply this answer
//                                          //      by the answers of each factor to produce the answers in for those
//                                          //      composite bases (such as 6, which is the base of 2 * 3). We just
//                                          //      multiply the frequency of each factor by M due to the exponent rule
//                                          //      and we repeat the same to get the bases with at least (t + 1)
//                                          //      trailing zeroes and at the end we can subscrant the second answer
//                                          //      from the first one.

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
#define oo 100000000000000000

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
vii factors;
#define MOD 100000007

ll fastPow(ll x, ll n)
{
	ll ret = 1;
	while (n)
	{
		if (n & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return ret;
}

void getFactors(ll n)
{
	factors.clear();
	ll step = 1;
	for (ll i = 2; i * i <= n; i += step, step = 2)
	{
		if (n % i == 0)
		{
			factors.pb(mp(i, 0));
			while (n % i == 0)
			{
				n /= i;
				factors.back().second++;
			}
		}
	}

	if (n != 1)
		factors.pb(mp(n, 1));
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n, m, t;
	ll cas = 1;
	while (true)
	{
		cin >> n >> m >> t;
		if (n + m + t == 0)
			break;

		getFactors(n);
		ll inclusion = 1, exclusion = 1;
		FOR(i, 0, sz(factors))
		{
			ll x = factors[i].second;
			inclusion = (inclusion * (x * m / t + 1)) % MOD;
			exclusion = (exclusion * (x * m / (t + 1) + 1)) % MOD;
		}

		cout << "Case " << cas << ": " << (inclusion - exclusion + MOD) % MOD << endl;
		cas++;
	}

	return 0;
}

//======================================================================================================================