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
//                                          //IDEA: We can start with the pair (x, 1) which takes one step. We want to
//                                          //      find the number p = (x) * q + 1, since the pair (p, x) would take
//                                          //      three steps, and we can generalize this to more steps. Now we have
//                                          //      the constraint of only using 1, 0 or -1. We can just take modulo 2
//                                          //      since the q in the equation above will always be x or -x, which
//                                          //      will maintain everything in the range [1, 1] but, for simplicity,
//                                          //      we always take q as x and then take modulo 2, simulating the choice
//                                          //      between x and -x.

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

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n;
	cin >> n;

	vi a, b;

	a.pb(0);
	a.pb(1);
	b.pb(1);

	vi c;
	FOR(i, 2, n + 1)
	{
		c.clear();
		c.pb(0);
		FOR(j, 0, sz(a))
		{
			c.pb(a[j]);
		}

		FOR(j, 0, sz(b))
		{
			c[j] = (c[j] + b[j]) % 2;
		}

		swap(a, b);
		swap(a, c);
	}

	cout << sz(a) - 1 << endl;
	FOR(i, 0, sz(a))
		cout << a[i] << " ";
	cout << endl << sz(b) - 1 << endl;
	FOR(i, 0, sz(b))
		cout << b[i] << " ";

	return 0;
}

//======================================================================================================================