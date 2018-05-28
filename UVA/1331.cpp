#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <queue>
#include <bitset>
#include <sstream>
#include <set>
#include <iomanip>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <iterator>
#include <complex>

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

using namespace std;

//                                          //AUTHOR: Hugo Garcia
//                                          //IDEA: Lets use two pointers as dp state, we will try to generate a 
//                                          //      triangle to a point k that is between l and r, if this triangle is
//                                          //      possible i.e. no edge intersects the area of the triangle l, k, r,
//                                          //      we recurse to dp[l][k] + dp[k][r].

//======================================================================================================================

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
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, VA_ARGS), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 100000000000000000

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
template <class F>
struct Point {
	F x, y;
	Point() : x(0), y(0) {}
	Point(const F& x, const F& y) : x(x), y(y) {}

	void swap(Point& other) { using std::swap; swap(x, other.x); swap(y, other.y); }
	template <class F1> explicit operator Point<F1>() const {
		return Point<F1>(static_cast<F1>(x), static_cast<F1>(y));
	}
	template <class F1> Point& operator = (const Point<F1>& other) {
		x = other.x; y = other.y; return *this;
	}
	template <class F1> Point& operator += (const Point<F1>& other) {
		x += other.x; y += other.y; return *this;
	}
	template <class F1> Point& operator -= (const Point<F1>& other) {
		x -= other.x; y -= other.y; return *this;
	}
	template <class F1> Point& operator *= (const F1& factor) {
		x *= factor; y *= factor; return *this;
	}
	template <class F1> Point& operator /= (const F1& factor) {
		x /= factor; y /= factor; return *this;
	}
};

template <class F> using Polygon = vector<Point<F>>;
inline int prev(int i, int n) { return i == 0 ? n - 1 : i - 1; }
inline int next(int i, int n) { return i == n - 1 ? 0 : i + 1; }
template <class T> inline int sgn(const T& x) { return (T(0) < x) - (x < T(0)); }

template <class F>
F area(const Polygon<F>& poly) 
{
	int n = static_cast<int>(poly.size());
	F area = F(0);
	for (int i = 0; i < n; ++i)
		area += poly[i].x * (poly[prev(i, n)].y - poly[next(i, n)].y);
	return area;
}

Polygon<ll> poly;
double dp[55][55];

double getArea(ll a, ll b, ll c)
{
	Point<ll> A = poly[a], B = poly[b], C = poly[c];
	return fabs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y)) * .5;
}

ll n;
double solve(ll l, ll r)
{
	if (l + 1 == r)
		return 0;

	if (dp[l][r] >= 0)
		return dp[l][r];

	double ret = 1e18;
	FOR(k, l + 1, r)
	{
		bool aux = true;
		double area = getArea(l, k, r);

		FOR(i, 0, n)
		{
			if (!aux)
				break;
			if (i == l ||
				i == r ||
				i == k)
				continue;

			double candidate = getArea(l, k, i) + getArea(l, r, i) + getArea(k, r, i);

			if (fabs(area - candidate) < EPS)
				aux = false;
		}

		if (aux)
			ret = min(ret, max(area, max(solve(l, k), solve(k, r))));
	}

	return dp[l][r] = ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		poly.clear();
		FOR(i, 0, n)
		{
			ll a, b;
			cin >> a >> b;
			poly.pb(Point<ll>(a, b));
		}

		FOR(i, 0, 55)
		{
			FOR(j, 0, 55)
			{
				dp[i][j] = -1e17;
			}
		}

		solve(0, n - 1);
		cout << fixed << setprecision(1) << dp[0][n - 1] << endl;
	}

	return 0;
}

//======================================================================================================================