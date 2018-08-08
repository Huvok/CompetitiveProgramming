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
//                                          //IDEA: dp[i] is the loss for the first i billboards. From the last k + 1
//                                          //      we have to pick one of them to prevent having more than k together,
//                                          //      so we take the one with the minimum value and the amount we are
//                                          //      losing dp[j - 1] + value[j] if we take off the jth billboard. We use
//                                          //      a deque to maintain the minimum element in our window.

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
#define oo 100000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll a[100005];
ll dp[100005];
ll n, k;

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	cin >> n >> k;
	ll s = 0;
	FOR(i, 1, n + 1)
	{
		cin >> a[i];
		s += a[i];
	}

	deque<ii> dq;
	mem(dp, 0);
	FOR(i, 1, n + 1)
	{
		while (!dq.empty() &&
			dq.back().second < i - k)
			dq.pop_back();

		ll candidate = a[i] + dp[i - 1];
		while (!dq.empty() &&
			dq.front().first >= candidate)
			dq.pop_front();

		dq.push_front(ii(candidate, i));

		if (i > k)
			dp[i] = a[dq.back().second] + dp[dq.back().second - 1];
	}

	cout << s - dp[n] << endl;

	return 0;
}

//======================================================================================================================