#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// If k^d >= n, an answer exists. The answer for a student is the k base d digit number in order, just increment
// one by one for the next students.

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
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll prnt[1005][1005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, k, d;
	cin >> n >> k >> d;

	bool can = false;
	ll cur = k;

	FOR(i, , d) {
		if (cur >= n) {
			can = true;
			break;
		}

		cur *= k;
	}

	vi ans;
	FOR(i, 0, d) {
		ans.pb(1);
	}

	if (can) {
		FOR(i, 0, n) {
			FOR(j, 0, d) {
				prnt[j][i] = ans[j];
			}

			ROF(j, d - 1, 0) {
				ans[j]++;
				if (ans[j] <= k)
					break;

				ans[j] = 1;
			}
		}

		FOR(i, 0, d) {
			FOR(j, 0, n) {
				cout << prnt[i][j] << " ";
			}

			cout << endl;
		}
	}
	else
		cout << -1 << endl;

	return 0;
}

