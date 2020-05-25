#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	
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
	
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ii, ll>> viii;
	
#define MOD 1000000007
	
//----------------------------------------------------------------------------------------------------------------------
ll kmp(string s, string t) {
  vi ans;
  // Preprocess
  vi b(t.length()+1, 0); // Tabla para retroceder al encontrar desigualdad.
  int i = 0, j = -1;
  b[0] = -1;
  while(i < t.length()) {
    while(j >= 0 && t[i] != t[j]) j = b[j];
    i++; j++;
    b[i] = j;
  }

  // Busqueda
  i = 0; j = 0;
  while(i < s.length()) {
    while(j >= 0 && s[i] != t[j]) j = b[j];
    i++; j++;
  }
  return j;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	string s, t;
	ll n;
	cin >> n;
	t = "";
	FOR(i, 0, n) {
		cin >> s;
		ll hue = kmp(s.length() < t.length() ? t.substr(t.length() - s.length()) : t, s);
		t += s.substr(hue);
	}

	cout << t << endl;

	return 0;
}