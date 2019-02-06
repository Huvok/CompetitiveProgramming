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
ll a[200005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	double ans = 0;
	double avg = 0;
	FOR(i, 0, m)
	{
		cin >> a[i];
		avg += a[i];
	}

	avg /= n;
	while (m < n * 2)
	{
		m++;
		a[m - 1] = 0;
	}

	sort(a, a + m);

	FOR(i, 0, n)
	{
		ans += abs((a[i] + a[m - 1 - i]) - avg);
	}

	cout << fixed << setprecision(5) << ans << endl;

	return 0;
}