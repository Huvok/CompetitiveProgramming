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
//                                          //IDEA: The ghosts will collide when their x and y coordinates are the same.
//                                          //      Solve for Tx => TxVix + Xi = TxVjx + Xj, gives 
//                                          //      Tx = (Xj - Xi) / (Vix - Vjx). Now solve for Ty =>
//                                          //      TyViy + aXi + b = TyVjy + aXj + b, gives
//                                          //      Ty = a(Xj - Xi) / (Viy - Vjy). Tx and Ty are the times when 
//                                          //      ghosts i and j will have the same x and y coordinates. If both
//                                          //      times are equal, there will be a collision. Tx = Ty, replace with
//                                          //      equations from above and the answer is aVix - Viy = aVjx - Vjy,
//                                          //      so store in a map how many ghosts have each value and when
//                                          //      another ghost with aVx - Vy comes, add the number of collisions it
//                                          //      will be involved into (map[aVx - Vy]) and substract the number
//                                          //      of parallel ghosts there are (anotherMap[{Vx, Vy}]). For every
//                                          //      collision, you should add another one to the answer (one collision
//                                          //      generates two answer points).

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
map<ll, ll> vals;
map<ii, ll> same;

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n, a, b;
	cin >> n >> a >> b;

	ll ans = 0;
	ll x, vx, vy;
	FOR(i, 0, n)
	{
		cin >> x >> vx >> vy;

		ans += vals[a * vx - vy];
		vals[a * vx - vy]++;

		ans -= same[ii(vx, vy)];
		same[ii(vx, vy)]++;
	}

	cout << ans * 2 << endl;

	return 0;
}

//======================================================================================================================