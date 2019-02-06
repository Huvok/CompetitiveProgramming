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
double dist(ll x1, ll y1, ll x2, ll y2)
{
	x1 = abs(x1 - x2);
	x1 *= x1;
	y1 = abs(y1 - y2);
	y1 *= y1;
	return sqrt(x1 + y1);
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll x1, x2, y1, y2, r1, r2;
	ll n;
	cin >> n;
	while (n--)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (r1 < r2)
		{
			swap(x1, x2);
			swap(y1, y2);
			swap(r1, r2);
		}

		if (abs(dist(x1, y1, x2, y2) - (r1 + r2)) < 1e-9)
			cout << "TANGENT EXT" << endl;
		else if (dist(x1, y1, x2, y2) > r1 + r2)
			cout << "EXT" << endl;
		else if (x1 == x2 &&
			y1 == y2 &&
			r1 == r2)
			cout << "SAME" << endl;
		else if (abs(dist(x1, y1, x2, y2) + r2 - r1) < 1e-9)
			cout << "TANGENT INT" << endl;
		else if (dist(x1, y1, x2, y2) < r1 - r2)
			cout << "INT" << endl;
		else
			cout << "SEC" << endl;
	}

	return 0;
}