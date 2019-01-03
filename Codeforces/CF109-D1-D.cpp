#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Copy the array and sort it. Keep track of every index (where should be every number in the final array).
// Then you must do at most two swaps per index: if you are going to swap i and j, you should make 
// sure that i is good, just keep track of any good index and if i is not that index, swap
// it.

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
ii a[100005];
ii b[100005];
ll n;

bool isGood(ll x) {
	string s = to_string(x);
	FOR(i, 0, sz(s)) {
		if (s[i] != '7' && s[i] != '4')
			return false;
	}

	return true;
}

bool isSorted() {
	FOR(i, 1, n) {
		if (a[i].first >= a[i - 1].first)
			continue;
		else
			return false;
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	cin >> n;

	FOR(i, 0, n) {
		cin >> a[i].first;
		b[i].first = a[i].first;
		b[i].second = i;
	}

	sort(b, b + n);

	ll idx = -1;
	FOR(i, 0, n) {
		if (isGood(a[i].first)) {
			idx = i;
		}
	}

	if (idx == -1) {
		if (!isSorted()) {
			cout << -1 << endl;
			return 0;
		}
	}

	map<ll, ll> m;
	FOR(i, 0, n) {
		a[b[i].second].second = i;
		m[i] = b[i].second;
	}

	vii ans;
	FOR(i, 0, n) {
		ll j = m[i];
		if (i == j)
			continue;

		if (i != idx) {
			ans.pb(ii(i + 1, idx + 1));
			swap(a[i], a[idx]);
			swap(m[a[i].second], m[a[idx].second]);
		}
		
		if (i != j) {
			ans.pb(ii(i + 1, j + 1));
			swap(a[i], a[j]);
			swap(m[a[i].second], m[a[j].second]);
			idx = j;
		}
	}

	cout << sz(ans) << endl;
	if (sz(ans) > 0) {
		FOR(i, 0, sz(ans))
			cout << ans[i].first << " " << ans[i].second << endl;
	}

	return 0;
}