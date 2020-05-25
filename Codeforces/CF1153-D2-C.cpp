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

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
	cin >> n;
	string str;
	cin >> str;

	if (n & 1) {
		cout << ":(" << endl;
		return 0;
	}

	ll open = 0, closed = 0, other = 0;
	FOR(i, 0, n) {
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
			closed++;
		else
			other++;
	}

	open = n / 2 - open;
	closed = n / 2 - closed;
	if (open < 0 || closed < 0) {
		cout << ":(" << endl;
		return 0;
	}

	ll cnt = 0;
	FOR(i, 0, n) {
		if (str[i] == '?') {
			if (open) {
				str[i] = '(';
				cnt++;
				open--;
			}
			else if (closed) {
				str[i] = ')';
				cnt--;
				closed--;
			}
		}
		else if (str[i] == '(')
			cnt++;
		else
			cnt--;
		
		if (cnt <= 0 && i < n - 1) {
			cout << ":(" << endl;
			return 0;
		}
	}

	cout << str << endl;

	return 0;
}