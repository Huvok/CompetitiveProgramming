#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// Try every row and column size and take the best. To distribute asterisks, the count of them
// is i * j - sz(str) where i is row and j is column. Distribute them evenly and then split the string
// to match i and j.

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
string getPart(string &s, ll n) {
	string ret = "";
	if (s.size() < n) {
		ret = s;
		s = "";
	}
	else {
		ret = s.substr(0, n);
		s = s.substr(n);
	}

	return ret;
}

bool check(vector<string> ans) {
	ll prev, cur = 0;
	prev = 0;
	FOR(i, 0, sz(ans)) {
		FOR(j, 0, sz(ans[i])) {
			if (ans[i][j] == '*')
				cur++;
		}

		if (i) {
			if (abs(prev - cur) > 1)
				return false;
		}

		prev = cur;
		cur = 0;
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	string cur = "";
	string str;
	cin >> str;
	if (str.size() <= 20) {
		cout << 1 << " " << str.size() << endl;
		cout << str << endl;
		return 0;

	}
	vector<string> ans(500);
	FOR(i, 1, 6) {
		FOR(j, 1, 21) {
			if (sz(str) <= i * j) {
				ll dif = i * j - sz(str);
				vector<string> cand;
				string aux = str;
				FOR(k, 0, i)
					cand.pb("");
				ll cur = 0;
				while (dif > 0) {
					cand[cur] += '*';
					dif--;
					cur++;
					cur %= i;
				}

				FOR(k, 0, i) {
					cand[k] += getPart(aux, j - sz(cand[k]));
				}

				ans = cand;
				i = 50, j = 50;
				break;
			}
		}
	}

	cout << ans.size() << " " << ans[0].size() << endl;
	FOR(i, 0, sz(ans)) {
		cout << ans[i] << endl;
	}
	

	return 0;
}