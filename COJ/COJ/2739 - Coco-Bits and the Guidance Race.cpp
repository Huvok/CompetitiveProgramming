﻿#include <cmath>
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
double dp[1LL << 10][10];
ll a, b, c;
ll n;
vector<pair<ll, ii>> v;

double dist(ll a, ll b)
{
	ll x = abs(v[a].second.first - v[b].second.first);
	ll y = abs(v[a].second.second - v[b].second.second);
	return sqrt(x*x + y*y);
}

double tsp(ll mask, ll last)
{
	if (mask == (1LL << n) - 1)
		return dist(last, b);

	if (dp[mask][last] != -1)
		return dp[mask][last];

	double ans = INT_MAX;
	FOR(i, 0, n)
	{
		if (!(mask & (1LL << i)))
		{
			ans = min(ans, tsp(mask | (1LL << i), i) + dist(last, i));
		}
	}

	return dp[mask][last] = ans;
}

double psp(ll mask, ll last)
{
	if (mask == (((1LL << n) - 1) & (~(1LL << b))))
		return dist(last, b);

	if (dp[mask][last] > 0)
		return dp[mask][last];

	double ans = INT_MAX;
	FOR(i, 0, n)
	{
		if (!(mask & (1LL << i)) &&
			i != b)
		{
			ans = min(ans, tsp(mask | (1LL << i), i) + dist(last, i));
		}
	}

	if (ans == INT_MAX)
		return dp[mask][last] = dist(last, b);

	return dp[mask][last] = ans;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;

	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a >> b >> c;
		v.pb(mp(a, mp(b, c)));
	}

	sort(all(v));
	cin >> a >> b;
	FOR(i, 0, n)
	{
		if (v[i].first == a)
			a = i;
		if (v[i].first == b)
			b = i;
		v[i].first = i;
	}

	FOR(i, 0, (1LL << n))
	{
		FOR(j, 0, n)
			dp[i][j] = -1;
	}

	double ans;
	if (a == b)
	{
		ans = tsp(1LL << a, a);
	}
	else
	{
		ans = psp(1LL << a, a);
	}

	cout << fixed << setprecision(2) << ans << endl;

	return 0;
}

//======================================================================================================================