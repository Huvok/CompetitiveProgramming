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

ll l, m;
string n;

ll dp[300005][20][10];
ll ban[105][105];

ll solve(ll i, ll last, bool fix)
{
	if (last != -1 &&
		dp[i][last][fix] != -1)
		return dp[i][last][fix];

	if (i >= l)
		return 0;

	if (i == l - 1)
	{
		if (fix)
		{
			ll ret = 0;
			FOR(j, 0, n[i] - '0')
			{
				if (!ban[last][j])
				{
					ret += 1;
				}
			}

			if (!ban[last][n[i] - '0'])
			{
				ret += 1;
			}

			return dp[i][last][fix] = ret % 1000000007;
		}
		else
		{
			ll ret = 0;
			FOR(j, 0, 10)
			{
				if (!ban[last][j])
				{
					ret += 1;
				}
			}

			return dp[i][last][fix] = ret % 1000000007;
		}
	}

	if (fix)
	{
		ll ret = 0;
		FOR(j, 0, n[i] - '0')
		{
			if (last == -1 ||
				!ban[last][j])
			{
				ret += solve(i + 1, j, false) % 1000000007;
				ret %= 1000000007;
			}
		}

		if (last == -1 ||
			!ban[last][n[i] - '0'])
		{
			ret += solve(i + 1, n[i] - '0', true) % 1000000007;
			ret %= 1000000007;
		}

		return dp[i][last][fix] = ret % 1000000007;
	}
	else
	{
		ll ret = 0;
		FOR(j, 0, 10)
		{
			if (!ban[last][j])
			{
				ret += solve(i + 1, j, false) % 1000000007;
				ret %= 1000000007;
			}
		}

		return dp[i][last][fix] = ret % 1000000007;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> l >> n >> m;
	string x;
	mem(dp, -1);
	mem(ban, 0);
	FOR(i, 0, m)
	{
		cin >> x;
		ban[x[0] - '0'][x[1] - '0'] = 1;
	}

	cout << (solve(0, -1, true) - 1 + 1000000007 ) % 1000000007 << endl;

	return 0;
}