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

ll a[30];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		string str;
		cin >> n;
		cin >> str;
		mem(a, 0);
		FOR(i, 0, sz(str))
		{
			a[str[i] - 'A']++;
		}

		string x = "", y = "";
		FOR(i, 0, 28)
		{
			while (a[i] > 1)
			{
				a[i] -= 2;
				x += (char)(i + 'A');
				y = (char)(i + 'A') + y;
			}
		}

		FOR(i, 0, 28)
		{
			if (a[i] > 0)
			{
				x += (char)(i + 'A');
				break;
			}
		}

		cout << x << y << endl;
	}

	return 0;
}