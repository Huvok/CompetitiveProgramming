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
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <iterator>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a) - 1; i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

string nine_decompose(ll n) {
	string ans = "";
	while (n > 9) {
		ans += "9";
		n -= 9;
	}
	ans += char(n+'0');
	return ans;
}

string combine(string u, string l) {
	if (u.length() > l.length() + 1) {
		l += "0";
	}
	string ans = "";
	FOR(i, 0, sz(u)) {
		ans += u[i];
		if (i < sz(l)) {
			ans += l[i];
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll n;
	while (true)
	{
		cin >> n;
		if (!n)
			break;

		string ans = "";
		if (n & 1)
		{
			if (n < 11) {
				ans = "-1";
				cout << ans << endl;
				continue;
			}
			ll lower = (n - 11) / 2, upper = (n + 11) / 2;
			string l = nine_decompose(lower), u = nine_decompose(upper);
			ans = combine(u, l);
		}
		else
		{
			ll lower = (n) / 2;
			string l = nine_decompose(lower);
			ans = combine(l, l);
		}
		cout << ans << endl;
	}

	return 0;
}