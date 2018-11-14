#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Multiply everything by 10 to get integers. Then we have the equation Ay + Bx = C and
// we want all solutions that pass over a multiple of ten, so we "shrink" everythin
// by multiplying A and B by 10. Now we want all the integral solutions of Ay + Bx = C over
// the segment delimited by the initial points coordinates.

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
ll extendedGcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }

    ll x1, y1;
    ll g = extendedGcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

bool diophantine(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = extendedGcd(abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shiftSolution(ll &x, ll &y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll findAllSolutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    if (a == 0) {
        if (b == 0 && c == 0)
            return (maxx - minx + 1) * (maxy - miny + 1);
        if (b == 0) return 0;
        if (c == 0) {
            if (miny <= 0 && maxy >= 0) return maxx - minx + 1;
            return 0;
        }
        if (c % b) return 0;
        ll x = c / b;
        if (miny <= x && maxy >= x) return maxx - minx + 1;
        return 0;
    }
    if (b == 0) {
        if (a == 0 && c == 0)
            return (maxx - minx + 1) * (maxy - miny + 1);
        if (a == 0) return 0;
        if (c == 0) {
            if (minx <= 0 && maxx >= 0) return maxy - miny + 1;
            return 0;
        }
        if (c % a) return 0;
        ll x = c / a;
        if (minx <= x && maxx >= x) return maxy - miny + 1;
        return 0;
    }
    
    ll x, y, g;
    if (!diophantine(a, b, c, x, y, g))
        return 0;
    a /= g; b /= g;

    ll signA = a > 0 ? 1 : -1;
    ll signB = b > 0 ? 1 : -1;

    shiftSolution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shiftSolution(x, y, a, b, signB);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    shiftSolution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shiftSolution(x, y, a, b, -signB);
    ll rx1 = x;

    shiftSolution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shiftSolution(x, y, a, b, -signA);
    if (y > maxy)
        return 0;
    ll lx2 = x;

    shiftSolution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shiftSolution(x, y, a, b, signA);
    ll rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if (lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
}

string get(string s) {
    string ret = "";
    FOR(i, 0, sz(s)) {
        if (s[i] != '.')
            ret += s[i];
    }

    return ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

    ll n;
    cin >> n;
    while (n--) {
        string a, b, c, d;
        cin >> a >> b >> c >> d;
        a = get(a), b = get(b), c = get(c), d = get(d);
        ll x1, x2, y1, y2;
        x1 = stoi(a), x2 = stoi(c), y1 = stoi(b), y2 = stoi(d);
        ll A = y2 - y1;
        ll B = x1 - x2;
        ll C = A * x1 + B * y1;
        A *= 10;
        B *= 10;
        ll minx = ceil(min(x1, x2) / 10.0);
        ll miny = ceil(min(y1, y2) / 10.0);
        ll maxx = floor(max(x1, x2) / 10.0);
        ll maxy = floor(max(y1, y2) / 10.0);
        cout << findAllSolutions(A, B, C, minx, maxx, miny, maxy) << endl;
    }

	return 0;
}