#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <queue>
#include <bitset>
#include <sstream>
#include <set>
#include <iomanip>
#include <string.h>
#include <limits.h>
#include <iterator>

using namespace std;

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

typedef unsigned long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
map<ll, ll> m[500005];

//---------------------------------------------------------------------------------------------------------------------- 

int main() {
    sync;
	
    ll n;
    while (cin >> n) {
        if (n == 0) break;
        FOR(i, 0, n + 1)
            m[i].clear();

        ll left = 0;
        FOR(i, 0, n) {
            ll a, b;
            cin >> a >> b;
            if (m[a][b]) {
                left--;
                m[a][b]--;
            }
            else {
                m[b][a]++;
                left++;
            }
        }

        if (left == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

	return 0;
}