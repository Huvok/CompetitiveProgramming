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
// Lets find the number of non-square-frees. Try every number p, and the numbers that are divided by p^2 are n / p^2,
// and are not square-free, but also you are counting some numbers more than once (36 is divided by 4 and by 9), so
// by inclusion-exclusion you have to take the number of prime factors of p into consideration. If they are odd, add,
// if even, substract, which is exactly the mobius function. Also, some p are already not square free and n / p^2 should not be 
// tested, but for non square free mobius[p] = 0.

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
vector <int> prime;
bool is_composite[10000007];
ll u[10000007];

void sieve() {
	ll n = 10000007;
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.push_back(i);
			u[i] = -1;
		}
		for (int j = 0; j < prime.size() && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				u[i * prime[j]] = 0;
				break;
			}
			else {
				u[i * prime[j]] = u[i] * u[prime[j]];
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll t;
	cin >> t;
	sieve();
	while (t--) {
		ll n;
		cin >> n;

		ll ans = n;
		FOR(i, 2, n) {
			if (i * i > n)
				break;

			ans += u[i] * (n / (i * i));
		}

		cout << ans << endl;
	}
	
	return 0;
}