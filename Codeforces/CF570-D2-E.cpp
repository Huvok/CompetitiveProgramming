#include <bits/stdc++.h>

using namespace std;

// dp[i][j][k][l] is the number of ways to reach from cell i,j to k,l. Of course
// those two cells must be equal and you must check all four possibilities of movement:
// i+1,j - k-1,l, i,j+1 - k-1,l, i+1,j - k,l-1, i,j+1, k,l-1.
// This is almost trivial, but to fit in time you must reconstruct l from the other three,
// since the distance from 1,1 to i,j must be equal to the distance of n,m to k,l.
// Also, you must use one less dimension of memory using the fact that you only use the "last layer".


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

typedef int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
char mat[505][505];
ll dp[2][505][505];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll ans = 0;
	ll n, m;
	cin >> n >> m;
	FOR(i, 1, n + 1) {
		string str;
		cin >> str;
		FOR(j, 1, m + 1) {
			mat[i][j] = str[j - 1];
		}
	}

	if (mat[1][1] == mat[n][m])
		dp[1][1][n] = 1;

	ll b = 0;
	FOR(i, 1, n + 1) {
		for (ll j = 1; (i + j) * 2 <= n + m + 2; j++) {
			FOR(k, i, n + 1) {
				ll l = n + m - i - j - k + 2;
				if (mat[i][j] == mat[k][l] && i <= k && j <= l) {
					// upper to left, lower to right
					dp[b][j][k] = (dp[b][j][k] + dp[b][j - 1][k]) % MOD;
					// upper to left, lower to down
					dp[b][j][k] = (dp[b][j][k] + dp[b][j - 1][k + 1]) % MOD;
					// upper to up, lower to right
					dp[b][j][k] = (dp[b][j][k] + dp[1 - b][j][k]) % MOD;
					// upper to up, lower to down
					dp[b][j][k] = (dp[b][j][k] + dp[1 - b][j][k + 1]) % MOD;
				}

				if (k - i + l - j <= 1)
					ans = (ans + dp[b][j][k]) % MOD;
			}
		}

		mem(dp[1 - b], 0);
		b = 1 - b;
	}

	cout << ans << endl;

	return 0;
}

