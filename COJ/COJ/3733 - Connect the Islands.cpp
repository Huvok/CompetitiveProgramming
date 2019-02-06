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

string mat[55];
ll r, c;
vii curCells;
map<ii, ll> belongs;
unordered_map<ll, vii> cellList;
ll cur;
ll done[10005];
bool vis[55][55];

void dfs(ll i, ll j)
{
	if (i < 0 || j < 0 || i >= r || j >= c)
		return;

	if (mat[i][j] == '.')
		return;

	mat[i][j] = '.';
	
	belongs.insert(mp(mp(i, j), cur));
	cellList[cur].pb(mp(i, j));
	if (cur == 1)
		curCells.pb(mp(i, j));
	dfs(i + 1, j);
	dfs(i - 1, j);
	dfs(i, j + 1);
	dfs(i, j - 1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll t;
	cin >> t;
	while (t--)
	{
		cin >> r >> c;
		belongs.clear();
		curCells.clear();
		cellList.clear();
		cur = 1;
		mem(done, 0);
		FOR(i, 0, r)
		{
			cin >> mat[i];
		}

		FOR(i, 0, r)
		{
			FOR(j, 0, c)
			{
				if (mat[i][j] == 'X')
				{
					dfs(i, j);
					cur++;
				}
			}
		}

		ll ans = 0;
		cur -= 2;
		done[1] = 1;

		while (cur > 0)
		{
			mem(vis, false);
			queue<pair<ii, ll>> q;
			FOR(i, 0, sz(curCells))
			{
				q.push(mp(curCells[i], -1));
				vis[curCells[i].first][curCells[i].second] = true;
			}

			while (!q.empty())
			{
				pair<ii, ll> v = q.front();
				ii cell = v.first;
				ll val = v.second;
				q.pop();

				if (belongs.find(mp(cell.first, cell.second)) != belongs.end() &&
					done[belongs[mp(cell.first, cell.second)]] == 0)
				{
					cur--;
					ans += val;
					done[belongs[mp(cell.first, cell.second)]] = true;
					ll who = belongs[mp(cell.first, cell.second)];
					FOR(i, 0, sz(cellList[who]))
					{
						curCells.pb(mp(cellList[who][i].first, cellList[who][i].second));
					}

					break;
				}

				vis[cell.first][cell.second] = true;
				if (cell.first < r &&
					vis[cell.first + 1][cell.second] == 0)
				{
					q.push(mp(mp(cell.first + 1, cell.second), val + 1));
					vis[cell.first + 1][cell.second] = true;
				}
				if (cell.second < c &&
					vis[cell.first][cell.second + 1] == 0)
				{
					q.push(mp(mp(cell.first, cell.second + 1), val + 1));
					vis[cell.first][cell.second + 1] = true;
				}
				if (cell.first > 0 &&
					vis[cell.first - 1][cell.second] == 0)
				{
					q.push(mp(mp(cell.first - 1, cell.second), val + 1));
					vis[cell.first - 1][cell.second] = true;
				}
				if (cell.second > 0 &&
					vis[cell.first][cell.second - 1] == 0)
				{
					q.push(mp(mp(cell.first, cell.second - 1), val + 1));
					vis[cell.first][cell.second - 1] = true;
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}