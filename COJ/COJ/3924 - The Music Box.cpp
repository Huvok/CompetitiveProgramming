#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <queue>
#include <string.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <unordered_set>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
#define MAX_N 100010
string T;
ll n;
ll RA[MAX_N], tempRA[MAX_N];
ii SA[MAX_N], tempSA[MAX_N];
ll c[MAX_N];
ll k, m;

void countingSort(ll k)
{
	ll sum, maxi = max(300LL, n);
	memset(c, 0, sizeof(c));

	FOR(i, 0, n)
		c[i + k < n ? RA[i + k] : 0]++;

	for (ll i = sum = 0; i < maxi; i++)
	{
		ll t = c[i];
		c[i] = sum;
		sum += t;
	}

	FOR(i, 0, n)
		tempSA[c[SA[i].first + k < n ? RA[SA[i].first + k] : 0]++] = SA[i];

	FOR(i, 0, n)
		SA[i] = tempSA[i];
}

void constructSA()
{
	ll r;
	ll idx = 0;
	FOR(i, 0, n)
	{
		RA[i] = T[i];
		SA[i] = mp(i, idx < k ? 1 : 2);
		if (T[i] == '$')
			idx++;
	}

	for (ll k = 1; k < n; k <<= 1)
	{
		countingSort(k);
		countingSort(0);
		tempRA[SA[0].first] = r = 0;

		FOR(i, 1, n)
		{
			tempRA[SA[i].first] = (RA[SA[i].first] == RA[SA[i - 1].first] &&
				RA[SA[i].first + k] == RA[SA[i - 1].first + k]) ? r : ++r;
		}

		FOR(i, 0, n)
			RA[i] = tempRA[i];

		if (RA[SA[n - 1].first] == n - 1)
			break;
	}
}

ll check(ll i, ll j)
{
	ll ans = 0;
	while (T[i] != '$' &&
		T[j] != '$')
	{
		if (T[i] != T[j])
			return ans;
		ans++;

		i++; j++;
	}

	return ans;
}

string get(ll i, ll j)
{
	string ret = "";
	while (T[i] != '$' &&
		T[j] != '$')
	{
		if (T[i] != T[j])
		{
			ret += T[i];
			return ret;
		}

		ret += T[i];
		i++; j++;
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> k >> m;

	string str;
	unordered_set<ll> s;
	FOR(i, 0, k)
	{
		s.insert(T.length());
		cin >> str;
		T += str;
		T += "$";
	}

	FOR(i, 0, m)
	{
		s.insert(T.length());
		cin >> str;
		T += str;
		T += "$";
	}

	n = T.length();

	constructSA();

	vii v;
	FOR(i, 0, n)
	{
		if (s.find(SA[i].first) != s.end())
			v.push_back(SA[i]);
	}

	unordered_set<string> strs;
	ll ans = 0;
	FOR(i, 0, v.size())
	{
		ll x = -1, y = -1;
		if (v[i].second == 2)
			continue;
		for (ll j = i - 1; j >= 0; j--)
		{
			if (v[i].second != v[j].second)
			{
				x = j;
				break;
			}
		}

		FOR(j, i + 1, v.size())
		{
			if (v[i].second != v[j].second)
			{
				y = j;
				break;
			}
		}

		ll a = -1, b = -1;
		if (x != -1)
			a = check(v[i].first, v[x].first);
		if (y != -1)
			b = check(v[i].first, v[y].first);

		if (a > b)
		{
			strs.insert(get(v[i].first, v[x].first));
		}
		else
		{
			strs.insert(get(v[i].first, v[y].first));
		}
	}

	for (auto it : strs)
	{
		ans += it.length();
	}

	cout << ans << '\n';

	return 0;
}

//======================================================================================================================