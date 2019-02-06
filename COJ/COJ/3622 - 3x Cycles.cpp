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

vi adj[1000005];
ll cols[1000005];
bool can = true;
bool br = false;
void dfs(ll i, ll p, ll cur)
{
	if (cols[i] != -1 &&
		cols[i] != cur)
	{
		can = false;
		return;
	}
	else if (cols[i] == cur)
	{
		br = true;
		return;
	}

	cols[i] = cur;
	
	FOR(j, 0, adj[i].size())
	{
		if (br)
			break;
		ll v = adj[i][j];

		if (v != p)
		{
			dfs(v, i, (cur + 1) % 3);
		}
	}

	cols[i] = -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	ll s, d;
	FOR(i, 0, m)
	{
		cin >> s >> d;
		adj[s].pb(d);
		adj[d].pb(s);
	}

	memset(cols, -1, sizeof(cols));
	FOR(i, 0, n)
	{
		if (cols[i] == -1)
		{
			br = false;
			dfs(i, -1, 0);
		}
	}

	if (can)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}