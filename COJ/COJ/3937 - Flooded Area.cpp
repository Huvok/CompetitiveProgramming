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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
string mat[55];
ll r, c;

void dfs(ll i, ll j)
{
	if (i >= r || i < 0 || j >= c || j < 0 || mat[i][j] == '.')
		return;

	mat[i][j] = '.';
	dfs(i + 1, j);
	dfs(i - 1, j);
	dfs(i, j + 1);
	dfs(i, j - 1);
}

bool check(ll i, ll j)
{
	ll hor = 0;
	ll ver = 0;
	FOR(k, j, c)
	{
		if (mat[i][k] == '*')
			hor++;
		else
			break;

		if (i &&
			mat[i - 1][k] == '*')
			return false;
	}

	FOR(k, i, r)
	{
		if (mat[k][j] == '*')
			ver++;
		else
			break;

		if (j &&
			mat[k][j - 1] == '*')
			return false;
	}

	if (hor != ver)
		return false;

	ll bhor = 0, bver = 0;
	FOR(k, j, c)
	{
		if (mat[i + ver - 1][k] == '*')
			bhor++;
		else
			break;

		if (i + ver < r &&
			mat[i + ver][k] == '*')
			return false;
	}

	FOR(k, i, r)
	{
		if (mat[k][j + hor - 1] == '*')
			bver++;
		else
			break;

		if (j + hor < c &&
			mat[k][j + hor] == '*')
			return false;
	}

	if (bhor != bver)
		return false;
	if (bhor != hor ||
		bver != ver)
		return false;

	FOR(k, i, i + ver)
	{
		FOR(l, j, j + hor)
		{
			if (mat[k][l] == '.')
				return false;
		}
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;
	cin >> r >> c;
	FOR(i, 0, r)
		cin >> mat[i];

	ll sq = 0;
	FOR(i, 0, r)
	{
		FOR(j, 0, c)
		{
			if (mat[i][j] == '*')
			{
				if (check(i, j))
				{
					sq++;
					dfs(i, j);
				}
				else
				{
					i = r;
					sq = 5;
					break;
				}
			}
		}
	}

	if (sq == 1)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}

//======================================================================================================================