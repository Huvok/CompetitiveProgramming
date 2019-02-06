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

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

#define PI 3.1415926535897932384626433832795

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int main()
{
	ll t;
	cin >> t;
	cout << fixed << setprecision(3);
	while (t--)
	{
		double r, a, b, c;
		cin >> r >> a >> b;
		c = 180 - a - b;

		a = a * PI / 180;
		b = b * PI / 180;
		c = c * PI / 180;

		cout << 2 * r * r * sin(a) * sin(a) * sin(a) * sin(b) / sin(c) << " square units" << endl;
	}

	return 0;
}