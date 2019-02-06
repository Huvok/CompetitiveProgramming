#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <queue>
#include <string.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <unordered_set>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

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

ll gcd(ll a, ll b)
{
	if (b) 
		return gcd(b, a % b);
	return a;
}

ll get(Polygon<ll> poly)
{
	ll ret = 0;
	FOR(i, 0, poly.size() - 1)
	{
		ll a = abs(poly[i].x - poly[i + 1].x);
		ll b = abs(poly[i].y - poly[i + 1].y);
		ret += (gcd(a, b) + 1);
	}

	ll a = abs(poly[0].x - poly[poly.size() - 1].x);
	ll b = abs(poly[0].y - poly[poly.size() - 1].y);
	ret += (gcd(a, b) + 1);

	return ret;
}


//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n;
	cin >> n;

	Polygon<ll> poly;

	ll x, y;
	FOR(i, 0, n)
	{
		cin >> x >> y;
		poly.push_back(Point<ll>(x, y));
	}

	double a = area(poly) * 1.0 / 2;
	if (a < 0)
		a *= -1;
	
	ll b = get(poly) - n;

	cout << (ll)((ll)a - b / 2 + 1) << endl;

	return 0;
}

//======================================================================================================================