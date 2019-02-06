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
	if (str[sz(str) - 2] == 'P')
	{
		ll x = atoi(str.substr(0, 2).c_str());
		if (x == 12)
			x = 12;
		else
			x += 12;
		str[0] = to_string(x)[0];
		str[1] = to_string(x)[1];
	}
	else
	{
		if (str[0] == '1' &&
			str[1] == '2')
		{
			str[0] = str[1] = '0';
		}
	}
	
	cout << str.substr(0, sz(str) - 2) << endl;

	return 0;
}