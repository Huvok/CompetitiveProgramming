#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Make two vectors, one for each type and sort them. Try to use all a and b and maintain two
// pointers, then while there is still c computers left, check which value is smaller.

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

	ll a, b, c;
	cin >> a >> b >> c;

	ll n;
	cin >> n;
	vi va, vb;
	FOR(i, 0, n) {
		ll x;
		cin >> x;
		string str;
		cin >> str;
		if (str[0] == 'U')
			va.pb(x);
		else
			vb.pb(x);
	}

	sort(all(va));
	sort(all(vb));

	ll ans = 0;

	ll pa = 0, pb = 0;
	ll cnt = 0;
	while (pa < sz(va) &&
		a > 0) {
		a--;
		ans += va[pa++];
		cnt++;
	}

	while (pb < sz(vb) &&
		b > 0) {
		b--;
		ans += vb[pb++];
		cnt++;
	}

	while (c > 0) {
		if (pa < sz(va) &&
			pb < sz(vb)) {
			if (va[pa] < vb[pb])
				ans += va[pa++];
			else
				ans += vb[pb++];
			c--;
		}
		else if (pa < sz(va)) {
			c--;
			ans += va[pa++];
		}
		else if (pb < sz(vb)) {
			c--;
			ans += vb[pb++];
		}
		else {
			break;
		}

		cnt++;
	}

	cout << cnt << " " << ans << endl;

	return 0;
}