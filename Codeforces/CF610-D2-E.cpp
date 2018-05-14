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
//                                          //IDEA: The result of d(p) can be calculated in the next way: take the
//                                          //      first two characters, if the second one appears before the first
//                                          //      one in the permutation p or is the same as the first one, we need
//                                          //      another cycle of p, so we could precalculate the amount of times
//                                          //      each character appears on s and store it in a matrix of 10x10 and
//                                          //      for every d(p) the answer will be matrix[p[i]][p[i+1]] for every i,
//                                          //      which can be calculated by bruteforce in m*k*k, however the updates
//                                          //      to s must be optimized. We can use lazy propagation, storing
//                                          //      a 10x10 matrix on each node of a segment tree and to combine two
//                                          //      nodes we just combine their matrices and add to the new matrix
//                                          //      +1 in the index [leftNodeLastChar][rightNodeFirstChar], for example
//                                          //      when merging ab with ca, we need to add a 1 to matrix[b][c].

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
ll n, m, k;
string s, p;
#define maxN 200005
int segmentTree[3 * maxN][11][11], lazy[3 * maxN], ss;
int br[3 * maxN], bl[3 * maxN], qr[10][10];

void precalcSegmentTree()
{
	mem(lazy, -1);

	FOR(i, 0, n)
	{
		ll c = s[i] - 'a';
		bl[ss + i] = br[ss + i] = c;
	}

	ROF(i, ss - 1, 1)
	{
		FOR(a, 0, k)
		{
			FOR(b, 0, k)
			{
				segmentTree[i][a][b] = segmentTree[i << 1][a][b] + segmentTree[i << 1 | 1][a][b];
			}
		}

		segmentTree[i][br[i << 1]][bl[i << 1 | 1]]++;
		bl[i] = bl[i << 1];
		br[i] = br[i << 1 | 1];
	}
}

void propagate(ll n, ll d)
{
	if (lazy[n] != -1)
	{
		bl[n] = br[n] = lazy[n];
		FOR(a, 0, k)
		{
			FOR(b, 0, k)
			{
				segmentTree[n][a][b] = 0;
			}
		}

		segmentTree[n][lazy[n]][lazy[n]] = d - 1;

		if (n < ss)
		{
			lazy[n << 1] = lazy[n];
			lazy[n << 1 | 1] = lazy[n];
		}

		lazy[n] = -1;
	}
}

bool query(ll n, ll l, ll r, ll d)
{
	propagate(n, d);

	if (l > r)
		return false;

	if (!l &&
		r == d - 1)
	{
		FOR(a, 0, k)
		{
			FOR(b, 0, k)
			{
				qr[a][b] += segmentTree[n][a][b];
			}
		}

		return true;
	}

	d /= 2;
	bool a = query(n << 1, l, min(d - 1, r), d);
	bool b = query(2 * n + 1, max(0LL, l - d), r - d, d);
	if (a && b)
		qr[br[n << 1]][bl[n << 1 | 1]]++;
	return true;
}

void query3(ll n, ll l, ll r, ll d, ll x)
{
	propagate(n, d);

	if (l > r)
		return;

	if (!l && r == d - 1)
	{
		lazy[n] = x;
		propagate(n, d);
		return;
	}

	d /= 2;
	query3(n << 1, l, min(d - 1, r), d, x);
	query3(2 * n + 1, max(0LL, l - d), r - d, d, x);

	FOR(a, 0, k)
	{
		FOR(b, 0, k)
		{
			segmentTree[n][a][b] = segmentTree[n << 1][a][b] + segmentTree[n << 1 | 1][a][b];
		}
	}

	segmentTree[n][br[n << 1]][bl[n << 1 | 1]]++;
	bl[n] = bl[n << 1];
	br[n] = br[n << 1 | 1];
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	cin >> n >> m >> k;
	cin >> s;
	ss = 1LL << (ll)ceil(log2(n));
	precalcSegmentTree();

	FOR(i, 0, m)
	{
		ll t;
		cin >> t;

		if (t == 1)
		{
			ll l, r;
			char c;
			cin >> l >> r >> c;
			l--; r--;
			query3(1, l, r, ss, c - 'a');
		}
		else
		{
			cin >> p;
			mem(qr, 0);
			query(1, 0, n - 1, ss);
			ll ans = 1;
			FOR(a, 0, k)
			{
				FOR(b, a, k)
				{
					ll c1 = p[a] - 'a';
					ll c2 = p[b] - 'a';
					ans += qr[c2][c1];
				}
			}

			cout << ans << endl;
		}
	}

	return 0;
}

//======================================================================================================================