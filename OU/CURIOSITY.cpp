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
#include <complex>

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

using namespace std;

//                                          //AUTHOR: Hugo Garcia
//                                          //IDEA: Use BFS and everytime you are in a new cell, try all the k possibilities.

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
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
#define debug(...) fprintf(stderr, VA_ARGS), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 100000000000000000

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ii a[15];
ll vis[1005][1005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n, m, k;
	cin >> n >> m >> k;
	ll xi, yi, xf, yf;
	cin >> xi >> yi >> xf >> yf;

	FOR(i, 0, k)
		cin >> a[i].first >> a[i].second;

	queue<pair<ii, ll>> q;
	q.push(pair<ii, ll>(ii(xi, yi), 0));
	vis[xi][yi] = 1;
	bool can = false;
	while (!q.empty())
	{
		pair<ii, ll> u = q.front();
		if (u.first.first == xf &&
			u.first.second == yf)
		{
			can = true;
			cout << u.second << endl;
			break;
		}

		q.pop();

		FOR(i, 0, k)
		{
			ii v = ii(u.first.first + a[i].first, u.first.second + a[i].second);
			if (v.first > 0 &&
				v.second > 0 &&
				v.first <= n &&
				v.second <= m &&
				vis[v.first][v.second] == 0)
			{
				vis[v.first][v.second] = 1;
				q.push(pair<ii, ll>(v, u.second + 1));
			}
		}
	}

	if (!can)
		cout << -1 << endl;

	return 0;
}

//======================================================================================================================