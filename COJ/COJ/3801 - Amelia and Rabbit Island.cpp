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

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll dp[1005];

int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, r1, r2;
		cin >> n >> r1 >> r2;
		dp[1] = r1, dp[2] = r2;
		for (ll i = 3; i <= n; i++)
		{
			dp[i] = dp[i - 1] * dp[i - 2];
			dp[i] %= 1000000;
		}

		cout << "At week " << (n - 1) * 3 + 1 << " we obtain " << dp[n] << " new rabbits." << endl;
	}

	return 0;
}