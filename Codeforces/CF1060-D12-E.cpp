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
// Calculate the sum of the paths in the original tree, which is done by: for each edge between u and v, node on side of
//    u * nodes on side of v. For every path of even length, the new sum is sum / 2, and for odd lengths it is (sum + 1) / 2.
//    Now just count the number of paths of odd length, which is done by multiplying the number of nodes in an odd level *
//    number of nodes in an even level. Finally, the answer is (s + o) / 2. s is the original sum and o the number of
//    paths of odd length.

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
vi adj[200005];
bool vis[200005];
ll cnt[200005];
ll n;
ll evenL = 0, oddL = 0;

ll countChildren(ll i) {
	vis[i] = true;
	ll ret = 1;

	FOR(j, 0, sz(adj[i])) {
		ll v = adj[i][j];
		if (!vis[v]) {
			ret += countChildren(v);
		}
	}

	cnt[i] = ret;
	return ret;
}

ll getSum(ll i) {
	vis[i] = true;
	ll ret = 0;

	FOR(j, 0, sz(adj[i])) {
		ll v = adj[i][j];
		if (!vis[v]) {
			ret += cnt[v] * (n - cnt[v]);
			ret += getSum(v);
		}
	}

	return ret;
}

void getParities(ll i, ll l) {
	vis[i] = true;
	if (l % 2 == 0)
		evenL++;
	else
		oddL++;

	FOR(j, 0, sz(adj[i])) {
		ll v = adj[i][j];
		if (!vis[v]) {
			getParities(v, l + 1);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;

	cin >> n;

	FOR(i, 0, n - 1) {
		ll s, d;
		cin >> s >> d;
		adj[s].pb(d);
		adj[d].pb(s);
	}

	countChildren(1);
	mem(vis, false);
	ll s = getSum(1);
	mem(vis, false);
	getParities(1, 0);
	
	s += (evenL * oddL);
	cout << s / 2 << endl;

	return 0;
}

//======================================================================================================================