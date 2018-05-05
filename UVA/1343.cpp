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
//                                          //IDEA: One way to solve this is to make a BFS and stop as soon as you get
//                                          //      to a state where the penalty (amount of numbers you do not want
//                                          //      in the center) is zero, but it will TLE/MLE soon because of the
//                                          //      amount of states, so we can solve it using IDA*, which is a DFS
//                                          //      that does not exceeds a certain depth and this depth is increasing
//                                          //      gradually until a solution is found. For this we need a heuristic
//                                          //      which can be the penalty mentioned above: 8 - max(# correct 1's,
//                                          //      # correct 2's, # correctt 3's). The penalty also represents that 
//                                          //      you need AT LEAST that amount of extra depth (or moves) to get to
//                                          //      your goal, so you can increase the depth threshold by that amount
//                                          //      in every iteration. Movement simulation through states can be
//                                          //      brute forced.

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
ll depth, solved;
ll center[8] = { 6, 7, 8, 11, 12, 15, 16, 17 };
ll shift[8][8] = {
	{ 0, 2, 6, 11, 15, 20, 22 },
	{ 1, 3, 8, 12, 17, 21, 23 },
	{ 10, 9, 8, 7, 6, 5, 4 },
	{ 19, 18, 17, 16, 15, 14, 13 },
	{ 23, 21, 17, 12, 8, 3, 1 },
	{ 22, 20, 15, 11, 6, 2, 0 },
	{ 13, 14, 15, 16, 17, 18, 19 },
	{ 4, 5, 6, 7, 8, 9, 10 }
};

ll invShift[8] = { 5, 4, 7, 6, 1, 0, 3, 2 };

void shiftStrip(ll a[], ll dir)
{
	ll aux = a[shift[dir][0]];
	FOR(i, 0, 6)
	{
		a[shift[dir][i]] = a[shift[dir][i + 1]];
	}

	a[shift[dir][6]] = aux;
}

ll H(ll a[])
{
	ll k[4] = { 0 };
	FOR(i, 0, 8)
	{
		k[a[center[i]]]++;
	}

	return 8 - max(k[1], max(k[2], k[3]));
}

ll path[150];
ll IDA(ll a[], ll curDepth, ll hv)
{
	if (hv == 0)
	{
		solved = 1;

		if (curDepth == 0)
		{
			cout << "No moves needed" << endl;
		}
		else
		{
			FOR(i, 0, curDepth)
			{
				cout << (char)(path[i] + 'A');
			}

			cout << endl;
		}

		cout << a[center[0]] << endl;
		return curDepth;
	}

	if (curDepth + hv > depth)
	{
		return curDepth + hv;
	}

	ll champ = 1e18, shv, aux;
	FOR(i, 0, 8)
	{
		shiftStrip(a, i);
		shv = H(a);
		path[curDepth] = i;
		aux = IDA(a, curDepth + 1, shv);
		champ = min(champ, aux);
		shiftStrip(a, invShift[i]);
		
		if (solved)
			break;
	}

	return champ;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	while (true)
	{
		ll a[32];
		FOR(i, 0, 24)
		{
			cin >> a[i];
			if (!a[i])
				return 0;
		}

		solved = 0;
		depth = 0;
		while (solved == 0)
		{
			depth = IDA(a, 0, H(a));
		}
	}

	return 0;
}

//======================================================================================================================
