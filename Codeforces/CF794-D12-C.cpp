#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Sort the strings in non-descending and non-ascending. Take the ceil(n/2) and floor(n/2) characters.
// Then greedily take the smallest or biggest letter depending on whose turn it is. The only extra case
// is when the first player's smallest character is not strictly smaller than the second's
// biggest character, in that case you should put that letter in the last available position.

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

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	
	string a, b;
	cin >> a >> b;
	sort(all(a));
	sort(all(b), greater<char>());

	ll l = 0, r = sz(a) - 1;
	ll n = sz(a);
	string ans = a;
	a = a.substr(0, (n + 1) / 2);
	b = b.substr(0, n / 2);
	ll pa = 0, pb = 0;
	FOR(i, 0, n) {
		if (i % 2 == 0) {
			if (a[pa] < b[pb]) {
				ans[l] = a[pa];
				pa++; l++;
			}
			else {
				ans[r] = a.back();
				a.pop_back(); r--;	
			}
		}
		else {
			if (a[pa] < b[pb]) {
				ans[l] = b[pb];
				pb++; l++;
			}
			else {
				ans[r] = b.back();
				b.pop_back(); r--;
			}
		}
	}

	cout << ans << endl;

	return 0;
}