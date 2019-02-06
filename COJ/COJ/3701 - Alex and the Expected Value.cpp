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

vi adj[100005];
ll cycle = -1;
ll mark[100005];

void dfs(ll i, ll cur, ll p)
{
	if (mark[i] != -1)
	{
		cycle = cur - mark[i];
		return;
	}

	mark[i] = cur;

	FOR(j, 0, sz(adj[i]))
	{
		if (adj[i][j] != p &&
			cycle == -1)
			dfs(adj[i][j], cur + 1, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll n;
	cin >> n;
	ll s, d;
	FOR(i, 0, n)
	{
		cin >> s >> d;
		adj[s].pb(d);
		adj[d].pb(s);
	}

	mem(mark, -1);
	dfs(1, 0, -1);
	
	if (cycle == 0)
		cycle = 2;
	cout << fixed << setprecision(7) << 1.0 + cycle * 1.0 / n << endl;

	return 0;
}