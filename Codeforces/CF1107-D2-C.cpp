#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Use two pointers to divide the string into parts of the same character. If the distance
// between the pointers is too big, put everything into a vector and sort it and take the biggest
// k elements.

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
ll a[200005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, k;
	cin >> n >> k;

	FOR(i, 0, n)
		cin >> a[i];

	string str;
	cin >> str;

	ll ans = 0;
	ll l = 0, r = 0;
	while (r < n) {
		if (str[l] == str[r])
			r++;
		else {
			if (r - l > k) {
				vi v;
				FOR(i, l, r) {
					v.pb(a[i]);
				}

				sort(all(v));
				ROF(i, sz(v) - 1, sz(v) - k)
					ans += v[i];
				l = r;
			}
			else {
				while (l < r) {
					ans += a[l];
					l++;
				}
			}
		}
	}

	if (r - l > k) {
		vi v;
		FOR(i, l, r + 1) {
			v.pb(a[i]);
		}

		sort(all(v));
		ROF(i, sz(v) - 1, sz(v) - k)
			ans += v[i];
	}
	else {
		while (l < r) {
			ans += a[l];
			l++;
		}
	}

	cout << ans << endl;

	return 0;
}