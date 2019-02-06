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

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

struct Point
{
	ll x, y;
	Point(ll X, ll Y) : x(X), y(Y) {}
	Point() {}

	bool operator <(Point b) const
	{
		return x < b.x;
	}
};

Point a[100005];

bool cmp(Point a, Point b)
{
	return a.y < b.y;
}

double dist(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double get(Point strip[], ll n, double d)
{
	double champ = d;

	sort(strip, strip + n, cmp);

	FOR(i, 0, n)
	{
		for (ll j = i + 1; j < n && (strip[j].y - strip[i].y) < champ; j++)
		{
			if (dist(strip[i], strip[j]) < champ)
				champ = dist(strip[i], strip[j]);
		}
	}

	return champ;
}

double oh(Point a[], ll n)
{
	double champ = 1e18;
	FOR(i, 0, n)
	{
		FOR(j, i + 1, n)
		{
			champ = min(champ, dist(a[i], a[j]));
		}
	}

	return champ;
}

Point strip[100005];

double solve(Point a[], ll n)
{
	if (n <= 3)
		return oh(a, n);

	ll m = n / 2;
	Point mid = a[m];

	double dl = solve(a, m);
	double dr = solve(a + m, n - m);

	double d = min(dl, dr);

	ll j = 0;
	FOR(i, 0, n)
	{
		if (abs(a[i].x - mid.x) < d)
		{
			strip[j] = a[i];
			j++;
		}
	}

	return min(d, get(strip, j, d));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll t;
	cin >> t;
	ll n;
	while (t--)
	{
		cin >> n;
		ll x, y;
		FOR(i, 0, n)
		{
			cin >> x >> y;
			a[i].x = x;
			a[i].y = y;
		}

		sort(a, a + n);
		cout << (ll)solve(a, n) << endl;
	}
	
	return 0;
}