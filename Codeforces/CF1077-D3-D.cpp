#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Binary search on the answer, to check if m is possible, count the sum of cnt[i] / m where
// i is a number from 0 to 200000, and the result must be equal or greater than k.

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
ll a[200005], cnt[200005];
ll n, k;

bool check(ll m) {
	ll cum = 0;
	FOR(i, 0, 200005) {
		cum += (cnt[i] / m);
	}

	return cum >= k;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	cin >> n >> k;
	FOR(i, 0, n) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	ll l = 0, h = 200005;
	while (l < h) {
		ll m = ((h - l) >> 1) + l + 1;
		if (check(m))
			l = m;
		else
			h = m - 1;
	}

	ll cur = 0;
	FOR(i, 0, n) {
		if (cnt[a[i]] >= l) {
			cout << a[i] << " ";
			cnt[a[i]] -= l;
			cur++;
		}

		if (cur == k)
			break;
	}

	cout << endl;

	return 0;
}