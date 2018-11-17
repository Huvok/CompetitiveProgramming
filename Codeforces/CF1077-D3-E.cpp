#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// First compress everything up to 200000, then sort the counts of the topics.
// Lets try every possible value from 1 to the maximum count of the topics. Lets say
// the current value is x, and iterate from the end of the sorted array. If the position to
// the left is less or equal than x / 2 and x is even, we can start from there with x / 2 problems.
// Repeat, this will execute up to log x steps.

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
map<ll, ll> m;
ll cnt[200005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> a[i];
		m[a[i]] = -1;
	}

	ll cur = 0;
	for (auto it : m) {
		m[it.first] = cur;
		cur++;
	}

	FOR(i, 0, n) {
		a[i] = m[a[i]];
		cnt[a[i]]++;
	}

	sort(cnt, cnt + cur);
	ll champ = 0;
	FOR(i, 1, cnt[cur - 1] + 1) {
		ll seek = i;
		ll r = cur - 2;
		ll ans = seek;
		while (r >= 0 && seek % 2 == 0) {
			seek /= 2;
			if (cnt[r] < seek) break;
			ans += seek;
			r--;
		}

		champ = max(champ, ans);
	}

	cout << champ << endl;

	return 0;
}