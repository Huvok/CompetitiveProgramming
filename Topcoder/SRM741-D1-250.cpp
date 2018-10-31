#include <bits/stdc++.h>

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// dp[i][j][k] is answer for first ith digits of string a, we have taken j digits in total and k = 0 if the first i digits of the answer were
// strictly less than X, k = 1 if its equal and 2 if is greater. If k = 0, our only option is to take or ignore and keep k = 0. If
// its 1, we can keep the 1, if the new digit is greater change to 2, or change to 0 if its less. If its 2, we keep the 2.
// Also always check if the current digit is different than zero or we have taken at least one digit. Finally, the base case
// is when we run out of digits on S. If the final k is 0 or 1, the number of digits taken, j, must be greater than
// the size of X to be valid. If k is 2, it must be greater or equal.

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
class DigitStringDiv1 {
public:
	ll dp[50][50][3];
	ll solve(string a, string b, ll i, ll j, ll p) {
		if (i >= sz(a)) {
			if (p == 0 || p == 1)
				return j > sz(b);
			else
				return j >= sz(b);
		}

		if (dp[i][j][p] != -1)
			return dp[i][j][p];
		ll ans = 0;
		if (p == 0) {
			if (j > 0 || a[i] != '0')
				ans += solve(a, b, i + 1, j + 1, 0);
		}
		else if (p == 1) {
			if (j > 0 || a[i] != '0') {
				if (j < sz(b) && a[i] > b[j])
					ans += solve(a, b, i + 1, j + 1, 2);
				else if (j < sz(b) && a[i] == b[j])
					ans += solve(a, b, i + 1, j + 1, 1);
				else
					ans += solve(a, b, i + 1, j + 1, 0);
			}
		}
		else {
			ans += solve(a, b, i + 1, j + 1, 2);
		}

		ans += solve(a, b, i + 1, j, p);
		return dp[i][j][p] = ans;
	}

	long long count(string S, int X) {
		string hue = to_string(X);
		mem(dp, -1);
		return solve(S, hue, 0, 0, 1);
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	DigitStringDiv1  d;
	cout << d.count("101", 9);


	return 0;
}

