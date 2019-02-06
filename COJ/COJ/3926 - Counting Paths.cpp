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
ll getPot(ll k)
{
	unsigned long long cur = 1;
	ll ans = 0;

	while (cur <= k)
	{
		ans++;
		cur *= 2;
	}

	return ans - 1;
}

vi adj[5000];
ll dp[5000];

ll dfs(ll i, ll cur, ll target, ll d)
{
	if (i == d)
	{
		if (cur < target)
			cout << "ERROR" << '\n';
		return cur == target;
	}

	if (dp[i] != -1)
		return dp[i];

	ll ans = 0;
	FOR(j, 0, adj[i].size())
	{
		ans += dfs(adj[i][j], cur + 1, target, d);
	}

	return dp[i] = ans;
}

ll fastPow(ll x, ll n)
{
	ll ret = 1;
	while (n) {
		if (n & 1) ret = ret * x;
		x = x * x;
		n >>= 1;
	}
	return ret;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll k;
	cin >> k;

	if (k == 1)
	{
		cout << "2 1" << '\n' << "1 2" << '\n' << "1 2" << '\n';
		return 0;
	}
	else if (k == 2)
	{
		cout << "2 2" << '\n' << "1 2" << '\n' << "1 2" << '\n' << "1 2" << '\n';
		return 0;
	}

	vii v;
	ll init = getPot(k);
	ll idx = 2;
	ll s = 1, d = init + 1;
	ll prev;
	ll idxes[55];
	memset(idxes, -1, sizeof(idxes));
	while (k > 0)
	{
		ll x = getPot(k);
		k -= fastPow(2, x);
		prev = 1;
		FOR(i, 0, init)
		{
			if (i < init - x)
			{
				if (init - x > 50 &&
					i == 0 &&
					idxes[50] != -1)
				{
					prev = idxes[50];
					i = 50;
				}
				else if (init - x > 40 &&
					i == 0 &&
					idxes[40] != -1)
				{
					prev = idxes[40];
					i = 40;
				}
				else if (init - x > 30 &&
					i == 0 &&
					idxes[30] != -1)
				{
					prev = idxes[30];
					i = 30;
				}
				else if (init - x > 20 &&
					i == 0 &&
					idxes[20] != -1)
				{
					prev = idxes[20];
					i = 20;
				}
				else if (init - x > 10 &&
					i == 0 &&
					idxes[10] != -1)
				{
					prev = idxes[10];
					i = 10;
				}

				if (i == 20 &&
					idxes[20] == -1)
					idxes[20] = prev;

				if (i == 10 &&
					idxes[10] == -1)
					idxes[10] = prev;

				if (i == 30 &&
					idxes[30] == -1)
					idxes[30] = prev;

				if (i == 40 &&
					idxes[40] == -1)
					idxes[40] = prev;

				if (i == 50 &&
					idxes[50] == -1)
					idxes[50] = prev;

				if (i == init - x - 1)
				{
					v.pb(mp(prev, i + 2));
					break;
				}
				else
					v.pb(mp(prev, idx));
				prev = idx;
				idx++;
			}
			else if (i == init - 1)
			{
				v.pb(mp(prev, d));
				v.pb(mp(prev, d));
				if (d == idx)
					idx++;
			}
			else
			{
				v.pb(mp(prev, idx));
				v.pb(mp(prev, idx));
				prev = idx;
				idx++;
			}
		}
	}

	cout << max(idx - 1, d) << " " << v.size() << '\n';
	cout << s << " " << d << '\n';
	memset(dp, -1, sizeof(dp));
	FOR(i, 0, v.size())
	{
		cout << v[i].first << " " << v[i].second << '\n';
		//adj[v[i].first].pb(v[i].second);
	}

	//cout << "-------" << '\n';

	//cout << dfs(1, 0, init, d) << '\n';

	return 0;
}

//======================================================================================================================