#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Define two arrays, a will be for the acummulated values and b is for the
// actual added value. Maintain a pointer to the last element.

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

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll a[200005], b[200005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;
	ll s = 0;
	ll ptr = 1;
	while (n--) {
		ll t;
		cin >> t;
		if (t == 1) {
			ll x, y;
			cin >> x >> y;
			a[x] += y;
			s += x * y;
		}
		else if (t == 2) {
			ll x;
			cin >> x;
			ptr++;
			b[ptr] = x;
			s += x;
		}
		else {
			a[ptr - 1] += a[ptr];
			s -= a[ptr];
			a[ptr] = 0;
			s -= b[ptr];
			b[ptr] = 0;
			ptr--;
		}

		if (ptr == 0)
			cout << 0.000000 << endl;
		else
			cout << fixed << setprecision(9) << s * 1. / ptr << endl;
	}

	return 0;
}