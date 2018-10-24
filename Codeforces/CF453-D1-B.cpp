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
// Since one possible answer is all ones, the maximum number in the real answer will never exceed 60. dp[i][mask] is
// answer for the first ith terms and the prime factors of the bitmask mask have already been used. Try every number for 1 
// to 60 and get its prime factors in a mask. Then get the inverse of that mask and iterate over all possible submasks. It means
// that you are about to use the factors of the number k, so the previous answer has to have those factors off, so
// dp[i][submask | f[k]] means the answer for ith terms when you have used submask factors and are about to use the factors
// of number k. And it should be the minimum of all dp[i - 1][submask].

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
ll a[105], f[65];
bool isPrime[500];
vi primes;

void sieve() {
	mem(isPrime, true);
	isPrime[0] = isPrime[1] = false;
	FOR(i, 2, 60) {
		if (isPrime[i]) {
			primes.pb(i);
			for (ll j = i * i; j < 60; j += i)
				isPrime[j] = false;
		}
	}
}

ll getFacts(ll x) {
	ll ret = 0;
	
	FOR(i, 0, 17) {
		while (x % primes[i] == 0) {
			ret |= (1LL << i);
			x /= primes[i];
		}
	}

	return ret;
}

ll dp[105][1LL << 17], dpk[105][1LL << 17], ans[105];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	sieve();
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i + 1];

	FOR(i, 2, 60)
		f[i] = getFacts(i);

	ll limit = 1LL << 17;
	FOR(i, 1, n + 1) {
		FOR(k, 0, limit) {
			dp[i][k] = oo;
		}
	}

	FOR(k, 0, limit)
		dp[0][k] = 0;

	FOR(i, 1, n + 1) {
		FOR(k, 1, 60) {
			ll mask = (~f[k]) & (limit - 1);
			for (ll submask = mask; ; submask = (submask - 1) & mask) {
				if (submask == 0) {
					ll y = 9;
				}
				if (dp[i - 1][submask] + abs(a[i] - k) < dp[i][submask | f[k]]) {
					dp[i][submask | f[k]] = dp[i - 1][submask] + abs(a[i] - k);
					dpk[i][submask | f[k]] = k;
				}

				if (submask == 0)
					break;
			}
		}
	}

	ll champ = 0;
	FOR(i, 0, limit) {
		if (dp[n][champ] > dp[n][i])
			champ = i;
	}

	ROF(i, n, 1) {
		ans[i] = dpk[i][champ];
		champ ^= f[dpk[i][champ]];
	}

	FOR(i, 1, n + 1) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}