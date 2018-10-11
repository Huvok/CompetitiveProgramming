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
// If you have guns i and j and use i before j you get Ci*W + Cj*W*Ri, otherwise Cj*W + Ci*W*Rj, now who is better?
//      we want to be able to compare every gun just by themselves, so if we equal the equations we want all i in one side
//      and j in other side. We can get the equations Ci / (1 - Ri) vs Cj / (1 - Rj) and sort based on this.

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
pair<ll, double> a[100005];

bool cmp(pair<ll, double> p, pair<ll, double> q) {
	return (p.first * (1 - q.second) < q.first * (1 - p.second));
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, w;
	cin >> n >> w;
	FOR(i, 0, n) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a, a + n, cmp);

	double ans = 0;
	double cur = w;

	FOR(i, 0, n) {
		ans += a[i].first * cur;
		cur = cur * a[i].second;
	}

	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}

//======================================================================================================================