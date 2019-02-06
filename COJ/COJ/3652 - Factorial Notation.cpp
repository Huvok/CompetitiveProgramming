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

ll a[50005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t;
	cin >> t;
	ll idx = 0;
	while (t--)
	{
		idx = 0;
		string str;
		cin >> str;
		mem(a, 0);
		string cur = "";
		bool getting = false;
		FOR(i, 0, sz(str))
		{
			if (str[i] == '(')
			{
				getting = true;
			}
			else if (str[i] == ')')
			{
				a[idx] = atoi(cur.c_str());
				cur = "";
				idx++;
				getting = false;
			}
			else if (getting)
				cur += str[i];
			else
			{
				a[idx++] = str[i] - '0';
			}
		}

		reverse(a, a + idx);

		if (a[0] == 1)
		{
			bool can = true;
			FOR(i, 1, 5000)
			{
				if (a[i])
					can = false;
			}

			if (can)
			{
				cout << 1 << endl;
				continue;
			}
		}

		if (a[1] == 1 &&
			!a[0])
		{
			bool can = true;
			FOR(i, 2, 5000)
			{
				if (a[i])
					can = false;
			}

			if (can)
			{
				cout << 1 << endl;
				continue;
			}
		}

		FOR(i, 0, 5000)
		{
			if (a[i] > 1)
			{
				if (a[i] % (i + 1) == 0)
				{
					a[i + 1] += a[i] / (i + 1);
					a[i] = 0;
				}
			}
		}

		bool can = true;
		ll cnt = 0;
		FOR(i, 0, 5000)
		{
			if (a[i] == 1)
				cnt++;
			else if (a[i] > 1)
				can = false;
		}

		if (can &&
			cnt == 1)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}