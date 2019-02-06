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
ll arr[55];
ll dp[55][55][55];
ll n;

ll solve(ll i, ll x, ll cnt, ll k)
{
	if (i >= n)
	{
		if (cnt == 0)
			return 0;
		return x / cnt == k;
	}

	if (dp[i][x][cnt] != -1)
		return dp[i][x][cnt];

	ll ret = 0;
	ret += solve(i + 1, x ^ arr[i], cnt + 1, k) + solve(i + 1, x, cnt, k);

	return dp[i][x][cnt] = ret;
}

int main()
{
	cin >> n;

	FOR(i, 0, n)
		cin >> arr[i];

	for (ll i = 50; i >= 0; i--)
	{
		memset(dp, -1, sizeof(dp));
		ll x = solve(0, 0, 0, i);

		if (x != 0)
		{
			cout << x << endl;
			break;
		}
	}

	return 0;
}