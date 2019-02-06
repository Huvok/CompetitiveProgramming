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
pair<double, double> a[10005];
ll n;

double dist(double x1, double x2, double y1, double y2)
{
	double x = abs(x1 - x2);
	double y = abs(y1 - y2);

	return sqrt(x * x + y * y);
}

double get(double i, pair<double, double> a)
{
	return max(dist(i - .5, a.first, 0, a.second), dist(i + .5, a.first, 0, a.second));
}

double check(double m)
{
	double ret = 0;
	FOR(i, 0, n)
	{
		ret = max(ret, get(m, a[i]));
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;

	FOR(i, 0, n)
	{
		cin >> a[i].first >> a[i].second;
	}

	sort(a, a + n);
	double l = a[0].first - 1;
	double r = a[n - 1].first + 1;
	double m;
	FOR(k, 0, 400)
	{
		m = (r + l) / 2;
		double a = check(m + .0000001);
		double b = check(m - .0000001);
		if (a > b)
			r = m;
		else
			l = m;
	}

	cout << fixed << setprecision(6) << check(m) << '\n';

	return 0;
}

//======================================================================================================================