#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Convert the permutations into their factoradic form and sum the factoradics. Then
// appply the modulo, and finally transform back to the permutation.

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
ll a[200005], b[200005];
ordered_set<ll> s;
ll fac[200005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n;
    cin >> n;
    FOR(i, 0, n) {
        cin >> a[i];
        s.insert(a[i]);
    }

    FOR(i, 0, n) {
        fac[i] += s.order_of_key(a[i]);
        s.erase(a[i]);
    }

    FOR(i, 0, n) {
        cin >> b[i];
        s.insert(b[i]);
    }

    FOR(i, 0, n) {
        fac[i] += s.order_of_key(b[i]);
        s.erase(b[i]);
    }

    ROF(i, n - 1, 0) {
        if (i) {
            fac[i - 1] += (fac[i] / (n - i));
        }

        fac[i] %= (n - i);
    }

    FOR(i, 0, n) {
        s.insert(i);
    }

    FOR(i, 0, n) {
        auto x = *s.find_by_order(fac[i]);
        cout << x << " ";
        s.erase(x);
    }

    cout << endl;

	return 0;
}