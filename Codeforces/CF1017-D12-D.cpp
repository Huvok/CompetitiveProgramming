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

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

using namespace std;

//                                          //AUTHOR: Hugo Garcia
// dp[i][j][k], for the ith bit we have the mask j that represents the count of numbers with limit k. The answer for
//		this state is the sum of i - 1, j and the ith bit toggled (the numbers don't match at this bit) and with the 
//      same j (the numbers match) but with k - w[i], because we get w[i] points from the matching.

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
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
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll w[15];
ll cnt[1LL << 13], dp[13][1LL << 13][105];
ll n, m, q;

ll get(string str)
{
	ll ret = 0;
	FOR(j, 0, n)
	{
		if (str[j] == '1')
			ret |= 1LL << j;
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;

	cin >> n >> m >> q;

	FOR(i, 0, n)
		cin >> w[i];

	FOR(i, 0, m)
	{
		string str;
		cin >> str;
		ll val = get(str);
		cnt[val]++;
	}

	for (ll i = n; i >= 0; i--)
	{
		FOR(j, 0, (1LL << n))
		{
			FOR(k, 0, 101)
			{
				if (i == n)
					dp[i][j][k] = cnt[j];
				else
					dp[i][j][k] = dp[i + 1][j ^ (1LL << i)][k] + (k >= w[i] ? dp[i + 1][j][k - w[i]] : 0);
			}
		}
	}

	FOR(i, 0, q)
	{
		string str;
		ll k;
		cin >> str >> k;
		ll val = get(str);
		cout << dp[0][val][k] << endl;
	}

	return 0;
}

//======================================================================================================================