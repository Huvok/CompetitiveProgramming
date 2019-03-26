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
// For every node create a map of colors and counts, when considering two children (two maps)
// merge the smaller one into the bigger one (DSU principle, in the end its done in nlog2n);

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
ll c[100005];
vi adj[100005];
map<ll, ll> maps[100005];
ll ans[100005], cnt[100005];

void dfs(ll u, ll p) {
    cnt[u] = 1;
    ans[u] = c[u];
    maps[u][c[u]] = 1;
    for (auto v : adj[u]) {
        if (v == p)
            continue;

        dfs(v, u);

        if (maps[v].size() > maps[u].size()) {
            swap(maps[u], maps[v]);
            ans[u] = ans[v];
            cnt[u] = cnt[v];
        }
        
        for (auto it : maps[v]) {
            maps[u][it.first] += it.second;
            if (maps[u][it.first] == cnt[u])
                ans[u] += it.first;
            else if (maps[u][it.first] > cnt[u]) {
                cnt[u] = maps[u][it.first];
                ans[u] = it.first;
            }
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------- 

int main() {
    sync;
	
    ll n;
    cin >> n;
    FOR(i, 0, n)
        cin >> c[i + 1];

    FOR(i, 0, n - 1) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, -1);
       
    FOR(i, 0, n) {
        cout << ans[i + 1] << " ";
    }

    cout << endl;

	return 0;
}