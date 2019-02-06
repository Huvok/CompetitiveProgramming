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

ii arr[100005];
ll a[100005];
ll cnt[100005];
ll ss;

ll segmentTree[3 * 100001];
#define MOD 1000000007

void precalcSegmentTree() 
{
	FOR(i, 0, ss) segmentTree[ss + i] = 0;

	FOR(i, 0, 100001) 
	{
		segmentTree[ss + i] = 0;
	}
}

ll query(ll n, ll l, ll r, ll d) 
{
	if (l > r) return 0;
	if (!l && r == d - 1) 
	{
		return segmentTree[n];
	}

	d /= 2;
	return (query(n << 1, l, min(d - 1, r), d) +
		query(2 * n + 1, max(0LL, l - d), r - d, d)) % MOD;
}

void modify(ll n, ll x) 
{
	segmentTree[ss + n] = x;
	n += ss;
	while (n >>= 1) 
	{
		segmentTree[n] = segmentTree[n << 1] + segmentTree[n << 1 | 1];
		segmentTree[n] %= MOD;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;

		FOR(i, 0, n)
		{
			ll x;
			cin >> x;
			arr[i] = mp(x, i);
		}
		
		sort(arr, arr + n);
		ll idx = 0;
		ll prev = arr[0].first;
		arr[0].first = 0;
		FOR(i, 1, n)
		{
			if (arr[i].first != prev)
				idx++;
			prev = arr[i].first;
			arr[i].first = idx;
		}

		FOR(i, 0, n)
			a[arr[i].second] = arr[i].first;

		mem(cnt, 0);
		ss = 1LL << (ll)ceil(log2(100001));
		mem(segmentTree, 0);
		precalcSegmentTree();
		reverse(a, a + n);
		FOR(i, 0, n)
		{
			
			cnt[a[i]] += query(1, 0, a[i] - 1, ss);
			cnt[a[i]]++;
			cnt[a[i]] %= MOD;
			modify(a[i], cnt[a[i]]);
			

			/*RFOR(j, a[i] - 1, 0)
			{
				cnt[a[i]] += cnt[j];
				cnt[a[i]] %= MOD;
			}

			cnt[a[i]]++;
			cnt[a[i]] %= MOD;*/
		}

		ll ans = 0;
		FOR(i, 0, 100005)
		{
			ans += cnt[i];
			ans %= MOD;
		}

		cout << (ans) % MOD << endl;
	}

	return 0;
}

//======================================================================================================================