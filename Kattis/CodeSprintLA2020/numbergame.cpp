#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
//                                                          // AUTHOR: Hugo
//                                                          Garcia
 
#define FOR(i, a, b) for (ll i = ll(a); i < ll(b); i++)
#define ROF(i, a, b) for (ll i = ll(a); i >= ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define lld I64d
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
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
ll vis[200005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
  sync;
 
  ll n, m;
  cin >> n >> m;
  
  queue<ii> q;
  q.push(ii(n, 0));
  ll ans = -1;
  
  while (!q.empty()) {
    ii u = q.front();
    q.pop();
    if (vis[u.first])
        continue;
    
    if (u.first == m) {
        ans = u.second;
        break;
    }
    
    vis[u.first] = 1;
    if (u.first + 1 <= 2 * m) {
        q.push(ii(u.first + 1, u.second + 1));
    }
    if (u.first - 1 >= 0) {
        q.push(ii(u.first - 1, u.second + 1));
    }
    if (u.first * 2 <= 2 * m) {
        q.push(ii(u.first * 2, u.second + 1));
    }
  }
  
  cout << ans << endl;
 
  return 0;
}
