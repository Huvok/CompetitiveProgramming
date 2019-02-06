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

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }

const double EPS = .000000001;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
ll fastPow(ll x, ll n, ll m) 
{
	ll ret = 1;
	while (n) 
	{
		if (n & 1) 
			ret = ret * x % m;

		x = (x * x) % m;
		n >>= 1;
	}

	return ret;
}

ll solve(ll d, ll n, ll m)
{
	if (n == 1)
		return 1LL;
	if (n == 2)
		return 1LL + fastPow(10, d, m);

	if (n & 1)
	{
		return ((solve(d, n - 1, m) % m * fastPow(10, d, m)) % m + 1LL) % m;
	}
	else
	{
		return (solve(d, n / 2, m) % m * (fastPow(10, d * (n / 2), m) + 1LL)) % m;
	}
}

ll mod(string x, ll m)
{
	ll ret = 0;

	FOR(i, 0, sz(x))
		ret = (ret * 10 + (ll)x[i] - '0') % m;

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll k, r;
	string n;
	ll t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k >> r;
		k = solve(sz(n), k, r);
		printf("%lld\n", mod(n, r) * k % r);
	}

	return 0;
}

//======================================================================================================================