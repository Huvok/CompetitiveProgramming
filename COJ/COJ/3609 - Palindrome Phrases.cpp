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

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, _VA_ARGS_), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
string a[105];
vi adj[105];
vi radj[105];
bool cycle;
bool can;

bool ready(ll i, ll idx, ll mode)
{
	if (mode == 1)
	{
		return sz(a[i]) - 1 == idx;
	}
	else
	{
		return idx == 0;
	}
}

ll dp[105][15][105][15];
bool vis[105][15][105][15];

void checkCycle(ll i, ll idx, ll j, ll jdx, bool first, ll cnt)
{
	if (cycle)
		return;
	if (cnt > 100)
		return;
	if (i == j &&
		idx == jdx &&
		!first)
	{
		cycle = true;
		return;
	}
	else if (i == j &&
		idx + 1 == jdx &&
		!first)
	{
		cycle = true;
		return;
	}

	if (ready(i, idx, 1) &&
		ready(j, jdx, 2))
	{
		FOR(k, 0, sz(adj[i]))
		{
			FOR(l, 0, sz(radj[j]))
			{
				ll vk = adj[i][k];
				ll vl = radj[j][l];

				if (a[vk][0] == a[vl][sz(a[vl]) - 1])
				{
					if (vk == vl &&
						sz(a[vk]) == 1 &&
						!first)
					{
						cycle = true;
						return;
					}
					else
						checkCycle(vk, 0, vl, sz(a[vl]) - 1, false, cnt + 1);
				}
			}
		}
	}
	else if (ready(i, idx, 1))
	{
		FOR(k, 0, sz(adj[i]))
		{
			ll vk = adj[i][k];

			if (a[vk][0] == a[j][jdx - 1])
			{
				checkCycle(vk, 0, j, jdx - 1, false, cnt + 1);
			}
		}
	}
	else if (ready(j, jdx, 2))
	{
		FOR(l, 0, sz(radj[j]))
		{
			ll vl = radj[j][l];

			if (a[i][idx + 1] == a[vl][sz(a[vl]) - 1])
			{
				checkCycle(i, idx + 1, vl, sz(a[vl]) - 1, false, cnt + 1);
			}
		}
	}
	else
	{
		if (a[i][idx + 1] == a[j][jdx - 1])
		{
			checkCycle(i, idx + 1, j, jdx - 1, false, cnt + 1);
		}
	}
}

ll solve(ll i, ll idx, ll j, ll jdx)
{
	if (cycle)
		return 0;
	if (i == j &&
		idx == jdx)
	{
		can = true;
		checkCycle(i, idx, j, jdx, true, 0);
		return 1;
	}
	else if (i == j &&
		idx + 1 == jdx)
	{
		checkCycle(i, idx, j, jdx, true, 0);
		can = true;
		return 2;
	}

	if (vis[i][idx][j][jdx])
		return 0;
	vis[i][idx][j][jdx] = 1;

	if (dp[i][idx][j][jdx] != -1)
		return dp[i][idx][j][jdx];

	ll ret = 0;
	if (ready(i, idx, 1) &&
		ready(j, jdx, 2))
	{
		FOR(k, 0, sz(adj[i]))
		{
			FOR(l, 0, sz(radj[j]))
			{
				ll vk = adj[i][k];
				ll vl = radj[j][l];

				if (a[vk][0] == a[vl][sz(a[vl]) - 1])
				{
					if (vk == j &&
						vl == i)
					{
						checkCycle(i, idx, j, jdx, true, 0);
						can = true;
						ret = max(ret, ret + 2LL);
					}
					else
						ret = max(ret, 2 + solve(vk, 0, vl, sz(a[vl]) - 1));
				}
			}
		}
	}
	else if (ready(i, idx, 1))
	{
		FOR(k, 0, sz(adj[i]))
		{
			ll vk = adj[i][k];

			if (a[vk][0] == a[j][jdx - 1])
			{
				ret = max(ret, 2 + solve(vk, 0, j, jdx - 1));
			}
		}
	}
	else if (ready(j, jdx, 2))
	{
		FOR(l, 0, sz(radj[j]))
		{
			ll vl = radj[j][l];

			if (a[i][idx + 1] == a[vl][sz(a[vl]) - 1])
			{
				ret = max(ret, 2 + solve(i, idx + 1, vl, sz(a[vl]) - 1));
			}
		}
	}
	else
	{
		if (a[i][idx + 1] == a[j][jdx - 1])
		{
			ret = max(ret, 2 + solve(i, idx + 1, j, jdx - 1));
		}
	}

	if (!can)
		ret = 0;

	return dp[i][idx][j][jdx] = ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;
	ll n, m;
	cin >> n >> m;
	FOR(i, 1, n + 1)
		cin >> a[i];

	ll s, d;
	FOR(i, 0, m)
	{
		cin >> s >> d;
		adj[s].pb(d);
		radj[d].pb(s);
	}

	ll champ = 0;
	cycle = false;
	mem(dp, -1);
	mem(vis, 0);
	FOR(i, 1, n + 1)
	{
		FOR(j, i, n + 1)
		{
			if (cycle)
				break;
			if (!cycle &&
				a[i][0] == a[j][sz(a[j]) - 1])
			{
				can = false;
				ll x = solve(i, 0, j, sz(a[j]) - 1);
				mem(vis, 0);
				if (can)
				{
					champ = max(champ, x);
				}
			}
		}
	}

	if (cycle)
		champ = -1;
	cout << champ << endl;

	return 0;
}

//======================================================================================================================