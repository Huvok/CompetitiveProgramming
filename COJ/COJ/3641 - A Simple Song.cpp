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

ll dp[1005][1005];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string n, m;
	cin >> n >> m;

	FOR(i, 0, 1001)
	{
		FOR(j, 0, 1001)
		{
			dp[i][j] = 1e15;
		}
	}

	ll ans = 1e15;
	FOR(i, 0, n.length())
	{
		ll t = 1;
		FOR(j, 0, m.length() + 1)
		{
			dp[i % 2][j] = (dp[!(i % 2)][j] > t) ? t : dp[!(i % 2)][j];
			if (m[j] == n[i])
				t = dp[!(i % 2)][j] + 1;
			if (t > 1e14)
				break;
			if (j == m.size() &&
				ans > t)
				ans = t;
		}
	}

	cout << ans << endl;

	return 0;
}