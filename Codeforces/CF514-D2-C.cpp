#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Create a Trie and traverse it using dfs, just maintain a counter to see how many times you have changed a char.

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

#define MOD 998244353

//----------------------------------------------------------------------------------------------------------------------
ll Trie[500002][3];
ll root, cnt = 0;
ll en[500002][3];
string str;

void addTrie(string str) {
	ll i, v = root;
	FOR(i, 0, sz(str)) {
		if (!Trie[v][str[i] - 'a'])
			Trie[v][str[i] - 'a'] = ++cnt;
		
		if (i == sz(str) - 1)
			en[v][str[i] - 'a'] = 1;
		
		v = Trie[v][str[i] - 'a'];
	}
}

bool dfs(ll i, ll v, ll cnt, bool x) {
	if (i == str.size()) {
		if (x && cnt == 1)
			return true;
		else
			return false;
	}

	ll val;
	FOR(j, 0, 3) {
		val = cnt;
		if (!Trie[v][j])
			continue;
		if ((j + 'a') != str[i])
			val++;
		if (cnt < 2) {
			x = en[v][j];
			if (dfs(i + 1, Trie[v][j], val, x))
				return true;
		}
	}

	return false;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, m;
	cin >> n >> m;
	FOR(i, 0, n) {
		cin >> str;
		addTrie(str);
	}

	while (m--) {
		cin >> str;
		if (dfs(0, 0, 0, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}