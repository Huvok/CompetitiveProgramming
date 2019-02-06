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

char a[100005][105];

ll segmentTree[3 * 100005][10], lazy[3 * 100005][10];
ll lazymark[3 * 100005];
ll ss;
ll n, q;

void precalcSegmentTree()
{
	mem(lazymark, 0);
	FOR(i, 0, n)
	{
		FOR(j, 0, strlen(a[i]))
		{
			segmentTree[ss + i][a[i][j] - '0']++;
		}
	}

	for (ll i = ss - 1; i; i--)
	{
		FOR(j, 0, 10)
		{
			segmentTree[i][j] = segmentTree[i << 1][j] + segmentTree[i << 1 | 1][j];
		}
	}
}

void propagate(ll n, ll d)
{
	if (lazymark[n])
	{
		FOR(i, 0, 10)
			segmentTree[n][i] = lazy[n][i] * d;

		if (n < ss)
		{
			FOR(i, 0, 10)
			{
				lazy[n << 1][i] = lazy[n][i];
				lazy[n << 1 | 1][i] = lazy[n][i];
			}
			lazymark[n << 1] = 1;
			lazymark[n << 1 | 1] = 1;
		}

		FOR(i, 0, 10)
			lazy[n][i] = 0;
		lazymark[n] = 0;
	}
}

void query(ll n, ll l, ll r, ll d, vi &fill)
{
	propagate(n, d);

	if (l > r)
		return;

	if (!l && r == d - 1)
	{
		ll champ = 0;
		ll idx = 0;

		FOR(i, 0, 10)
			fill[i] += segmentTree[n][i];

		return;
	}

	d /= 2;
	query(n << 1, l, min(d - 1, r), d, fill);
	query(2 * n + 1, max(0LL, l - d), r - d, d, fill);
}

void query3(ll n, ll l, ll r, ll d, string x)
{
	propagate(n, d);
	if (l > r) return;

	if (!l && r == d - 1)
	{
		FOR(i, 0, sz(x))
			lazy[n][x[i] - '0']++;
		lazymark[n] = 1;
		propagate(n, d);
		return;
	}

	d /= 2;
	query3(n << 1, l, min(d - 1, r), d, x);
	query3(2 * n + 1, max(0LL, l - d), r - d, d, x);

	FOR(i, 0, 10)
	{
		segmentTree[n][i] = segmentTree[n << 1][i] + segmentTree[n << 1 | 1][i];
	}
}

int main()
{
	scanf("%lld %lld", &n, &q);
	FOR(i, 0, n)
	{
		scanf("%s", &a[i]);
		if (i > 100000)
			break;
	}

	ss = 1 << (ll)ceil(log2(n));
	precalcSegmentTree();
	vi fil(10);
	ll x, l, r;
	char ch[105];
	FOR(i, 0, q)
	{
		scanf("%lld %lld %lld", &x, &l, &r);
		if (x == 0)
		{
			fill(all(fil), 0);
			query(1, l - 1, r - 1, ss, fil);
			ll champ = 0, idx = 0;
			FOR(i, 0, 10)
			{
				if (fil[i] > champ)
				{
					champ = fil[i];
					idx = i;
				}
			}

			printf("%lld\n", idx);
		}
		else
		{
			scanf("%s", &ch);
			query3(1, l - 1, r - 1, ss, ch);
		}
	}

	return 0;
}