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
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a) - 1; i>=ll(b); i--)
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

ll segmentTree[3 * 100005], lazy[3 * 100005], ss;
ll n;

void precalcSegmentTree() 
{
	memset(lazy, 0, sizeof(lazy));
	mem(segmentTree, 0);
}

void propagate(ll n, ll d) 
{
	if (lazy[n]) 
	{
		segmentTree[n] += lazy[n] * d;
		if (n<ss) 
		{
			lazy[n << 1] += lazy[n];
			lazy[n << 1 | 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

ll query(ll n, ll l, ll r, ll d) 
{ 
	propagate(n, d);

	if (l > r) return 0;

	if (!l && r == d - 1) 
	{
		return segmentTree[n];
	}
	
	d /= 2;
	return query(n << 1, l, min(d - 1, r), d) +
		query(2 * n + 1, max(0LL, l - d), r - d, d);
}

void query3(ll n, ll l, ll r, ll d, ll x) 
{
	propagate(n, d);

	if (l > r) return;

	if (!l && r == d - 1) 
	{
		lazy[n] += x;
		propagate(n, d);
		return;
	}

	d /= 2;
	query3(n << 1, l, min(d - 1, r), d, x);
	query3(2 * n + 1, max(0LL, l - d), r - d, d, x);
	segmentTree[n] = segmentTree[n << 1] + segmentTree[n << 1 | 1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	ss = 1 << (ll)ceil(log2(100005));
	precalcSegmentTree();

	ll l, r;
	FOR(i, 0, n)
	{
		cin >> l >> r;
		ll a = query(1, l, l, ss);
		ll b = query(1, r, r, ss);
		query3(1, l, l, ss, -a);
		query3(1, r, r, ss, -b);
		cout << a + b << endl;
		query3(1, l + 1, r - 1, ss, 1);
	}

	return 0;
}