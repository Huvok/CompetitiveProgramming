#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// The answer for n >= 4 will always be the same, and it will be the 4 extreme points. The
// only extra case is n = 3. The biggest bounding box parallel to x and y axis will always
// share two of its vertex with two extreme vertex, so try over all combinations of
// extreme vertex (6) and iterate over all points for possible candidates.

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
ii arr[300005];

ll dst(ii a, ii b) {
	ll x = abs(a.first - b.first);
	ll y = abs(a.second - b.second);
	return x + y;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;
	ii minx = ii(oo, oo);
	ii miny = ii(oo, oo);
	ii maxx = ii(-oo, -oo);
	ii maxy = ii(-oo, -oo);
	FOR(i, 0, n) {
		ll a, b;
		cin >> a >> b;
		arr[i] = ii(a, b);
		if (a < minx.first)
			minx = ii(a, b);
		if (a > maxx.first)
			maxx = ii(a, b);
		if (b < miny.second)
			miny = ii(a, b);
		if (b > maxy.second)
			maxy = ii(a, b);
	}

	ii maxis[4] = {minx, maxx, miny, maxy};
	ll ans = 0;
	FOR(i, 0, n) {
		FOR(j, 0, 4) {
			FOR(k, j + 1, 4) {
				if (arr[i] == maxis[j] ||
					arr[i] == maxis[k])
					continue;

				ans = max(ans, dst(arr[i], maxis[j]) +
						dst(maxis[j], maxis[k]) +
						dst(maxis[k], arr[i]));
			}
		}
	}

	cout << ans << " ";
	ans = dst(minx, maxy) + dst(maxy, maxx) + dst(maxx, miny) + dst(miny, minx);
	FOR(i, 1, n - 2)
		cout << ans << " ";
	cout << endl;

	return 0;
}

