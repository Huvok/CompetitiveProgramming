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
//                                          //IDEA: If we reflect the destination point over an edge, the final position
//                                          //      point's distance to the source point is the shortest distance
//                                          //      when touching this edge, so we can try all the possibilities of
//                                          //      reflection over all edges and take the shortest distance. This holds
//                                          //      for more than one edge since reflecting a point adds (or substracts)
//                                          //      distance in both axes accordingly to the reflection but this
//                                          //      distance can be discomposed individually into four reflections and
//                                          //      each of them applies some effect into the final answer i.e. solving
//                                          //      two (or more) reflections at the same time takes into consideration
//                                          //      the distance needed to accomplish both reflections if they were
//                                          //      solved individually. In the end, each reflection between parallel
//                                          //      edges adds or substracts 2 times the distance between the edges.

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
class Polyline
{
public:
	double dist(double x1, double y1, double x2, double y2)
	{
		x1 = abs(x1 - x2);
		x1 = x1 * x1;
		y1 = abs(y1 - y2);
		y1 = y1 * y1;
		return sqrt(x1 + y1);
	}

	double length(int a, int b, int x0, int y0, int x1, int y1)
	{
		double ret = 1e18;
		for (ll i = -2; i <= 2; i += 4)
		{
			for (ll j = -2; j <= 2; j += 4)
			{
				ret = min(ret, dist(x0, y0, x1 + a * i, y1 + b * j));
			}
		}

		return ret;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	 

	return 0;
}

//======================================================================================================================