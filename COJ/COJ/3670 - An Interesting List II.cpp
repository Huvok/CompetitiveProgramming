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

#define MAX_N 105
#define MOD 1000000007
ll n, l, m;
struct Matrix
{
	ll mat[MAX_N][MAX_N];
};

Matrix matMul(Matrix a, Matrix b)
{
	Matrix ans;
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			ans.mat[i][j] = 0;
			FOR(k, 0, n)
			{
				ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j] % MOD);
				ans.mat[i][j] %= MOD;
			}
		}
	}

	return ans;
}

ll matPow(Matrix base, ll p, ll n)
{
	p--;
	Matrix ans;
	FOR(i, 0, n)
	{
		ans.mat[i][i] = 1;
	}

	while (p)
	{
		if (p & 1)
			ans = matMul(ans, base);
		base = matMul(base, base);
		p >>= 1;
	}

	ll ret = 0;
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			ret += ans.mat[i][j];
			ret %= MOD;
		}
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> l >> m;

	Matrix mat;
	FOR(i, 0, n)
	{
		FOR(k, max(0LL, i - m), min(n, i + m + 1))
		{
			mat.mat[i][k] = 1;
		}
	}

	ll ans = matPow(mat, l, n);

	cout << ans << endl;

	return 0;
}