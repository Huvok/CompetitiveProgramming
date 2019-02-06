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

ll oc[1005];
ll cy[1005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll a, c, m, x;

	while (cin >> a >> c >> m >> x)
	{
		ll cur = 1;
		mem(oc, 0);
		mem(cy, 0);

		oc[x] = 1;
		while (true)
		{
			x = (a * x + c) % m;
			if (oc[x] != 0)
			{
				cy[x] = 1;
				oc[x]++;
				break;
			}

			oc[x]++;
			cur++;
		}

		while (true)
		{
			x = (a * x + c) % m;
			if (cy[x] != 0)
			{
				break;
			}

			oc[x]++;
			cy[x]++;
		}

		if (cur >= m)
			cout << "YES ";
		else
			cout << "NO ";

		cout << cur << " ";
		cur = 0;
		FOR(i, 0, 1001)
		{
			if (oc[i] == 1)
				cur++;
		}

		cout << cur << " ";
		cur = 0;
		FOR(i, 0, 1001)
		{
			if (cy[i] == 1)
				cur++;
		}

		cout << cur << endl;
	}

	return 0;
}