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
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a) - 1; i>=ll(b); i--)
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
double a[1005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll m;
	cin >> m;
	FOR(i, 1, m + 1)
	{
		cin >> a[i];
	}
	sort(a + 1, a + m + 1);
	vector<double> le, ri;
	FOR(i, 1, m / 2 + 1)
		le.pb(a[i]);

	double q1, q2, q3, qr;
	if (m & 1)
		q2 = a[(m + 1) / 2];
	else
		q2 = (a[m / 2] + a[m / 2 + 1]) / 2;

	FOR(i, (m + 1) / 2 + 1, m + 1)
		ri.pb(a[i]);

	if (sz(le) & 1)
	{
		q1 = le[(sz(le) + 1) / 2 - 1];
	}
	else
	{
		q1 = (le[sz(le) / 2 - 1] + le[sz(le) / 2 + 1 - 1]) / 2;
	}

	if (sz(ri) & 1)
	{
		q3 = ri[(sz(ri) + 1) / 2 - 1];
	}
	else
	{
		q3 = (ri[sz(ri) / 2 - 1] + ri[sz(ri) / 2 + 1 - 1]) / 2;
	}

	qr = abs(q3 - q1);

	ll ans = 0;
	FOR(i, 1, m + 1)
	{
		if (a[i] > q3 + 1.5 * qr ||
			a[i] < q1 - 1.5 * qr)
			ans++;
	}

	cout << ans << endl;

	return 0;
}