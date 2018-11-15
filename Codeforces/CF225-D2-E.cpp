#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Expand the equations by replacig x by 2k and (2k + 1) and you will see that z must be a
// power of 2 and z * 2 - 1 must be prime i.e. marsenne.

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
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ii, ll>> viii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll val[42] = {0,2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,2203,2281,3217,4253,
			4423,9689,9941,11213,19937,21701,23209,44497,86243,110503,132049,216091,756839,
			859433,1257787,1398269,2976221,3021377,6972593,13466917,20996011,24036583};
//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	
	ll n;
	cin >> n;
	ll pot = val[n];
	ll ans = 1;
	FOR(i, 0, pot - 1)
		ans = ans * 2 % MOD;

	ans = (ans - 1 + MOD) % MOD;
	cout << ans << endl;

	return 0;
}