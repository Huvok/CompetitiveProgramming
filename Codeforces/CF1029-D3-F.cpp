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
// Iterate over divisors of a + b, say current divisor is i, we will force a side of the smaller rectangle to be shared
// with the side of size of the current divisor i. This means that (a + b) / di must be equal or bigger than a / dj, where
// a is the smaller rectangle and dj is a divisor of a. We can greedily take the biggest divisor of a that is smaller or equal
// than di and if and only if the condition above holds, update the possible new answer.

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
vii factors;

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

vi divisors;
void getDivisors(ll idx = 0, ll res = 1)
{
	if (idx == sz(factors))
	{
		divisors.pb(res);
		return;
	}

	FOR(i, 0, factors[idx].second + 1)
	{
		getDivisors(idx + 1, res);
		res *= factors[idx].first;
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll a, b;
	cin >> a >> b;

	ll ans = oo;
	FOR(hue, 0, 2) {
		swap(a, b);
		getFactors(a);
		getDivisors();
		vi da = divisors;
		divisors.clear();
		getFactors(a + b);
		getDivisors();
		vi db = divisors;
		divisors.clear();

		ll cur = 0;
		sort(all(da));
		sort(all(db));
		FOR(i, 0, sz(db)) {
			ll bl = db[i];
			
			ll target = (a + b) / bl;
			while (cur < sz(da) - 1 &&
				da[cur + 1] <= bl)
				cur++;

			if (da[cur] <= bl &&
				(a + b) / bl >= a / da[cur])
				ans = min(ans, 2 * bl + 2 * (a + b) / bl);
		}
	}

	cout << ans << endl;

	return 0;
}

//======================================================================================================================