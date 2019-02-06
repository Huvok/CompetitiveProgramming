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

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
string mat[10];
ll cur = 0;
ll n;

bool dfs(ll i, ll j, ll dir)
{
	if (i < 0 || j < 0 || i >= n || j >= n || mat[i][j] == 'o')
		return false;

	mat[i][j] = 'o';
	cur++;

	if (cur == n * n)
		return true;
	bool can = false;
	if (i == 0 ||
		j == 0 ||
		i == n - 1 ||
		j == n - 1)
	{
		can |= dfs(i - 1, j, 0);
		can |= dfs(i, j + 1, 1);
		can |= dfs(i + 1, j, 2);
		can |= dfs(i, j - 1, 3);
	}
	else if (dir == 0 &&
		mat[i - 1][j] == 'o')
	{
		can |= dfs(i, j + 1, 1);
		can |= dfs(i + 1, j, 2);
		can |= dfs(i, j - 1, 3);
	}
	else if (dir == 1 &&
		mat[i][j + 1] == 'o')
	{
		can |= dfs(i - 1, j, 0);
		can |= dfs(i + 1, j, 2);
		can |= dfs(i, j - 1, 3);
	}
	else if (dir == 2 &&
		mat[i + 1][j] == 'o')
	{
		can |= dfs(i - 1, j, 0);
		can |= dfs(i, j + 1, 1);
		can |= dfs(i, j - 1, 3);
	}
	else if (dir == 3 &&
		mat[i][j - 1] == 'o')
	{
		can |= dfs(i - 1, j, 0);
		can |= dfs(i, j + 1, 1);
		can |= dfs(i + 1, j, 2);
	}
	else
	{
		if (dir == 0)
			can |= dfs(i - 1, j, 0);
		else if (dir == 1)
			can |= dfs(i, j + 1, 1);
		else if (dir == 2)
			can |= dfs(i + 1, j, 2);
		else
			can |= dfs(i, j - 1, 3);
	}

	mat[i][j] = 'x';
	cur--;
	return can;
}
 
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;
	cin >> n;

	FOR(i, 0, n)
	{
		cin >> mat[i];
		FOR(j, 0, n)
		{
			if (mat[i][j] == 'o')
				cur++;
		}
	}

	bool can = false;
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			if (mat[i][j] == 'x')
			{
				can |= dfs(i, j, 0);
				can |= dfs(i, j, 1);
				can |= dfs(i, j, 2);
				can |= dfs(i, j, 3);
			}

			if (can)
				break;
		}
	}

	if (can)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

//======================================================================================================================