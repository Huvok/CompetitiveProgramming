#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <queue>
#include <string.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll a[100005];
ll ax[100005];

struct bucket
{
	ll cur = 0;
	ll a[645];
	ll b[645];
	ll n = 0;
};

bucket buckets[645];

ll bsz;

ll query(ll l, ll r, ll x)
{
	ll ret = 0;
	while (l % bsz != 0 &&
		l < r)
	{
		if (buckets[l / bsz].b[l % bsz] + buckets[l / bsz].cur > x)
			ret++;
		l++;
	}

	while (r % bsz != bsz - 1 &&
		r >= l)
	{
		if (buckets[r / bsz].b[r % bsz] + buckets[r / bsz].cur > x)
			ret++;
		r--;
	}

	while (l < r)
	{
		auto it = upper_bound(buckets[l / bsz].a, buckets[l / bsz].a + buckets[l / bsz].n, 
			x - buckets[l / bsz].cur) - buckets[l / bsz].a;

		ret += buckets[l / bsz].n - it;
		l += bsz;
	}

	return ret;
}

void update(ll l, ll r, ll x)
{
	bool ch = false;
	while (l % bsz != 0 &&
		l < r)
	{
		buckets[l / bsz].b[l % bsz] += x;
		l++;
		ch = true;
	}

	if (ch)
	{
		FOR(j, 0, bsz)
			buckets[(l - 1) / bsz].a[j] = buckets[(l - 1) / bsz].b[j];
		sort(buckets[(l - 1) / bsz].a, buckets[(l - 1) / bsz].a + buckets[(l - 1) / bsz].n);
	}

	ch = false;

	while (r % bsz != bsz - 1 &&
		r >= l)
	{
		buckets[r / bsz].b[r % bsz] += x;
		r--;
		ch = true;
	}

	if (ch)
	{
		FOR(j, 0, bsz)
			buckets[(r + 1) / bsz].a[j] = buckets[(r + 1) / bsz].b[j];
		sort(buckets[(r + 1) / bsz].a, buckets[(r + 1) / bsz].a + buckets[(r + 1) / bsz].n);
	}

	while (l < r)
	{
		buckets[l / bsz].cur += x;
		l += bsz;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, q;
	cin >> n >> q;

	FOR(i, 0, n)
	{
		cin >> a[i];
		ax[i] = a[i];
	}

	bsz = sqrt(n) / 2;

	FOR(i, 0, n)
	{
		ll now = i / bsz;
		buckets[now].a[i % bsz] = a[i];
		buckets[now].b[i % bsz] = a[i];
		buckets[now].n++;

		if (i % bsz == bsz - 1 ||
			i == n - 1)
		{
			sort(buckets[now].a, buckets[now].a + buckets[now].n);
		}
	}

	char c;
	ll l, r;
	while (q--)
	{
		cin >> c >> l >> r;
		l--;
		r--;
		if (l > r)
			swap(l, r);

		if (c == 'Q')
		{
			ll x = max(buckets[l / bsz].b[l % bsz] + buckets[l / bsz].cur, 
				buckets[r / bsz].b[r % bsz] + buckets[r / bsz].cur);

	
			cout << query(l, r, x) << '\n';
		}
		else
		{
			ll x;
			cin >> x;

	
			update(l, r, x);
		}
	}

	return 0;
}