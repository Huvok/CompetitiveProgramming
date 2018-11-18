#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Try the four combinations (and the naive manhattan) of intersecting the diagonal by going
// horizontal from A and B, vertical from A and horizontal from B... And take the best from them.
// To get the intersection in horizontal solve for x the line equation and similar for
// vertical. Then you can also get the points of intersection and then get the length
// of the diagonal.

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
double dst(double x1, double y1, double x2, double y2) {
	double x = abs(x1 - x2);
	double y = abs(y1 - y2);
	x = x * x;
	y = y * y;
	return sqrt(x + y);
}
//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	
	ll a, b, c;
	cin >> a >> b >> c;
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double ans = abs(x1 - x2) + abs(y1 - y2);
	// x - x
	double da = abs(x1 - ((-c - b * y1) * 1. / a));
	double db = abs(x2 - ((-c - b * y2) * 1. / a));
	double xa = (-c - b * y1) * 1. / a;
	double xb = (-c - b * y2) * 1. / a;
	double ya = (-c - a * xa) / b;
	double yb = (-c - a * xb) / b;
	ans = min(ans, dst(xa, ya, xb, yb) + da + db);

	// x-  y
	 da = abs(x1 - ((-c - b * y1) * 1. / a));
	 db = abs(y2 - ((-c - a * x2) * 1. / b));
	xa = (-c - b * y1) * 1. / a;
	yb = (-c - a * x2) * 1. / b;
	xb = (-c - b * yb) / a;
	 ya = (-c - a * xa) / b;
	ans = min(ans, dst(xa, ya, xb, yb) + da + db);

	// y - x
	 da = abs(y1 - ((-c - a * x1) * 1. / b));
	 db = abs(x2 - ((-c - b * y2) * 1. / a));
	 ya = (-c - a * x1) * 1. / b;
	 xa = (-c - b * ya) / a;
	 xb = (-c - b * y2) * 1. / a;
	 yb = (-c - a * xb) / b;
	ans = min(ans, dst(xa, ya, xb, yb) + da + db);

	// y - y
	 da = abs(y1 - ((-c - a * x1) * 1. / b));
	 db = abs(y2 - ((-c - a * x2) * 1. / b));
	 yb = (-c - a * x2) * 1. / b;
	 xb = (-c - b * yb) / a;
	 ya = (-c - a * x1) * 1. / b;
	 xa = (-c - b * ya) / a;
	ans = min(ans, dst(xa, ya, xb, yb) + da + db);

	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}