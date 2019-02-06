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

ll fast(ll N) {
	getFactors(N);
	vi powers(32, 0LL);
	FOR(i, 0, sz(factors)) {
		powers[factors[i].second]++;
	}
	ll sum = 0;
	ROF(i, 32, 0) {
		sum += powers[i];
		powers[i] = sum;
	}
	ll power = 2;
	ll result = 0LL;
	while (power < sz(powers) &&
		powers[power]) {
		result += (1LL << (powers[power])) - 1LL;
		power++;
	}
	return result;
}

ll brute(ll n) {
	ll ans = 0;
	FOR(i, 2, n+1) {
		if (n%i == 0) {
			getFactors(i);
			ll power = 100;
			for (auto factor : factors) {
				power = min(power, factor.second);
			}
			if (power > 1) {
				bool possible = true;
				for (auto factor : factors) {
					if (factor.second % power != 0) possible = false;
				}
				if (possible) ans++;
			}
		}
	}
	return ans;
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
unordered_set<ll> s;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll T;
	cin >> T;
	/*FOR(i, 1, 1000000) {
		cout << i << ": brute = " << brute(i) << ", fast = " << fast(i) << endl;
		assert(fast(i) == brute(i));
	}*/

	FOR(i, 2, sqrt(1000000009) + 1)
	{
		ll cur = i * i;
		while (cur <= 1000000009)
		{
			s.insert(cur);
			cur *= i;
		}
	}

	while (T--) {
		ll N;
		cin >> N;
		getFactors(N);
		divisors.clear();
		getDivisors();
		//ll result = brute(N);
		//assert(result == brute(N));

		ll result = 0;
		FOR(i, 0, sz(divisors))
		{
			if (s.find(divisors[i]) != s.end())
				result++;
		}
		cout << result << endl;
	}
	return 0;
}