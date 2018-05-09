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
//                                          //IDEA: Simulate the process as stated in the problem statement but
//                                          //      just store the last row, since it is the only one necessary to
//                                          //      construct the following ones.

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
ll a[15][15];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	while (true)
	{
		ll n;
		cin >> n;

		if (!n)
			break;

		FOR(i, 0, n)
			cin >> a[0][i];

		FOR(i, 1, n)
		{
			FOR(j, 0, n - i)
			{
				a[i][j] = a[i - 1][j + 1] - a[i - 1][j];
			}
		}

		vi cur;
		FOR(i, 0, n)
		{
			cur.pb(a[i][n - 1 - i]);
		}

		reverse(all(cur));

		ll k;
		cin >> k;
		vi nxt;
		FOR(i, 0, k)
		{
			FOR(j, 0, sz(cur))
			{
				if (!j)
					nxt.pb(cur[0]);
				else
				{
					nxt.pb(nxt.back() + cur[j]);
				}
			}

			swap(nxt, cur);
			nxt.clear();
		}

		cout << "Term " << k + n << " of the sequence is " << cur.back() << endl;
	}

	return 0;
}

//======================================================================================================================