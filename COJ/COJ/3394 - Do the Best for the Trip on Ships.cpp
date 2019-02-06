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

//----------------------------------------------------------------------------------------------------------------------
ll ships[10];
ll happy[20][10];
ll weights[20];
ll gw[1 << 16];
ll n, k;
ll lim;
ll dp[1 << 16][10];
ll dp2[1 << 16][10];

void precalcgw()
{
	lim = 1 << n;
	FOR(i, 1, lim)
	{
		FOR(j, 0, n)
		{
			if ((i >> j) & 1)
				gw[i] += weights[j];
		}
	}
}

ll solve(ll mask, ll k)
{
	if (k < 0)
		return 0;

	if (k == 0)
	{
		if (gw[mask] <= ships[k])
			return dp[mask][k];
		else
			return -1000000000;
	}

	if (dp2[mask][k] != -1)
		return dp2[mask][k];

	ll ret = -100000000;
	for (ll i = mask; i >= 0; i = (i - 1) & mask)
	{
		if (gw[i] > ships[k])
			continue;

		ll comp = (1LL << 20) - 1;
		comp = ~i & comp;
		comp &= mask;

		if (k == 0 &&
			comp != 0)
			continue;

		ret = max(ret, dp[i][k] + solve(comp, k - 1));
		if (i == 0)
			break;
	}

	return dp2[mask][k] = ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;
	cin >> n >> k;

	FOR(i, 0, k)
		cin >> ships[i];

	FOR(i, 0, n)
		cin >> weights[i];

	FOR(i, 0, n)
	{
		FOR(j, 0, k)
		{
			cin >> happy[i][j];
		}
	}

	precalcgw();

	FOR(i, 0, n)
	{
		FOR(j, 0, k)
		{
			if (ships[j] >= weights[i])
				dp[1 << i][j] = happy[i][j];
		}
	}

	FOR(l, 0, k)
	{
		FOR(mask, 1, lim)
		{
			if (gw[mask] > ships[l])
				continue;

			for (ll i = (mask - 1) & mask; i > 0; i = (i - 1) & mask)
			{
				ll comp = (1LL << 17) - 1;
				comp = ~i & comp;
				comp &= mask;

				dp[mask][l] = max(dp[mask][l], dp[i][l] + dp[comp][l]);
			}
		}
	}

	mem(dp2, -1);
	ll ans = solve(lim - 1, k - 1);

	if (ans > 0)
		cout << ans << endl;
	else
		cout << "No travel." << endl;

	return 0;
}

//======================================================================================================================