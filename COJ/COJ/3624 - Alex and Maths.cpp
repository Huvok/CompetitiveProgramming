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

ll dp[105][105][25];
ll a[105];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, k, r;
	cin >> n >> k >> r;
	FOR(i, 0, n)
		cin >> a[i];

	FOR(i, 0, n)
	{
		dp[i][1][a[i] % r] = 1;
	}

	FOR(j, 2, k + 1)
	{
		FOR(i, j - 1, n)
		{
			FOR(l, 0, r)
			{
				ll ret = 0;
				FOR(x, 0, i)
				{
					ret += dp[x][j - 1][l];
					ret %= 1000000009;
				}
				dp[i][j][(l + a[i]) % r] += ret;
				dp[i][j][(l + a[i]) % r] %= 1000000009;
			}
		}
	}

	ll ans = 0;
	FOR(i, 0, n)
	{
		ans += dp[i][k][0];
		ans %= 1000000009;
	}

	cout << ans << endl;

	return 0;
}