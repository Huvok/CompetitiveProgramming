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
// If n is odd, take out its first prime divisor. After that or if it is even, answer is n / 2.

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
vi primes;
bool isprime[200005];

void sieve() {
	mem(isprime, true);
	isprime[0] = isprime[1] = false;
	FOR(i, 2, 200005) {
		if (isprime[i]) {
			primes.pb(i);
			for (ll j = i + i; j < 200005; j += i) {
				isprime[j] = false;
			}
		}
	}
}

bool is_prime(ll n) {
	ll limit = sqrt(n) + 2;
	FOR(i, 2, limit) {
		if (n % i == 0 &&
			i != n) {
			return false;
		}
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;

	sieve();
	ll ans = 0;
	if (is_prime(n))
	{
		cout << 1 << endl;
		return 0;
	}
	if (n % 2 == 1) {
		for (auto it : primes) {
			if (n % it == 0) {
				n -= it;
				ans++;
				break;
			}
		}
	}

	ans += n / 2;
	cout << ans << endl;

	return 0;
}