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

vii factors;

void getFactors(ll n)
{
	factors.clear();
	ll step = 1;
	for (ll i = 2; i * i <= n; i += step, step = 2)
	{
		if (n % i == 0)
		{
			factors.pb(mp(i, 0));
			while (n % i == 0)
			{
				n /= i;
				factors.back().second++;
			}
		}
	}

	if (n != 1)
		factors.pb(mp(n, 1));
}

vi divisors;
void getDivisors(ll idx = 0, ll res = 1)
{
	if (idx == sz(factors))
	{
		divisors.pb(res);
		return;
	}

	FOR(i, 0, factors[idx].second + 1)
	{
		getDivisors(idx + 1, res);
		res *= factors[idx].first;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		divisors.clear();
		getFactors(n);
		getDivisors();

		ll p = 0, i = 0;
		FOR(j, 0, sz(divisors))
		{
			if (divisors[j] & 1)
				i++;
			else
				p++;
		}

		cout << "P: " << p << " I: " << i << endl;
	}

	return 0;
}