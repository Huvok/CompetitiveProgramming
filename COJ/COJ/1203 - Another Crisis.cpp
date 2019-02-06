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
vi adj[100005];
ll cost[100005];
ll v, p, ans;

ll dfs(ll i)
{
	priority_queue<ll> pq;
	FOR(j, 0, sz(adj[i]))
	{
		pq.push(-dfs(adj[i][j]));
	}

	ll ret = 0;
	FOR(j, 0, ceil(p * sz(adj[i]) / 100.))
	{
		ret += (-pq.top());
		pq.pop();
	}

	cost[i] = ret;
	return (sz(adj[i]) == 0 ? 1 : ret);
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;
	
	while (true)
	{
		cin >> v >> p;
		if (v + p == 0)
			break;

		ll x;
		FOR(i, 0, v + 1)
			adj[i].clear();

		FOR(i, 0, v)
		{
			cin >> x;
			adj[x].pb(i + 1);
		}

		ll ans = dfs(0);

		cout << ans << endl;
	}

	return 0;
}

//======================================================================================================================