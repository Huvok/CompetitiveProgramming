#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Create two sparse tables, one to get gcds in range and another to get min in range (segment tree is too slow, maybe the iterative version works),
// then binary search the length of the answer. When you get the length, search linearly to see which indixes have that length.

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
ll n, a[300005];
ll sparseGcd[300005][30], sparseMin[300005][30];

void build() {
	FOR(i, 1, n + 1) {
		sparseGcd[i][0] = a[i];
		sparseMin[i][0] = i;
	}

	for (ll j = 1; 1 << j <= n; j++) {
		for (ll i = 1; i + ((1 << j) - 1) <= n; i++) {
			sparseGcd[i][j] = __gcd(sparseGcd[i][j - 1], sparseGcd[i + (1 << (j - 1))][j - 1]);
			if (a[sparseMin[i][j - 1]] < a[sparseMin[i + (1 << (j - 1))][j - 1]])
				sparseMin[i][j] = sparseMin[i][j - 1];
			else
				sparseMin[i][j] = sparseMin[i + (1 << (j - 1))][j - 1];
		}
	}
}

ll getGcd(ll i, ll j) {
	ll r = j - i + 1;
	ll k = (ll)log2(r);
	return __gcd(sparseGcd[i][k], sparseGcd[r - (1 << k) + i][k]);
}

ll getMin(ll i, ll j) {
	ll r = j - i + 1;
	ll k = (ll)log2(r);
	return min(a[sparseMin[i][k]], a[sparseMin[r - (1 << k) + i][k]]);
}

bool check(ll m) {
	FOR(i, 1, n - (m - 1) + 1) {
		ll a = getGcd(i, i + m - 1);
		ll b = getMin(i, i + m - 1);
		if (a == b)
			return true;
	}

	return false;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	cin >> n;

	FOR(i, 1, n + 1)
		cin >> a[i];
	
	build();

	ll l = 0, h = n;
	while (l < h) {
		ll m = ((h - l) >> 1) + l + 1;
		if (check(m))
			l = m;
		else
			h = m - 1;
	}

	vi v;
	FOR(i, 1, n - (l - 1) + 1) {
		if (getGcd(i, i + l - 1) == getMin(i, i + l - 1))
			v.pb(i);
	}

	cout << v.size() << " " << l - 1 << endl;
	FOR(i, 0, sz(v)) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}