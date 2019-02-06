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

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
double const EPS = 1e-9;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

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

template <class F1, class F2, class F3>
void projection(const Point<F1>& point, const Line<F2>& line, Point<F3>& res) {
	res = line.a;
	if (line) res += line.ab * static_cast<F3>((point - line.a) * line.ab) / abs(line.ab);
}

template <class F1, class F2, class F3>
void reflection(const Point<F1>& point, const Line<F2>& line, Point<F3>& res) {
	projection(point, line, res);
	res = 2 * res - point;
}

template <class F1, class F2, class F3>
void closest(const Point<F1>& point, const Line<F2>& seg, Point<F3>& res) {
	if (((point - seg.a) * seg.ab) <= 0) res = seg.a;
	else if (((point - seg.b()) * seg.ab) >= 0) res = seg.b();
	else projection(point, seg, res);
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
bool intersectSegments(const Line<F1>& lhs, const Line<F2>& rhs, Line<F3>& res) {
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

template <class F>
struct AngleCompare {
	const Point<F> origin;
	const bool zero;

	AngleCompare(const Point<F>& origin = Point<F>())
		: origin(origin), zero(origin == Point<F>()) {}

	template <class F1, class F2>
	bool operator () (const Point<F1>& lhs, const Point<F2>& rhs) const {
		return zero ? ccw(lhs, rhs) < 0 : ccw(lhs, rhs, origin) < 0;
	}
};

template <class Iterator, class F>
void sortByAngle(Iterator first, Iterator last, const Point<F>& origin) {
	first = partition(first, last, [&origin](const decltype(*first)& point) {
		return point == origin; });
	auto pivot = partition(first, last, [&origin](const decltype(*first)& point) {
		return point > origin; });
	AngleCompare<F> acmp(origin);
	sort(first, pivot, acmp);
	sort(pivot, last, acmp);
}


template <class F> using Polygon = vector<Point<F>>;
inline int prev(int i, int n) { return i == 0 ? n - 1 : i - 1; }
inline int next(int i, int n) { return i == n - 1 ? 0 : i + 1; }
template <class T> inline int sgn(const T& x) { return (T(0) < x) - (x < T(0)); }

template <class F>
F area(const Polygon<F>& poly) {
	int n = static_cast<int>(poly.size());
	F area = F(0);
	for (int i = 0; i < n; ++i)
		area += poly[i].x * (poly[prev(i, n)].y - poly[next(i, n)].y);
	return area;
}

// True if orientation of a simple polygon is counter-clockwise.
template <class F>
bool orientation(const Polygon<F>& poly) {
	int n = static_cast<int>(poly.size());
	int i = static_cast<int>(min_element(begin(poly), end(poly)) - begin(poly));
	return ccw(poly[prev(i, n)], poly[next(i, n)], poly[i]) > 0;
}

template <class F>
Polygon<F> convexHull(Polygon<F> points) {
	sort(begin(points), end(points));
	Polygon<F> hull;
	hull.reserve(points.size() + 1);
	for (int phase = 0; phase < 2; ++phase) {
		auto start = hull.size();
		for (auto& point : points) {
			while (hull.size() >= start + 2 &&
				ccw(point, hull.back(), hull[hull.size() - 2]) <= 0)
				hull.pop_back();
			hull.push_back(point);
		}
		hull.pop_back();
		reverse(begin(points), end(points));
	}
	if (hull.size() == 2 && hull[0] == hull[1]) hull.pop_back();
	return hull;
}

template <class F1, class F2>
int pointVsTriangle(const Point<F1>& point, const Polygon<F2>& triangle) {
	assert(triangle.size() == 3);
	int signs[3];
	for (int i = 0; i < 3; ++i)
		signs[i] = sgn(ccw(point, triangle[next(i, 3)], triangle[i]));
	if (signs[0] == signs[1] && signs[1] == signs[2]) return -1;
	for (int i = 0; i < 3; ++i) if (signs[i] * signs[next(i, 3)] == -1) return 1;
	return 0;
}

template <class F1, class F2>
int pointVsPolygon(const Point<F1>& point, const Polygon<F2>& poly) {
	int n = static_cast<int>(poly.size()), windingNumber = 0;
	for (int i = 0; i < n; ++i) {
		if (point == poly[i]) return 0;
		int j = next(i, n);
		if (poly[i].y == point.y && poly[j].y == point.y) {
			if (min(poly[i].x, poly[j].x) <= point.x &&
				point.x <= max(poly[i].x, poly[j].x)) return 0;
		}
		else {
			bool below = poly[i].y < point.y;
			if (below != (poly[j].y < point.y)) {
				auto orientation = ccw(point, poly[j], poly[i]);
				if (orientation == 0) return 0;
				if (below == (orientation > 0)) windingNumber += below ? 1 : -1;
			}
		}
	}
	return windingNumber == 0 ? 1 : -1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t;
	cin >> t;
	ll v, p;
	while (t--)
	{
		cin >> v >> p;

		Polygon<ll> poly;
		ll x, y;
		FOR(i, 0, v)
		{
			cin >> x >> y;
			poly.pb(Point<ll>(x, y));
		}

		ll ans = 0;
		FOR(i, 0, p)
		{
			cin >> x >> y;
			if (pointVsPolygon(Point<ll>(x, y), poly) == -1)
			{
				ans++;
			}
		}

		cout << ans << endl;
	}

	return 0;
}