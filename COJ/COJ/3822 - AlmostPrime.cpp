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
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define mem(x, val) memset((x), (val), sizeof(x))
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

const double EPS = .000000001;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

ll gcd(ll a, ll b) 
{
	if (b) 
		return gcd(b, a % b);
	return a;
}

bool prime[80005];
void sieve()
{
	mem(prime, true);
	prime[0] = prime[1] = false;
	FOR(i, 2, 80001)
	{
		if (prime[i])
		{
			for (ll j = i * 2; j < 80001; j += i)
				prime[j] = false;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n;
	cin >> n;
	ll ans = 0;
	sieve();
	FOR(i, 2, n + 1)
	{
		ll x = gcd(n, i);
		if (prime[x])
			ans++;
	}

	cout << ans << endl;

	return 0;
}