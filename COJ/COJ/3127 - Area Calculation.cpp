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

//----------------------------------------------------------------------------------------------------------------------
double ans[100005];
ll cnt[100005];

ll get(ll x)
{
	ll cnt = 0;
	while (x > 0)
	{
		cnt++;
		x /= 10;
	}

	return cnt;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll t;
	sc(t);
	ans[0] = sqrt(18) * PI;
	cnt[0] = 2;
	ans[0] /= 10;

	FOR(i, 1, 100001)
	{
		ans[i] = ans[i - 1] * 3 / 2;
		cnt[i] = cnt[i - 1];
		if (ans[i] > 10 - EPS)
		{
			ans[i] /= 10;
			cnt[i]++;
		}
	}

	ll i = 1;
	while (t--)
	{
		ll x;
		sc(x);

		cout << "Case " << i << ": " << cnt[x] << endl;
		i++;
	}

	return 0;
}

//======================================================================================================================