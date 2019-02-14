#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Factorize b, and then you have to look for the minimum of all xi/yi where xi is a power
// of pi, and pi is a prime shared by b and n!. To get yi you factorized b, to get xi you can divide n
// by all powers of pi. For example, say 5!, divide 5! by 2, then by 4, etc... this way
// you get all the powers for pi, i.e. xi.

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define lld I64d
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ii, ll>> viii;

#define MOD 998244353

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, b;
	cin >> n >> b;
	ll ans = oo;
	FOR(i, 2, b + 1) {
		if (i * i > b)
			i = b;
		ll cnt = 0;
		while (b % i == 0) {
			b /= i;
			cnt++;
		}

		if (cnt == 0)
			continue;
		ll tmp = 0, mul = 1;
		while (mul <= n / i) {
			mul *= i;
			tmp += n / mul;
		}

		ans = min(ans, tmp / cnt);
	}

	cout << ans << endl;

	return 0;
}