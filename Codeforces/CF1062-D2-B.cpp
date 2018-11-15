#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Factorize n, the answer is the product of all its prime factors. The number of
// operation is as following. If you must multiply, you can use only one multiplication.
// Get the greatest factor power of n, if it is different than a power of two
// or at least two powers differ you must use a multiplication. After that, you need
// log2(a) sqrts where a is the highest power rounded up to a power of two.

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
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ii, ll>> viii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	
	ll n;
	cin >> n;
	vii facts;
	ll ans = 1;
	if (n == 1) {
		cout << "1 0" << endl;
		return 0;
	}
	FOR(i, 2, n + 1) {
		if (n % i == 0) {
			facts.pb(ii(i, 0));
			ans *= i;
		}
		while (n % i == 0) {
			n /= i;
			facts.back().second++;
		}
	}

	ll mx = 0;
	bool flag = true;
	FOR(i, 0, sz(facts)) {
		if (i) {
			if (facts[i].second != facts[i - 1].second)
				flag = false;
		}

		mx = max(mx, facts[i].second);
	}

	ll cnt = 0;
	ll ops = ceil(log2(mx));
	while (mx > 1) {
		if (mx & 1) cnt++;
		mx >>= 1;
	}

	if (cnt || !flag)
		ops++;

	cout << ans << " " << ops << endl;

	return 0;
}