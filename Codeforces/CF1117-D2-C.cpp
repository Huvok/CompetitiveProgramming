#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Binary search the answer. To check if m is valid, precalculate where you will be after m
// days due to the wind, and add your current position. If the manhattan distance is
// not greater than m, then it is possible.

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
ll x1, ys, x2, y2, n;
string str;
ll dpv[200005], dph[200005];

bool check(ll m) {
	ll x = 0, y = 0;
	ll c = m / n;
	x += c * dph[n - 1];
	y += c * dpv[n - 1];
	c = m % n;
	if (c) {
		x += dph[c - 1];
		y += dpv[c - 1];
	}
	x += x1;
	y += ys;
	if (abs(x - x2) + abs(y - y2) <= m)
		return true;
	return false;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	cin >> x1 >> ys >> x2 >> y2;
	cin >> n;
	cin >> str;
	if (str[0] == 'U')
		dpv[0] = 1;
	else if (str[0] == 'D')
		dpv[0] = -1;
	else if (str[0] == 'R')
		dph[0] = 1;
	else
		dph[0] = -1;

	FOR(i, 1, n) {
		dpv[i] = dpv[i - 1];
		dph[i] = dph[i - 1];
		if (str[i] == 'U')
			dpv[i] += 1;
		else if (str[i] == 'D')
			dpv[i] += -1;
		else if (str[i] == 'R')
			dph[i] += 1;
		else
			dph[i] += -1;
	}

	ll l = 0, r = 1e18;
	while (l < r) {
		ll m = ((r - l) >> 1) + l;
		if (check(m))
			r = m;
		else
			l = m + 1;
	}

	if (l > 1e17)
		l = -1;
	cout << l << endl;

	return 0;
}