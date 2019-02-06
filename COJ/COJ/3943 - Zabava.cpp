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
ll a[105];
ll dp[105][505];

ll get(ll x, ll k)
{
	ll full = x / k;
	if (full == 0)
		return x;
	ll rem = x % k;
	ll ans = rem * (full + 1);
	ll sum = full * (full + 1) / 2;
	ans = k * sum + ans;
	return ans;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n, m, k;
	sc(n), sc(m), sc(k);
	ll x;
	FOR(i, 0, n)
	{
		sc(x);
		a[x]++;
	}

	FOR(i, 1, m + 1)
	{
		FOR(j, 0, k + 1)
		{
			dp[i][j] = INT_MAX;
			FOR(l, 0, j + 1)
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][l] + get(a[i], j - l + 1));
			}
		}
	}

	printf("%lld\n", dp[m][k]);

	return 0;
}

//======================================================================================================================