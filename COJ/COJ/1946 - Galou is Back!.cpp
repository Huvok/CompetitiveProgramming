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
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }

const double EPS = .000000001;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
ll vis[105][105];
ll mat[105][105];
ll n, m;

void dfs(ll i, ll j, ll mode)
{
	if (i >= n || j >= m || i < 0 || j < 0)
		return;

	if (mat[i][j] == 0)
		return;
	if (vis[i][j] == 1 &&
		mode == 1)
		return;
	if (vis[i][j] == 2 &&
		mode == 0)
		return;
	if (vis[i][j] == 3)
		return;

	if (vis[i][j] == 0)
		vis[i][j] = mode ? 1 : 2;
	else
		vis[i][j] = 3;

	dfs(i, j - 1, !mode);
	dfs(i + 1, j - 1, !mode);
	dfs(i + 1, j, !mode);
	dfs(i, j + 1, !mode);
	dfs(i - 1, j + 1, !mode);
	dfs(i - 1, j, !mode);
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;

	while (true)
	{
		cin >> n >> m;
		if (!n)
			break;
		mem(vis, 0);
		string str;
		FOR(i, 0, n)
		{
			cin >> str;
			FOR(j, 0, m)
			{
				if (str[j] == '*')
					mat[i][j] = 1;
				else if (str[j] == 'I')
					mat[i][j] = 2;
				else
					mat[i][j] = 0;
			}
		}

		FOR(i, 0, n)
		{
			FOR(j, 0, m)
			{
				if (mat[i][j] == 2)
					dfs(i, j, 1);
			}
		}

		cout << endl;

		FOR(i, 0, n)
		{
			FOR(j, 0, m)
			{
				if (mat[i][j] == 0)
					cout << ".";
				else if (vis[i][j] == 0)
					cout << "F";
				else if (vis[i][j] == 1)
					cout << "(";
				else if (vis[i][j] == 2)
					cout << ")";
				else
					cout << "B";
			}

			cout << endl;
		}
	}

	return 0;
}

//======================================================================================================================