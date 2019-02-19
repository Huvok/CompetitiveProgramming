#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Enumerate all digits up to 1e7, check if their digits sum to equal and check the amount
// of diferences.

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
bool cool(ll x) {
	string str = to_string(x);
	while (sz(str) < 6)
		str = "0" + str;

	string a = str.substr(0, 3);
	string b = str.substr(3);
	ll la = a[0] + a[1] + a[2] - 3 * '0';
	ll lb = b[0] + b[1] + b[2] - 3 * '0';

	return la == lb;
}

ll differ(ll x, string orig) {
	string str = to_string(x);
	while (sz(str) < 6)
		str = "0" + str;

	ll ret = 0;
	FOR(i, 0, 6) {
		if (orig[i] != str[i])
			ret++;
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	string str;
	cin >> str;
	ll ans = oo;
	FOR(i, 0, 999999 + 1) {
		if (cool(i)) {
			ans = min(ans, differ(i, str));
		}
	}

	cout << ans << endl;

	return 0;
}