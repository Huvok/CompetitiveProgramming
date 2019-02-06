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
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define mem(x, val) memset((x), (val), sizeof(x))
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

const double EPS = .000000001;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

ll a[100005], as[100005], bs[100005];
ii segments[100005];
ll ss;
vector<ll> segmentTree[3 * 100005];

void precalcSegmentTree(ll N) 
{
	FOR(i, 0, N) 
	{
		segmentTree[ss + i].pb(bs[i]);
	}

	for (int i = ss - 1; i; i--) 
	{
		merge(all(segmentTree[i << 1]), all(segmentTree[i << 1 | 1]), back_inserter(segmentTree[i]));
	}
}

ll query(int n, int l, int r, int d, ll k) 
{
	if (l > r) return 0;
	if (!l && r == d - 1) 
	{
		vi::iterator it = lower_bound(all(segmentTree[n]), k);
		return (distance(segmentTree[n].begin(), it));
	}

	d /= 2;

	return query(n << 1, l, min(d - 1, r), d, k) + query(2 * n + 1, max(0, l - d), r - d, d, k);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, q;
	cin >> n >> q;

	FOR(i, 0, n)
	{
		cin >> a[i];
	}

	unordered_map<ll, ll> m;
	ll sum = 0;
	ll idx = 0;
	m[0] = -1;
	FOR(i, 0, n)
	{
		sum += a[i];
		if (a[i] == 0)
		{
			segments[idx++] = mp(i, i);
		}
		else if (m.find(sum) != m.end())
		{
			segments[idx++] = mp(m[sum] + 1, i);
		}
		
		m[sum] = i;
	}

	sort(segments, segments + idx);
	FOR(i, 0, idx)
	{
		as[i] = segments[i].first;
		bs[i] = segments[i].second;
	}

	ss = 1 << (ll)ceil(log2(idx));
	precalcSegmentTree(idx);
	FOR(i, 0, q)
	{
		ll l, r;
	
		cin >> l >> r;
		l--, r--;
		ll k = r;
		l = lower_bound(as, as + idx, l) - as;
		r = upper_bound(as, as + idx, r) - as;
		r--;

		if (l >= idx)
			cout << "NO" << '\n';
		else
		{
			ll q = query(1, l, r, ss, k + 1);
			cout << (q ? "YES" : "NO") << '\n';
		}
	}

	return 0;
}

//======================================================================================================================