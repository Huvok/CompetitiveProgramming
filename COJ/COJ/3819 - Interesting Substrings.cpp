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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()

const double EPS = .000000001;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MAX_N 200010
ll T[200010];
ll n;
ll RA[MAX_N], tempRA[MAX_N];
ii SA[MAX_N], tempSA[MAX_N];
ll c[MAX_N];

void countingSort(ll k)
{
	ll sum, maxi = max(2000LL, n);
	mem(c, 0);

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
	sync;
	ll r;
	ll cur = 1;
	FOR(i, 0, n)
	{
		RA[i] = T[i];
		SA[i] = mp(i, cur);
		if (T[i] < 1000)
			cur++;
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

ll ans[1005];
ll szt;

ll check(ll a, ll b)
{
	ll cnt = 1;
	while (a < szt &&
		b < szt &&
		T[a] > 999 &&
		T[b] > 999 &&
		T[a] == T[b])
	{
		cnt++;
		a++;
		b++;
	}

	if (T[a] < 1000)
		return -1;

	return cnt;
}

ll Phi[200010], PLCP[200010], LCP[200010];

void getLCP()
{
	ll i, L;
	Phi[SA[0].first] = -1;
	for (i = 1; i < n; i++)
	{
		Phi[SA[i].first] = SA[i - 1].first;
	}

	for (i = L = 0; i < n; i++)
	{
		if (Phi[i] == -1)
		{
			PLCP[i] = 0;
			continue;
		}

		while (T[i + L] == T[Phi[i] + L] &&
			T[i + L] != '$')
			L++;

		PLCP[i] = L;
		L = max(L - 1, 0LL);
	}

	for (i = 0; i < n; i++)
		LCP[i] = PLCP[SA[i].first];
}

void solve(ll l, ll r, ll level)
{
	if (l > r)
		return;
	bool same = true;
	for (ll i = l; i < r; i++)
	{
		if (SA[i].second != SA[i + 1].second)
		{
			same = false; break;
		}
	}

	if (same)
		ans[SA[l].second] = min(ans[SA[l].second], level + 1);
	else
	{
		while (l <= r &&
			T[SA[l].first + level + 1] < 1000)
		{
			l++;
		}

		ll prev = l;
		for (ll i = l + 1; i <= r; i++)
		{
			if (LCP[i] == level + 1)
			{
				solve(prev, i - 1, level + 1);
				prev = i;
			}
		}

		solve(prev, r, level + 1);
	}
}


int main()
{
	ll t;
	cin >> t;

	string str;
	vector<string> v;
	ll dif = 999;
	szt = 0;
	FOR(i, 0, t)
	{
		cin >> str;
		v.pb(str);
		FOR(j, 0, sz(str))
		{
			T[szt] = (ll)str[j] + 1000;
			szt++;
		}

		T[szt] = dif;
		dif--;
		szt++;
	}

	n = szt;

	constructSA();
	getLCP();

	FOR(i, 0, t)
		ans[i + 1] = sz(v[i]) + 1;

	ll prev = t;
	FOR(i, t + 1, n)
	{
		if (LCP[i] == 0)
		{
			solve(prev, i - 1, 0);
			prev = i;
		}
	}

	solve(prev, n - 1, 0);

	if (t == 1)
		ans[1] = 1;
	FOR(i, 1, t + 1)
	{
		cout << ans[i] << endl;
	}

	/*FOR(i, 0, sz(v))
	{
	ll mini = INT_MAX;
	FOR(j, 0, sz(v[i]))
	{
	FOR(k, j, sz(v[i]))
	{
	bool can = true;
	str = v[i].substr(j, k - j + 1);
	FOR(l, 0, sz(v))
	{
	if (l == i)
	continue;

	if (v[l].find(str) != string::npos)
	{
	can = false;
	break;
	}
	}

	if (can)
	mini = min(mini, k - j + 1);
	}
	}

	if (mini != ans[i + 1])
	cout << "YEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEES ";
	cout << mini << " - " << ans[i + 1] << endl;
	}
	*/
	return 0;
}