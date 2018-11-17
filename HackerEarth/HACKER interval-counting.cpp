#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// By contribution technique, count the number of pairs on which the ith element is the minimum.
// For every i, get until which element it is the minimum to the left and to the right, then in that segment
// iterate over the smallest half (l - i or i - r) and now that you have fixed the i and l, you must
// count the number of valid r, which can be donde using a fenwick or segment tree. Do this offline so
// that you can store the queries and answer them in order in the end. The answer for a query of type
// l, i, r is query(r, val) - query(i, val).

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
ll a[500005];
ll n;
ll k;

ll bit[500005];

ll query(ll x) {
	ll ret = 0;
	for(; x >= 0; x = (x & (x + 1)) - 1)
		ret += bit[x];
	return ret;
}

void upd(ll idx, ll x) {
	for (; idx < n; idx = idx | (idx + 1))
		bit[idx] += x;
}

ll l[500005], r[500005];
vector<pair<ll, ll>> queries[500005];
//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	cin >> n >> k;
	vi v(n);
	FOR(i, 0, n) {
		cin >> a[i];
		v[i] = a[i];
	}

	FOR(i, 0, n)
		l[i] = r[i] = i;
	FOR(i, 1, n) {
		ll p = i;
		while (p && a[i] < a[p - 1])
			p = l[p - 1];
		l[i] = p;
	}
	ROF(i, n - 1, 0) {
		ll p = i;
		while (p + 1 < n && a[i] <= a[p + 1])
			p = r[p + 1];
		r[i] = p;
	}
	sort(all(v));
	uni(v);
	
	ll ans = 0;
	FOR(i, 0, n) {
		ll ax = i - l[i] + 1;
		ll bx = r[i] - i + 1;
		if (ax < bx) {
			FOR(j, l[i], i + 1) {
				ll look = k - a[i] - a[j];
				look = upper_bound(all(v), look) - v.begin() - 1;
				queries[r[i]].pb(mp(look, 1));
				if (i)
					queries[i - 1].pb(mp(look, -1));
			}
		}
		else {
			FOR(j, i, r[i] + 1) {
				ll look = k - a[i] - a[j];
				look = upper_bound(all(v), look) - v.begin() - 1;
				queries[i].pb(mp(look, 1));
				if (l[i])
					queries[l[i] - 1].pb(mp(look, -1));
			}
		}
	}

	FOR(i, 0, n) {
		ll cur = lower_bound(all(v), a[i]) - v.begin();
		upd(cur, 1);
		for (ii hue : queries[i]) {
			ans += query(hue.first) * hue.second;
		}
	}

	cout << ans << endl;

	return 0;
}