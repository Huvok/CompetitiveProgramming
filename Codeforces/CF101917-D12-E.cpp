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
// Convert the angle to radians and apply the rotation to the polygon. Then imagine it has a bounding box
//      with left border on the most negative x, right border on rightest x and so on. You have to translate this
//      box and scale it to the original one.

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
#define sz(x) (ll)(x).size()
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
struct point {
	double x, y;
};

point arr[100005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll a, w, h, n;
	cin >> a >> w >> h >> n;
	FOR(i, 0, n)
		cin >> arr[i].x >> arr[i].y;

	double rad = a * PI / 180;
	FOR(i, 0, n) {
		double aux = sin(rad) * arr[i].x + cos(rad) * arr[i].y;
		arr[i].x = cos(rad) * arr[i].x - sin(rad) * arr[i].y;
		arr[i].y = aux;
	}

	double lx = oo, ly = oo, hx = -oo, hy = -oo;
	FOR(i, 0, n) {
		lx = min(lx, arr[i].x);
		ly = min(ly, arr[i].y);
		hx = max(hx, arr[i].x);
		hy = max(hy, arr[i].y);
	}

	double scalex = w / (hx - lx);
	double scaley = h / (hy - ly);
	FOR(i, 0, n) {
		arr[i].x = (arr[i].x - lx) * scalex;
		arr[i].y = (arr[i].y - ly) * scaley;
	}

	cout << fixed << setprecision(10);
	FOR(i, 0, n)
		cout << arr[i].x << " " << arr[i].y << endl;

	return 0;
}

//======================================================================================================================