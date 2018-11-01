#include <bits/stdc++.h>

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// We need to create a complete graph with an eulerian path (first number on a is where we start).
// Given n and m we need to find the most amount of numbers we can have. For example,
// if we are going to put 5 numbers, we need 5 * 4 / 2 edges (or spots in the array), so we
// can iterate over all amounts of numbers and pick the largest one that satisfies the conditions.
// For even amount of numbers the special case is x * (x - 1) / 2 - x / 2 - 1 (at most two nodes of
// odd degree in eulerian graph).

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
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll a[100005];

ll solve(ll n, ll m) {
	ll ret = 1;
	ll limit = n - 1;
	FOR(i, 2, m + 1) {
		if (i % 2 == 0) {
			if (limit >= i * (i - 1) / 2 + i / 2 - 1)
				ret = i;
		}
		else {
			if (limit >= i * (i - 1) / 2)
				ret = i;
		}
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, m;
	cin >> n >> m;
	FOR(i, 0, m) {
		ll x;
		cin >> x;
		cin >> x;
		a[i] = x;
	}

	sort(a, a + m, greater<ll>());

	ll ans = 0;
	n = solve(n, m);
	FOR(i, 0, n) {
		ans += a[i];
	}

	cout << ans << endl;

	return 0;
}

