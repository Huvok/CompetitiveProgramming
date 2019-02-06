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
pair<ii, ll> a[100005];
ll ends[100005];
ll dp[100005];

bool cmp(const pair<ii, ll> x, const ll y)
{
	return x.first.first <= y;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll t;
	sc(t);
	ll n;

	while (t--)
	{
		sc(n);
		FOR(i, 1, n + 1)
		{
			sc(a[i].first.second), sc(a[i].first.first), sc(a[i].second);
			a[i].first.first += a[i].first.second;
		}

		sort(a, a + n + 1);
		a[0] = {{-1, -1}, -1};
		dp[0] = 0;
		FOR(i, 1, n + 1)
		{
			auto it = lower_bound(a, a + n + 1, a[i].first.second, cmp) - a - 1;
			dp[i] = max(dp[i - 1], dp[it] + a[i].second);
		}

		printf("%lld\n", dp[n]);
	}

	return 0;
}

//======================================================================================================================