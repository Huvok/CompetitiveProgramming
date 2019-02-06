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

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }

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

#undef FUNC1
#undef FUNC2
#undef FUNC3

Point<ll> a[105];
ll n;
double d;
vi le, ri;
vi adj[105];
ll lhs, rhs;
unordered_map<ll, ll> m;

double dist(Point<ll> a, Point<ll> b)
{
	a -= b;
	ll x = a * a;
	return sqrt(a * a);
}

void unlink(Point<ll> p, Point<ll> q, ll i, ll j)
{
	FOR(k, 1, n + 1)
	{
		if (i != k &&
			j != k)
		{
			if (k == 81)
			{
				ll xd = 1;
			}
			double d1 = dist(p, a[k]);
			double d2 = dist(q, a[k]);

			if (dist(p, a[k]) <= d &&
				dist(q, a[k]) <= d)
			{
				if (((p - q) ^ (a[k] - q)) > 0LL)
					le.pb(k);
				else
					ri.pb(k);
			}
		}
	}
}

void link()
{
	FOR(i, 1, n + 1)
		adj[i].clear();

	lhs = sz(le);
	rhs = sz(ri);

	FOR(i, 0, lhs)
		m.insert(mp(i + 1, le[i]));
	FOR(i, 0, rhs)
		m.insert(mp(i + lhs + 1, ri[i]));

	FOR(i, 0, lhs)
	{
		FOR(j, 0, rhs)
		{
			double di = dist(a[le[i]], a[ri[j]]);
			if (di > d)
			{
				adj[i + 1].pb(j + lhs + 1);
				adj[j + lhs + 1].pb(i + 1);
			}
		}
	}
}

ll match[105], dst[105];

bool bfs()
{
	ll i, u, v, len;
	queue<ll> q;
	for (i = 1; i <= n; i++)
	{
		if (match[i] == 0)
		{
			dst[i] = 0;
			q.push(i);
		}
		else
			dst[i] = 1e18;
	}

	dst[0] = 1e18;
	while (!q.empty())
	{
		u = q.front();
		q.pop();

		if (u != 0)
		{
			len = adj[u].size();
			for (i = 0; i < len; i++)
			{
				v = adj[u][i];

				if (dst[match[v]] == 1e18)
				{
					dst[match[v]] = dst[u] + 1;
					q.push(match[v]);
				}
			}
		}
	}

	return (dst[0] != 1e18);
}

bool dfs(ll u)
{
	ll i, v, len;
	if (u != 0)
	{
		len = adj[u].size();
		for (i = 0; i < len; i++)
		{
			v = adj[u][i];
			if (dst[match[v]] == dst[u] + 1)
			{
				if (dfs(match[v]))
				{
					match[v] = u;
					match[u] = v;
					return true;
				}
			}
		}

		dst[u] = 1e18;
		return false;
	}

	return true;
}

ll hopcroftKarp()
{
	ll matching = 0, i;
	while (bfs())
	{
		for (i = 1; i <= n; i++)
		{
			if (match[i] == 0 &&
				dfs(i))
				matching++;
		}
	}

	return matching;
}

unordered_set<ll> banned[105];
unordered_set<ll> champset;

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;
	cin >> n >> d;
	FOR(i, 1, n + 1)
		cin >> a[i].x >> a[i].y;

	FOR(i, 1, n + 1)
	{
		FOR(j, 1, n + 1)
		{
			if (dist(a[i], a[j]) > d)
				banned[i].insert(j);
		}
	}

	ll ans = 1;
	vi champ;
	double orig = d;
	champ.pb(1);
	FOR(i, 1, n + 1)
	{
		FOR(j, i + 1, n + 1)
		{
			if (dist(a[i], a[j]) <= d)
			{
				double old = d;
				d = dist(a[i], a[j]);
				le.clear();
				ri.clear();
				m.clear();
				unlink(a[i], a[j], i, j);
				link();

				mem(match, 0);
				mem(dst, 0);
				ll v = sz(ri) + sz(le);
				ll flow = hopcroftKarp();
				ll underdog = 2 + (v - flow);
				if (ans < underdog)
				{
					ans = underdog;
					champ.clear();
					champset.clear();
					champ.pb(i);
					champ.pb(j);
					FOR(i, 1, v + 1)
					{
						if (match[i] == 0)
						{
							champ.pb(m[i]);
							champset.insert(m[i]);
						}
					}

					FOR(i, 1, v + 1)
					{
						if (match[i] != 0)
						{
							bool can = true;
							for (auto it : banned[m[i]])
							{
								if (champset.find(it) != champset.end())
								{
									can = false;
									break;
								}
							}

							if (can)
							{
								champ.pb(m[i]);
								champset.insert(m[i]);
							}
						}
					}
				}

				d = old;
			}
		}
	}

	cout << ans << endl;

	sort(all(champ));
	FOR(i, 0, sz(champ))
		cout << champ[i] << " ";
	cout << endl;

	d = orig;
	FOR(i, 0, sz(champ))
	{
		FOR(j, i + 1, sz(champ))
		{
			if (dist(a[champ[i]], a[champ[j]]) > orig)
				cout << "OH OH " << champ[i] << " " << champ[j] << endl;
		}
	}

	return 0;
}

//======================================================================================================================