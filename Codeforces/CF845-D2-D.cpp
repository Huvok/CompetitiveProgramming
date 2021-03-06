#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Maintain a stack of speed signs and a counter for the no overtaken allowed. If a new speed
// arrives, pop all that is below it. If a overtaken comes, add the counter to the answer and set it
// to zero.

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

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;
	ll ans = 0;
	stack<ll> s;
	ll overtake = 0;
	ll speed = 0;
	FOR(i, 0, n) {
		ll t;
		cin >> t;
		if (t == 1) {
			cin >> speed;
			while (!s.empty() && 
				speed > s.top()) {
				ans++;
				s.pop();
			}
		} 
		else if (t == 2) {
			ans += overtake;
			overtake = 0;
		}
		else if (t == 3) {
			ll x;
			cin  >> x;
			if (x >= speed)
				s.push(x);
			else
				ans++;
		}
		else if (t == 4) {
			overtake = 0;
		}
		else if (t == 5) {
			while (!s.empty())
				s.pop();
		}
		else {
			overtake++;
		}
	}

	cout << ans << endl;

	return 0;
}