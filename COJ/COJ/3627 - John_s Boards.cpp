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

#define MOD 1000000007

ll a(ll n)
{
	return n % MOD * (n + 1) % MOD * 500000004 % MOD;
}

ll b(ll n)
{
	return n % MOD * (n + 1)% MOD * (2 * n + 1) % MOD * 166666668 % MOD;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t;
	cin >> t;
	ll n;
	while (t--)
	{
		cin >> n;

		ll ans = 0;
		ans += b(n) * b(n) % MOD;
		ans %= MOD;
		ans -= b(n) * a(n) % MOD * n % MOD;
		ans += MOD;
		ans %= MOD;
		ans -= b(n) * a(n) % MOD * n % MOD;
		ans += MOD;
		ans %= MOD;
		ans += a(n) * a(n) % MOD * n % MOD * n % MOD;
		ans %= MOD;
		ans -= b(n) * a(n) % MOD;
		ans += MOD;
		ans %= MOD;
		ans -= b(n) * a(n) % MOD;
		ans += MOD;
		ans %= MOD;
		ans += 2 * a(n) * a(n) % MOD * n % MOD;
		ans %= MOD;
		ans += a(n) * a(n) % MOD;

		cout << ans % MOD << endl;
	}

	return 0;
}