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

using namespace std;

//                                          //AUTHOR: Hugo Garcia
//                                          //IDEA: Get the amount of nodes in a tree that are at most d of distance 
//                                          //      from each of the marked nodes. First, calculate the farthest marked 
//                                          //      node in every node's subtree, then calculate the same but for 
//                                          //      outside of every node's subtree, which would be the max between the 
//                                          //      answer of your parent subtree + 1 and the answer of your parent's 
//                                          //      outside answer + 1.
//                                          //      Note: check the case when you are your parent's subtree answer.

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

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
bool affected[100005];
vi adj[100005];
ll dp[100005][2];
ll down[100005], up[100005];
ll n, m, d;

void getDown(ll i, ll p)
{
	if (affected[i])
		down[i] = 0;
	else
		down[i] = INT_MIN;

	ll champ1 = INT_MIN, champ2 = INT_MIN;;
	FOR(j, 0, sz(adj[i]))
	{
		ll v = adj[i][j];

		if (p != v)
		{
			getDown(v, i);
			down[i] = max(down[i], down[v] + 1);

			if (down[v] + 1 > champ2)
			{
				champ2 = down[v] + 1;
				if (champ2 > champ1) 
				{
					swap(champ1, champ2);
				}
			}
		}
	}

	dp[i][0] = champ1;
	dp[i][1] = champ2;
}

void getUp(ll i, ll p)
{
	if (p == -1)
		up[i] = 0;
	else
	{
		if (dp[p][0] == down[i] + 1)
			up[i] = dp[p][1] + 1;
		else
			up[i] = dp[p][0] + 1;

		up[i] = max(up[i], up[p] + 1);
	}

	FOR(j, 0, sz(adj[i]))
	{
		ll v = adj[i][j];

		if (v != p)
		{
			getUp(v, i);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sc(n), sc(m), sc(d);

	ll x;
	FOR(i, 0, m)
	{
		sc(x);
		affected[x] = 1;
	}

	ll s, de;
	FOR(i, 0, n - 1)
	{
		sc(s), sc(de);
		adj[s].pb(de);
		adj[de].pb(s);
	}

	getDown(x, -1);
	getUp(x, -1);

	ll ans = 0;
	FOR(i, 1, n + 1)
	{
		if (max(down[i], up[i]) <= d)
			ans++;
	}

	printf("%lld\n", ans);

	return 0;
}

//======================================================================================================================