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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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

bool stop = false;
ll champ = INT_MAX;
//----------------------------------------------------------------------------------------------------------------------
ll solve(ll n, ll a, ll b, ll c, ll cur)
{
	if (n == 4)
	{
		stop = true;
		champ = min(champ, cur);
		return 0LL;
	}
	else if (n > 4)
		n %= 4;

	if (stop &&
		cur >= champ)
		return INT_MAX;

	ll ans = 0LL;
	ans = solve(n + 1, a, b, c, cur + a) + a;
	ans = min(solve(n + 2, a, b, c, cur + b) + b, ans);
	ans = min(solve(n + 3, a, b, c, cur + c) + c, ans);

	return ans;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n, a, b, c;
	sc(n), sc(a), sc(b), sc(c);
	n %= 4;

	if (n == 0)
		n = 4;
	
	printf("%lld\n", solve(n, a, b, c, 0LL));

	return 0;
}

//======================================================================================================================