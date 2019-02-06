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

ll dp[1000005];

int main()
{
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;

	FOR(i, 3, 1000001)
	{
		dp[i] = ((dp[i - 1] * (i - 1) % 1000000007) + (dp[i - 2] * (i - 2) % 1000000007)) % 1000000007;
	}

	ll t;
	scanf("%lld", &t);

	while (t--)
	{
		ll n;
		scanf("%lld", &n);
		printf("%lld\n", dp[n]);
	}

	return 0;
}