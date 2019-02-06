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
ll n;
#define MOD 1000000007
ll g[20];
ll dp[1LL << 20];
ll cnt[1LL << 20];
ll prod[1LL << 20];

ll count(ll x)
{
	ll cnt = 0;
	FOR(i, 0, 20)
	{
		if ((x >> i) & 1LL)
			cnt++;
	}

	return cnt;
}

ll prods(ll x)
{
	ll ret = 1;
	FOR(i, 0, 20)
	{
		if ((x >> i) & 1LL)
			ret = ret * g[i] % MOD;
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	mem(dp, -1);
	sc(n);
	readarr(g, n);
	FOR(i, 0, (1LL << n))
		dp[i] = 1e15;

	FOR(i, 0, n)
	{
		dp[1LL << i] = g[i];
	}

	FOR(i, 1, (1LL << n))
	{
		cnt[i] = count(i);
		prod[i] = prods(i);
		if (cnt[i] == 1)
			prod[i] = 0;
	}

	FOR(mask, 0, (1LL << n))
	{
		if (cnt[mask] == 1)
			continue;

		for (ll i = (mask - 1) & mask; i > 0; i = (i - 1) & mask)
		{
			ll comp = (1LL << 20) - 1;
			comp = ~i & comp;
			comp &= mask;
			dp[mask] = min(dp[mask], dp[i] + dp[comp] + prod[i] * cnt[i] + prod[comp] * cnt[comp]);
		}
	}

	if (n == 1)
		dp[(1LL << n) - 1] = 0;
	printf("%lld\n", dp[(1LL << n) - 1]);

	return 0;
}

//======================================================================================================================