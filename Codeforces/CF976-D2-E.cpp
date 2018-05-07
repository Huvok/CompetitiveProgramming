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
//                                          //IDEA: The best way to handle spell a is to evolve a single monster a
//                                          //      times (1LL << a) so lets calculate the answer when not using any
//                                          //      spell, then sort by hp - dmg since those will be the best options
//                                          //      for spell 2, then recalculate the answer taking those that sum to
//                                          //      more to your answer (the positive ones) and finally iterate for
//                                          //      every monster. If it is inside the b first ones, take out its
//                                          //      unevolved answer and take the evolved one, otherwise make the same
//                                          //      but taking out the arr[b - 1] answer.

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
#define oo 100000000000000000

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ii arr[200005];

bool cmp(ii a, ii b)
{
	return a.first - a.second > b.first - b.second;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n, a, b;
	cin >> n >> a >> b;

	ll sum = 0;
	FOR(i, 0, n)
	{
		cin >> arr[i].first >> arr[i].second;
		sum += arr[i].second;
	}

	sort(arr, arr + n, cmp);

	FOR(i, 0, b)
	{
		if (arr[i].first > arr[i].second)
		{
			sum -= arr[i].second;
			sum += arr[i].first;
		}
	}

	ll ans = sum;
	FOR(i, 0, n)
	{
		ll improve = (1LL << a) * arr[i].first;

		if (i < b ||
			!b)
		{
			ans = max(ans, sum - max(b ? arr[i].first : 0LL, arr[i].second) + (b ? improve : arr[i].second));
		}
		else
		{
			ans = max(ans, sum - (arr[b - 1].first > arr[b - 1].second ? arr[b - 1].first : arr[b - 1].second) + arr[b - 1].second + improve - arr[i].second);
		}
	}

	cout << ans << endl;

	return 0;
}

//======================================================================================================================