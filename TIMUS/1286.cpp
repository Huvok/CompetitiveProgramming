#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// We must find if there are solutions to both equations p*x + q*y = n and p*x + q*y = m.
// First check if a solution is possible by getting the gcd(p, q) and checking if n and m are
// multiples of it. Divide everything by g. If so, due to the restrictions of the problem, (x + y) must be even since
// you always make two moves. If one of p or q is even and the other is odd, there is
// a solution since you can just advance one by one. If both are even or odd, then
// the only way for an answer to exist is if (n + m) is even where n is the diff of x and
// m the diff of y.

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
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
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

    ll p, q, x1, y1, x2, y2;
    cin >> p >> q >> x1 >> y1 >> x2 >> y2;

    ll x = abs(x2 - x1);
    ll y = abs(y2 - y1);

    ll g = __gcd(p, q);
    if (x % g != 0 || y % g != 0)
        cout << "NO" << endl;
    else {
        p /= g; q /= g; x /= g; y /= g;
        if (p % 2 + q % 2 == 1)
            cout << "YES" << endl;
        else if ((x + y) % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        return 0;
    }
}