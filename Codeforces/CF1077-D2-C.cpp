#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Calculate the sum of everything, then iterate over all elements. The current sum is sum - a[i].
// if cur is even, then you can split it and it must be less or equal than 1e6 and also it
// must appear in the sequence (if it is the same as a[i], it must appear at least twice).

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
ll a[200005];
ll cnt[1000005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;
	ll sum = 0;
	mem(cnt, 0);
	FOR(i, 0, n) {
		cin >> a[i];
		sum += a[i];
		cnt[a[i]]++;
	}
	vi ans;
	FOR(i, 0, n) {
		ll cur = sum - a[i];
		cnt[a[i]]--;
		if (cur % 2 == 0 && cur / 2 <= 1e6 && cnt[cur / 2] > 0)
			ans.pb(i + 1);
		cnt[a[i]]++;
	}

	cout << sz(ans) << endl;
	for (ll i : ans)
		cout << i << " ";

	return 0;
}