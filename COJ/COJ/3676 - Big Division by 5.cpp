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
	string s;
	ll t;
	cin >> t;

	FOR(j, 1, t + 1)
	{
		cin >> s;

		char st = s[0];
		ll r = 0;
		ll l = sz(s);

		for (ll i = l - 1; i >= 0; i--) 
		{
			ll d = s[i] - '0';
			d *= 2;
			d += r;

			if (d > 9) 
			{
				r = d / 10;
				d %= 10;
			}
			else
			{
				r = 0;
			}

			s[i] = d + '0';
		}

		cout << "Case " << j << ": ";

		if (r > 0)
		{
			cout << (char)('0' + r);
		}

		FOR(i, 0, l - 1)
		{
			cout << s[i];
		}

		if (l == 1 && st <= '4')
			cout << 0;

		if (s[l - 1] != '0') 
		{
			cout << ",";
			cout << s[l - 1];
		}

		if (j != t)
			cout << "\n";
	}

	return 0;
}