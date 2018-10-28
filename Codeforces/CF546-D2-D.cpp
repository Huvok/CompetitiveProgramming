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
// Answer is clearly number of prime divisors of a minus prime divisors of a, since by
// taking divisors we maximize the number of divisions. Calculate minimum prime divisor of each
// number through erathosthenes, then the count of prime divisors for number i, cnt[i], is cnt[i / smallestPrime[i]] + 1.
// Finally precalculate prefix sums.

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

#define MOD 998244353

//----------------------------------------------------------------------------------------------------------------------
vector<int> primes;
int smallestPrime[5000005];
ll cnt[5000005], dp[5000005];

void sieve() {
	mem(smallestPrime, -1);
	cnt[0] = cnt[1] = 0;
	dp[0] = dp[1] = 0;
	FOR(i, 2, 5000005) {
		if (smallestPrime[i] == -1) {
			smallestPrime[i] = i;
			for (ll j = i * i; j < 5000005; j += i)
				if (smallestPrime[j] == -1)
					smallestPrime[j] = i;
		}

		cnt[i] = cnt[i / smallestPrime[i]] + 1;
		dp[i] = dp[i - 1] + cnt[i];
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	sieve();

	ll n;
	cin >> n;
	
	FOR(i, 0, n) {
		ll a, b;
		cin >> a >> b;

		cout << dp[a] - dp[b] << endl;
	}

	return 0;
}