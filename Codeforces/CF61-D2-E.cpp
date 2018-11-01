#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// For each number, check how much it contributes to the answer i.e. number of elements bigger than it to the
// left * number of elements smaller than it to the right. It can be done in many ways, for example with
// segment trees or order statistics tree.

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
ll a[1000005], g[1000005], l[1000005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;

	FOR(i, 0, n)
		cin >> a[i];

	ordered_set<ll> s;
	FOR(i, 0, n) {
		g[i] = i - s.order_of_key(a[i]);
		s.insert(a[i]);
	}

	s.clear();
	ROF(i, n - 1, 0) {
		l[i] = s.order_of_key(a[i]);
		s.insert(a[i]);
	}

	ll ans = 0;
	FOR(i, 0, n)
		ans += g[i] * l[i];
	cout << ans << endl;

	return 0;
}

