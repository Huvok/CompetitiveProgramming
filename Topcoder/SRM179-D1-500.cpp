#include <bits/stdc++.h>

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// First for every pair of consecutive points, get their differences x and y. Get the gcd of both, so now the path is
// broken into g paths of x/g and y/g length, where both lengths are coprime. There are only two cases: both
// numbers are odd or one of them is 2. If one is 2, then this path passes over 0 corners, since the other
// number / 2 would be in a line, but not in a corner. If both are odds, in the middle of the path would be a corner,
// so the path passes over g corners.

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
class Regions {
public:
	ll gcd(ll a, ll b) {
		if (b) return gcd(b, a % b);
		return a;
	}
	int numTaxes(vector <int> row, vector <int> col) {
		ll ans = 0;
		FOR(i, 0, sz(row) - 1) {
			ll x = abs(col[i] - col[i + 1]);
			ll y = abs(row[i] - row[i + 1]);
			ll g = gcd(x, y);
			if (g == 0)
				continue;
			ans += x + y;
			x = x / g;
			y = y / g;
			if (x % 2 == 0 || y % 2 == 0)
				continue;
			ans -= g;
		}
		if (ans > 2e9)
			ans = -1;
		return ans;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	Regions g;
	vector<int> r ={0,1000000000,6}, c = {0,999999999,18};
	cout << g.numTaxes(r, c) << endl;

	return 0;
}

