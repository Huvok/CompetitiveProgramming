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
// In order lets iterate over all A and asume the current A is the maximum one in the set of the answer.
//     Now from the subset of all elements with lower or equal A's, lets do the same for every E (i.e. sort this
//     set and iterate over all possible E and asume it is the biggest one in the answer). Now sort all the
//     elements with lower E's and take the minimum K D's.

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
struct boi {
	ll a, e, d;
	bool operator <(const boi &o) const {
		if (a == o.a) {
			if (e == o.e)
				return d < o.d;
			return e < o.e;
		}
		return a < o.a;
	}
};

boi a[2005];
boi cur[2005];

bool cmpe(boi a, boi b) {
	return a.e < b.e;
}

class compd {
public:
	bool operator ()(boi a, boi b) {
		return a.d < b.d;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, k;
	cin >> n >> k;
	FOR(i, 0, n) {
		cin >> a[i].a >> a[i].e >> a[i].d;
	}

	sort(a, a + n);
	ll ans = oo;
	FOR(i, 0, n) {
		cur[i] = a[i];
		sort(cur, cur + i + 1, cmpe);
		priority_queue<boi, vector<boi>, compd> pq;
		FOR(j, 0, i + 1) {
			pq.push(cur[j]);
			if (sz(pq) > k)
				pq.pop();
			if (sz(pq) >= k)
				ans = min(ans, a[i].a + cur[j].e + pq.top().d);
		}
	}

	cout << ans << endl;

	return 0;
}

//======================================================================================================================