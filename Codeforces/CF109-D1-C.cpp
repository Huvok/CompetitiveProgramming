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
#  define __builtin_popcountll __popcnt64
#endif

using namespace std;

//                                          //AUTHOR: Hugo Garcia
// Calculate cnt[i], count of nodes of subtree i, dp1[i], number of nodes in subtree of i that you can reach passing at least one
// lucky edge from i, dp2[i], the same but now for outside of subtree i.
// if edge to a child j is lucky, dp1[i] += cnt[j] because you can reach everything. If not, dp1[i] = dp[j] because you
// can reach the same nodes (if any). For dp2[i], if edge to parent p is lucky, dp2[i] = cnt[1] (root) - cnt[i], because
// you can reach the whole three outside of subtree i. If not lucky, dp2[i] = dp2[p] + dp1[p] - dp1[i], its like saying
// that you can reach the same nodes outside of subtree p, but also those valid for subtree p, but you are counting those
// on subtree i, since i is son of p, so you need to substract them.

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

#define MOD 998244353

//----------------------------------------------------------------------------------------------------------------------
unordered_set<ll> lucky;
void precalc(ll i) {
	if (i > 1e9)
		return;
	lucky.insert(i);
	precalc(i * 10 + 4);
	precalc(i * 10 + 7);
}

vii adj[100005];
ll cnt[100005], dp1[100005], dp2[100005];

void dfs(ll i, ll p) {
	cnt[i]++;
	FOR(j, 0, sz(adj[i])) {
		ii v = adj[i][j];
		if (v.first != p) {
			dfs(v.first, i);
			cnt[i] += cnt[v.first];

			if (lucky.find(v.second) != lucky.end())
				dp1[i] += cnt[v.first];
			else
				dp1[i] += dp1[v.first];
		}
	}
}

void dfs2(ll i, ll p, ll w) {
	if (lucky.find(w) != lucky.end())
		dp2[i] = cnt[1] - cnt[i];
	else
		dp2[i] = dp2[p] + dp1[p] - dp1[i];

	FOR(j, 0, sz(adj[i])) {
		ii v = adj[i][j];
		if (v.first != p) {
			dfs2(v.first, i, v.second);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	
	precalc(4);
	precalc(7);
	ll n;
	cin >> n;
	FOR(i, 0, n - 1) {
		ll s, d, w;
		cin >> s >> d >> w;
		adj[s].pb(ii(d, w));
		adj[d].pb(ii(s, w));
	}

	dfs(1, 0);
	dfs2(1, 0, 4);

	ll ans = 0;
	FOR(i, 1, n + 1) {
		ans += dp1[i] * (dp1[i] - 1) + dp2[i] * (dp2[i] - 1) + dp1[i] * dp2[i] * 2;
	}

	cout << ans << endl;

	return 0;
}