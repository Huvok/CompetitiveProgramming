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

ll dp[3005][3005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str;
	cin >> str;
	FOR(i, 0, sz(str))
		dp[i][i] = 1;

	FOR(i, 1, sz(str))
	{
		dp[i - 1][i] = 1;
	}

	FOR(j, 2, sz(str))
	{
		FOR(i, 0, sz(str) - j)
		{
			if (dp[i + 1][j + i - 1] &&
				str[i] + str[j + i] == str[i + 1] + str[j + i - 1])
				dp[i][j + i] = 1;
		}
	}

	FOR(i, 0, sz(str))
	{
		FOR(j, 1, sz(str))
		{
			dp[i][j] += dp[i][j - 1];
		}
	}

	FOR(j, 0, sz(str))
	{
		FOR(i, 1, sz(str))
		{
			dp[i][j] += dp[i - 1][j];
		}
	}

	ll q;
	cin >> q;
	ll l, r;
	FOR(i, 0, q)
	{
		cin >> l >> r;
		if (r < l)
		{
			swap(l, r);
		}
		ll sum = 0;
		sum += dp[r][r];
		if (l > 0)
		{
			sum -= dp[l - 1][r];
			sum -= dp[r][l - 1];
			sum += dp[l - 1][l - 1];
		}

		cout << sum << endl;
	}

	return 0;
}