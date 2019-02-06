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
#include <cassert>

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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string str;
	cin >> str;
	ll r = 0;
	ll rep;
	ll ans = sz(str);
	FOR(l, r + 1, sz(str))
	{
		rep = l % (r + 1);
		if (str[rep] != str[l])
		{
			r = l;
			continue;
		}

		if (l == sz(str) - 1)
		{
			ans = r + 1;
		}
	}

	if (sz(str) % ans != 0)
		ans = sz(str);

	if (sz(str) == ans)
		ans = 0;
	cout << ans << endl;
	
	return 0;
}