#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Simulate it. A trick to make it shorter is to lowercase all characters.

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
bool isEqual(char a, char b) {
	if (a < 97 && a > 64)
		a += 32;
	if (b < 97 && b > 64)
		b += 32;
	if (a == '0' && b == 'o' ||
		a == 'o' && b == '0')
			return true;
	if (a == '1' && b == 'i' ||
		a == '1' && b == 'l' ||
		a == 'l' && b == '1' ||
		a == 'i' && b == '1' ||
		a == 'i' && b == 'l' ||
		a == 'l' && b == 'i')
		return true;
	return a == b;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	string str;
	cin >> str;
	ll n;
	cin >> n;
	ll t = n;
	ll cnt = 0;
	while (n--) {
		string nxt;
		cin >> nxt;
		if(sz(nxt) != sz(str)) {
			cnt++;
			continue;
		}
		bool cur = true;
		FOR(j, 0, sz(nxt)) {
			if (!isEqual(str[j], nxt[j]))
				cur = false;
		}

		if (cur == false)
			cnt++;
	}

	if (cnt == t)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}