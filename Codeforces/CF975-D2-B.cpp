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

//                                          //AUTHOR: Hugo Garcia
//                                          //IDEA: Complete the first cycle if possible, then calculate all the stones
//                                          //      a hole will get with divisions and modulos. Repeat for every hole.

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

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll a[15];
ll aux[15];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	FOR(i, 0, 14)
	{
		cin >> a[i];
	}

	ll ans = 0;
	FOR(i, 0, 14)
	{
		ll cnt = 0;
		FOR(k, 0, 14)
		{
			aux[k] = a[k];
		}

		aux[i] = 0;
		ll left = a[i];
		FOR(k, i + 1, 14)
		{
			if (left <= 0)
				break;
			aux[k]++;
			left--;
		}

		ll x = left / 14;
		FOR(k, 0, 14)
		{
			aux[k] += x;
		}

		left -= x * 14;

		ll idx = 0;
		while (left > 0)
		{
			aux[idx]++;
			left--;
			idx++;
		}

		FOR(k, 0, 14)
		{
			if (aux[k] % 2 == 0)
				cnt += aux[k];
		}

		ans = max(ans, cnt);
	}

	cout << ans << endl;

	return 0;
}

//======================================================================================================================