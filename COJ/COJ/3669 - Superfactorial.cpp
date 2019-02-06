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

ll solve(ll n)
{
	if (n <= 1)
		return n;
	return 2 * solve((n + 1) / 2 - 1) + (n + 1) / 2;
}

ll get(ll n)
{
	if (((n + 1) & n) == 0)
	{
		if (n <= 1)
			return solve(n);
	}
	else
	{
		ll ret = 1;
		while (ret - 1 <= n)
		{
			ret *= 2;
		}

		ret /= 2;
		return solve(ret - 1) + get(n - ret) + n - ret + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n;
	cin >> n;
	ll ans = n * (n + 1) / 2;
	ans -= get(n);

	cout << ans << endl;

	return 0;
}