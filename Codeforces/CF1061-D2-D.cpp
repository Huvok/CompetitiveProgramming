#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// If you already had a TV that ended before the beginning of the show i, then it is always
// better to pick the TV that ended its show the closest to i. Assign a TV for every show
// then sort them by beginning, and for every show get the TV with the latest end,
// and if it is better to wait rather than to get another TV, do it.

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

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ii a[100005];
ll costs[100005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	
	ll n, x, y;
	cin >> n >> x >> y;
	set<iii> s;

	ll ans = 0;
	FOR(i, 0, n) {
		cin >> a[i].first >> a[i].second;
		s.insert(iii(ii(a[i].second, a[i].first), i));
	}

	sort(a, a + n);
	FOR(i, 0, n) {
		costs[i] = (a[i].second - a[i].first) * y;
		auto prev = s.lower_bound(iii(ii(a[i].first, 0), 0));
		if (prev == s.begin())
			continue;
		prev--;
		if ((a[i].first - prev->first.first) * y < x) {
			costs[i] = (a[i].second - prev->first.first) * y;
			s.erase(prev);
		}
	}

	FOR(i, 0, n) {
		ans = (ans + costs[i]) % MOD;
	}	

	ans = (ans + sz(s) * x) % MOD;

	cout << ans << endl;

	return 0;
}