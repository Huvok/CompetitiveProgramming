#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Create an array with all possible numbers, sorted. Binary search the answer element.
// Let say you are searching for k, then to check if it is valid, greate a grid of all zeros,
// and traverse row by row. If the current element is >= k, put it into a vector.
// Then iterate over all pairs in that vector, if you had already seen it then your answer is possible,
// if not, put it into a map or something (in my case a matrix). 


#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define lld I64d
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ii, ll>> viii;

#define MOD 998244353

//----------------------------------------------------------------------------------------------------------------------
ll a[1005][1005];
ll val[1000005];
ll good[1005][1005];
ll n, m;

bool check(ll mid) {
	mem(good, 0);
	FOR(k, 0, n) {
		vi p;
		FOR(i, 0, m) {
			if (a[k][i] >= mid)
				p.pb(i);
		}

		FOR(i, 0, sz(p)) {
			FOR(j, i + 1, sz(p)) {
				if (good[p[i]][p[j]])
					return true;
				good[p[i]][p[j]] = 1;
			}
		}
	}

	return false;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	cin >> n >> m;

	ll k = 0;
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			cin >> a[i][j];
			val[k++] = a[i][j];
		}
	}

	sort(val, val + k);

	ll ans = 0;
	ll l = 0, r = k - 1;
	while (l < r) {
		ll mid = (l + r) / 2 + 1;
		if (check(val[mid]))
			l = mid;
		else
			r = mid - 1;
	}

	cout << val[l] << endl;

	return 0;
}