#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Count the number of 1's and 0's in range. The answer is 2^c1 - 1 + 2^c0 * offset, where
// offset is the sum of the first powers of 2.

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
ll ones[100005], zeros[100005];
ll cums[100005];
ll cums2[100005];
ll sum[100005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	//sync;

    ll n, q;
	cin >> n >> q;
	string str;
	cin >> str;
	cums[0] = 0;
	cums[1] = 1;
	cums2[1] = 1;
	FOR(i, 2, 100005) {
		cums[i] = cums[i - 1] * 2 % MOD;
	}
	sum[0] = 1;
	FOR(i, 1, 100005) {
		sum[i] = sum[i - 1] * 2 % MOD;
		cums2[i] = cums[i + 1] - 1;
	}
	FOR(i, 1, 100005) {
		cums[i] = (cums[i] + cums[i - 1]) %MOD;
		sum[i] = (sum[i - 1] + sum[i]) % MOD;
	}
	mem(ones, 0);
	mem(zeros, 0);
	FOR(i, 0, sz(str)) {
		if (str[i] == '1')
			ones[i] = 1;
		else
			zeros[i] = 1;
	}

	FOR(i, 1, sz(str)) {
		ones[i] += ones[i - 1];
		zeros[i] += zeros[i - 1];
	}


	FOR(i, 0, q) {
		ll l, r;
		cin >> l >> r;
		l--; r--;
		ll a = ones[r];
		if (l)
			a -= ones[l - 1];
		ll b = zeros[r];
		if (l)
			b -= zeros[l - 1];
		ll ans = cums[a] % MOD;
		ll nxt = cums2[a];
		if (b) ans += sum[b - 1] * nxt % MOD;
		ans %= MOD;
		ans = (ans + MOD) % MOD;
		
		cout << ans << endl;
	}

	return 0;
}