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
#include <complex>

using namespace std;

//															//AUTHOR: Hugo Garcia
// Calculate the value from 0 to k, then each period (n / k) the value changes in (b / a) ^ k, so calculate this and
//      the answer is the value from 0 to k times the ratio ^ p, where p is the number of periods. Check for a = b = 1.

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
#define debug(...) fprintf(stderr, VA_ARGS), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll arr[100005];
#define MOD 1000000009

ll fastPow(ll x, ll n)
{
	ll ret = 1;
	while (n)
	{
		if (n & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n, a, b, k;
	cin >> n >> a >> b >> k;

	string str;
	cin >> str;
	FOR(i, 0, k)
	{
		if (str[i] == '+')
			arr[i] = 1;
		else
			arr[i] = -1;
	}

	ll periods = (n + 1) / k;
	ll periodVal = 0;
	ll invA = fastPow(a, MOD - 2);
	FOR(i, 0, k)
		periodVal = (periodVal + (arr[i] % MOD * fastPow(a, n - i) % MOD * fastPow(b, i) % MOD) + MOD) % MOD;

	ll ans = 0;
	ll change = fastPow(b, k) % MOD * fastPow(invA, k) % MOD;

	ll invCool = fastPow(change - 1, MOD - 2);

	ll hue = (fastPow(change, periods) - 1 + MOD) % MOD;
	if (change == 1)
		ans = periods % MOD;
	else
		ans = (fastPow(change, periods) - 1 + MOD) % MOD * invCool % MOD;

	ans = ans * periodVal % MOD;

	cout << ans << endl;

	return 0;
}