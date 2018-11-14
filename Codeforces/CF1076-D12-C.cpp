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
// b must be a / (a - 1) to be valid. Also, n must be equal or more than 4 for an answer to exist. Do a binary search
// over the value of a.

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

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll t;
	cin >> t;
	cout << fixed << setprecision(10);
	while (t--) {
		ll d;
		cin >> d;
		if (d == 4) {
			cout << "Y " << 2. << " " << 2. << endl;
			continue;
		}
		double low = 1.00001, high = d;
		FOR(i, 0, 5000) {
			double m = (low + high) / 2;
			double b = m / (m - 1);
			if ((m + b) < d)
				low = m;
			else
				high = m;
		}

		double b = low / (low - 1);
		if (abs(low * b - d) < EPS && abs(low + b - d) < EPS)
			cout << "Y " << low << " " << b << endl;
		else
			cout << "N" << endl;
	}

	

	return 0;
}