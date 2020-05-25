#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	
//                                                          // AUTHOR: Hugo Garcia
	
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
ll a[100005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	
	ll n, m, k;
	cin >> n >> m >> k;

	FOR(i, 0, m)
		cin >> a[i];

	ll ans = 0;
	ll nxt = 0;
	ll cur = 0;
	ll cnt = 0;
	if (a[nxt] - cur > k) {
		cur = a[nxt] - (a[nxt] - cur - 1) % k;
	}
	while (nxt < m) {
		if (a[nxt] - cur <= k) {
			nxt++;
			cnt++;
		} else {
			ans++;
			cur = cur + cnt;
			cnt = 0;
			if (a[nxt] - cur > k) {
				cur = a[nxt] - (a[nxt] - cur - 1) % k - 1;
			}
		}
	}

	if (a[nxt - 1] - cur > 0)
		ans++;

	cout << ans << endl;
	
	return 0;
}