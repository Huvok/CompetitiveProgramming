#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// From every substring you can make another substring, so if you iterate over the string s
// and you have the letter a, then it is possible to compress everything behind it and make a palindrome
// as long as you have more a's behind. So iterate over s, add one unit to the
// odd count and depending on which i you have (even or odd position) and the letter,
// add the count of characters you have processed (if current char is a, then you add the
// number of odd a's to the even count).

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

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	string s;
	cin >> s;

	ll e = 0, o = 0;
	ll ae = 0, ao = 0, be = 0, bo = 0;

	FOR(i, 0, sz(s)) {
		o++;

		if (i % 2 == 0) {
			if (s[i] == 'a') {
				o += ae;
				e += ao;
				ae++;
			}
			else {
				o += be;
				e += bo;
				be++;
			}
		}
		else {
			if (s[i] == 'a') {
				o += ao;
				e += ae;
				ao++;
			}
			else {
				o += bo;
				e += be;
				bo++;
			}
		}
	}

	cout << e << " " << o << endl;

	return 0;
}