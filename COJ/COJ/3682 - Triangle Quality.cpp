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
	ll n;
	cin >> n;
	while (n--)
	{
		double a, b, c;
		cin >> a >> b >> c;
		double ans = ((b + c - a) * (a + b - c) * (c + a - b)) / (a * b * c);
		if (ans >= 1 - 1e-9 &&
			ans <= 1 + 1e-9)
			cout << "equilateral" << endl;
		else if (ans > .5 && ans <= 1)
			cout << "good" << endl;
		else
			cout << "bad" << endl;
	}

	return 0;
}