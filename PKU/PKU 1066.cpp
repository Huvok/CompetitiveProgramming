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
//                                          //IDEA: The main idea is that a line from the middle point between two
//                                          //      the edge of the biggest square to the objective point will intersect
//                                          //      the same amount of lines as if we took a detour to pass them right
//                                          //      in the middle, so we can iterate for every middle point in the outer
//                                          //      edges, draw a line to the objective point and check how many
//                                          //      segments this line intersects. This is true because the possible
//                                          //      "doors" to pass will always look like a convex polygon with respect
//                                          //      to the current point, so it does not matter where you pass an edge,
//                                          //      since you will end up passing through it (in case you need it) and
//                                          //      every needed edge/segment is present in the line you draw.

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

template <class F> int read(Point<F>& point) { return read(point.x, point.y) / 2; }
template <class F> int write(const Point<F>& point) { return write(point.x, point.y); }

template <class F> istream& operator >> (istream& is, Point<F>& point) {
	return is >> point.x >> point.y;
}
template <class F> ostream& operator << (ostream& os, const Point<F>& point) {
	return os << point.x << ' ' << point.y;
}

template <class F> inline Point<F> makePoint(const F& x, const F& y) { return Point<F>(x, y); }
template <class F> void swap(Point<F>& lhs, Point<F>& rhs) { lhs.swap(rhs); }

#define FUNC1(name, arg, expr) \
template <class F> inline auto name(const arg) -> decltype(expr) { return expr; }
#define FUNC2(name, arg1, arg2, expr) \
template <class F1, class F2> \
inline auto name(const arg1, const arg2) -> decltype(expr) { return expr; }
#define FUNC3(name, arg1, arg2, arg3, expr) \
template <class F1, class F2, class F3> \
inline auto name(const arg1, const arg2, const arg3) -> decltype(expr) { return expr; }

FUNC1(operator -, Point<F>& point, makePoint(-point.x, -point.y))
FUNC2(operator +, Point<F1>& lhs, Point<F2>& rhs, makePoint(lhs.x + rhs.x, lhs.y + rhs.y))
FUNC2(operator -, Point<F1>& lhs, Point<F2>& rhs, makePoint(lhs.x - rhs.x, lhs.y - rhs.y))
FUNC2(operator *, F1& factor, Point<F2>& rhs, makePoint(factor * rhs.x, factor * rhs.y))
FUNC2(operator *, Point<F1>& lhs, F2& factor, makePoint(lhs.x * factor, lhs.y * factor))
FUNC2(operator /, Point<F1>& lhs, F2& factor, makePoint(lhs.x / factor, lhs.y / factor))

FUNC2(operator *, Point<F1>& lhs, Point<F2>& rhs, lhs.x * rhs.x + lhs.y * rhs.y)
FUNC2(operator ^, Point<F1>& lhs, Point<F2>& rhs, lhs.x * rhs.y - lhs.y * rhs.x)

// < 0 if rhs <- lhs counter-clockwise, 0 if collinear, > 0 if clockwise.
FUNC2(ccw, Point<F1>& lhs, Point<F2>& rhs, rhs ^ lhs)
FUNC3(ccw, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin, ccw(lhs - origin, rhs - origin))

FUNC2(operator ==, Point<F1>& lhs, Point<F2>& rhs, lhs.x == rhs.x && lhs.y == rhs.y)
FUNC2(operator !=, Point<F1>& lhs, Point<F2>& rhs, !(lhs == rhs))

FUNC2(operator <, Point<F1>& lhs, Point<F2>& rhs,
	lhs.y < rhs.y || (lhs.y == rhs.y && lhs.x < rhs.x))
	FUNC2(operator >, Point<F1>& lhs, Point<F2>& rhs, rhs < lhs)
	FUNC2(operator <=, Point<F1>& lhs, Point<F2>& rhs, !(lhs > rhs))
	FUNC2(operator >=, Point<F1>& lhs, Point<F2>& rhs, !(lhs < rhs))

	// Angles and rotations (counter-clockwise).
	FUNC1(angle, Point<F>& point, atan2(point.y, point.x))
	FUNC2(angle, Point<F1>& lhs, Point<F2>& rhs, atan2(lhs ^ rhs, lhs * rhs))
	FUNC3(angle, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin,
		angle(lhs - origin, rhs - origin))
	FUNC3(rotate, Point<F1>& point, F2& angleSin, F3& angleCos,
		makePoint(angleCos * point.x - angleSin * point.y,
			angleSin * point.x + angleCos * point.y))
	FUNC2(rotate, Point<F1>& point, F2& angle, rotate(point, sin(angle), cos(angle)))
	FUNC3(rotate, Point<F1>& point, F2& angle, Point<F3>& origin,
		origin + rotate(point - origin, angle))
	FUNC1(perp, Point<F>& point, makePoint(-point.y, point.x))

	// Distances.
	FUNC1(abs, Point<F>& point, point * point)
	FUNC1(norm, Point<F>& point, sqrt(abs(point)))
	FUNC2(dist, Point<F1>& lhs, Point<F2>& rhs, norm(lhs - rhs))
	FUNC2(dist2, Point<F1>& lhs, Point<F2>& rhs, abs(lhs - rhs))
	FUNC2(bisector, Point<F1>& lhs, Point<F2>& rhs, lhs * norm(rhs) + rhs * norm(lhs))

#undef FUNC1
#undef FUNC2
#undef FUNC3

	template <class F>
struct Line {
	Point<F> a, ab;
	Line() : a(), ab() {}
	Line(const Point<F>& a, const Point<F>& b, bool twoPoints = true)
		: a(a), ab(twoPoints ? b - a : b) {}
	Line(const F& xa, const F& ya, const F& xb, const F& yb)
		: a(xa, ya), ab(xb - xa, yb - ya) {}

	void swap(Line& other) { using std::swap; swap(a, other.a); swap(ab, other.ab); }
	template <class F1> explicit operator Line<F1>() const {
		return Line<F1>(Point<F1>(a), Point<F1>(ab), false);
	}
	template <class F1> Line& operator = (const Line<F1>& other) {
		a = other.a; ab = other.ab; return *this;
	}

	Point<F> b() const { return a + ab; }
	operator bool() const { return ab != Point<F>(); }
};

template <class F> int read(Line<F>& line) {
	int res = read(line.a, line.ab) / 2;
	return line.ab -= line.a, res;
}

template <class F>
inline Line<F> makeLine(const Point<F>& a, const Point<F>& b, bool twoPoints = true) {
	return Line<F>(a, b, twoPoints);
}

template <class F> void swap(Line<F>& lhs, Line<F>& rhs) { lhs.swap(rhs); }

template <class F1, class F2>
bool onLine(const Point<F1>& point, const Line<F2>& line) {
	if (!line) return point == line.a;
	return ((point - line.a) ^ line.ab) == 0;
}

template <class F1, class F2>
bool onSegment(const Point<F1>& point, const Line<F2>& seg) {
	if (!seg) return point == seg.a;
	auto vecta = seg.a - point, vectb = seg.b() - point;
	return (vecta ^ vectb) == 0 && (vecta * vectb) <= 0;
}

template <class F1, class F2> using distF = decltype(sqrt(F1() + F2()));

template <class F1, class F2>
distF<F1, F2> distLine(const Point<F1>& point, const Line<F2>& line) {
	if (!line) return dist(point, line.a);
	return abs((point - line.a) ^ line.ab) / norm(line.ab);
}

template <class F1, class F2>
distF<F1, F2> distSegment(const Point<F1>& point, const Line<F2>& seg) {
	if (((point - seg.a) * seg.ab) <= 0) return dist(point, seg.a);
	if (((point - seg.b()) * seg.ab) >= 0) return dist(point, seg.b());
	return distLine(point, seg);
}

template <int TYPE> struct EndpointChecker {};
template <> struct EndpointChecker<0> {  // no endpoint (ray)
	template <class F> bool operator ()(const F& a, const F& b) const { return true; }
};
template <> struct EndpointChecker<1> {  // closed endpoint
	template <class F> bool operator ()(const F& a, const F& b) const { return a <= b; }
};
template <> struct EndpointChecker<2> {  // open endpoint
	template <class F> bool operator ()(const F& a, const F& b) const { return a < b; }
};

template <int LA, int LB, int RA, int RB, class F1, class F2, class F3>
bool intersectLines(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
	assert(lhs && rhs);
	auto s = lhs.ab ^ rhs.ab;
	if (s == 0) return false;
	auto ls = (rhs.a - lhs.a) ^ rhs.ab;
	auto rs = (rhs.a - lhs.a) ^ lhs.ab;
	if (s < 0) s = -s, ls = -ls, rs = -rs;
	bool intersect =
		EndpointChecker<LA>()(decltype(ls)(0), ls) && EndpointChecker<LB>()(ls, s) &&
		EndpointChecker<RA>()(decltype(rs)(0), rs) && EndpointChecker<RB>()(rs, s);
	if (intersect) res = lhs.a + lhs.ab * static_cast<F3>(ls) / s;
	return intersect;
}

template <class F1, class F2, class F3>
bool intersectClosedSegments(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
	return intersectLines<1, 1, 1, 1>(lhs, rhs, res);
}

template <class F1, class F2, class F3>
bool intersectSegments(Line<F1>& lhs, Line<F2>& rhs, Line<F3>& res) {
	if (abs(lhs.ab.x) < EPS && abs(lhs.ab.y) < EPS)
		return distSegment(Point<F1>(lhs.a), rhs) < EPS;
	if (abs(rhs.ab.x) < EPS && abs(rhs.ab.y) < EPS)
		return distSegment(Point<F2>(rhs.a), lhs) < EPS;
	auto s = lhs.ab ^ rhs.ab;
	auto ls = (rhs.a - lhs.a) ^ rhs.ab;
	if (s == 0) {
		if (ls != 0) return false;
		auto lhsa = lhs.a, lhsb = lhs.b();
		auto rhsa = rhs.a, rhsb = rhs.b();
		if (lhsa > lhsb) swap(lhsa, lhsb);
		if (rhsa > rhsb) swap(rhsa, rhsb);
		res = Line<F3>(max(lhsa, rhsa), min(lhsb, rhsb));
		return res.ab >= Point<F3>();
	}
	auto rs = (rhs.a - lhs.a) ^ lhs.ab;
	if (s < 0) s = -s, ls = -ls, rs = -rs;
	bool intersect = 0 <= ls && ls <= s && 0 <= rs && rs <= s;
	if (intersect)
		res = Line<F3>(lhs.a + lhs.ab * static_cast<F3>(ls) / s, Point<F3>());
	return intersect;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll x1, x2, y1, y2;
		double x, y;
		vector<Point<double>> up, down, left, right;
		vector<Line<double>> segments;
		FOR(i, 0, n)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			Point<double> a(x1, y1), b(x2, y2);
			segments.pb(Line<double>(a, b));
			if (x1 == 0)
				left.pb(a);
			else if (x1 == 100)
				right.pb(a);
			else if (y1 == 0)
				down.pb(a);
			else
				up.pb(a);

			if (x2 == 0)
				left.pb(b);
			else if (x2 == 100)
				right.pb(b);
			else if (y2 == 0)
				down.pb(b);
			else
				up.pb(b);
		}

		cin >> x >> y;
		Point<double> d(x, y);

		ll ans = 1e9;
		up.pb(Point<double>(0, 100));
		up.pb(Point<double>(100, 100));
		down.pb(Point<double>(0, 0));
		down.pb(Point<double>(100, 0));
		left.pb(Point<double>(0, 0));
		left.pb(Point<double>(0, 100));
		right.pb(Point<double>(100, 0));
		right.pb(Point<double>(100, 100));

		sort(all(up));
		sort(all(down));
		sort(all(left));
		sort(all(right));

		FOR(i, 0, sz(up) - 1)
		{
			Point<double> s((up[i].x + up[i + 1].x) / 2, (up[i].y + up[i + 1].y) / 2);
			Line<double> ln(s, d);

			ll cnt = 1;
			FOR(j, 0, sz(segments))
			{
				Line<double> h(d, s);
				if (intersectSegments(ln, segments[j], h))
				{
					cnt++;
				}
			}

			ans = min(ans, cnt);
		}

		FOR(i, 0, sz(down) - 1)
		{
			Point<double> s((down[i].x + down[i + 1].x) / 2, (down[i].y + down[i + 1].y) / 2);
			Line<double> ln(s, d);

			ll cnt = 1;
			FOR(j, 0, sz(segments))
			{
				Line<double> h(d, s);
				if (intersectSegments(ln, segments[j], h))
				{
					cnt++;
				}
			}

			ans = min(ans, cnt);
		}

		FOR(i, 0, sz(left) - 1)
		{
			Point<double> s((left[i].x + left[i + 1].x) / 2, (left[i].y + left[i + 1].y) / 2);
			Line<double> ln(s, d);

			ll cnt = 1;
			FOR(j, 0, sz(segments))
			{
				Line<double> h(d, s);
				if (intersectSegments(ln, segments[j], h))
				{
					cnt++;
				}
			}

			ans = min(ans, cnt);
		}

		FOR(i, 0, sz(right) - 1)
		{
			Point<double> s((right[i].x + right[i + 1].x) / 2, (right[i].y + right[i + 1].y) / 2);
			Line<double> ln(s, d);

			ll cnt = 1;
			FOR(j, 0, sz(segments))
			{
				Line<double> h(d, s);
				if (intersectSegments(ln, segments[j], h))
				{
					cnt++;
				}
			}

			ans = min(ans, cnt);
		}

		cout << "Number of doors = " << ans << endl;

		if (t)
			cout << endl;
	}

	return 0;
}

//======================================================================================================================