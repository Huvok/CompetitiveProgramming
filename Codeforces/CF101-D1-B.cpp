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
//                                          //IDEA: First make an index compression. There can be at most 2*10^5
//                                          //      indexes. Then make a backwards DP, from the last coordinate (the
//                                          //      new n), which is the base case and its answer is 1. Then maintain
//                                          //      a counter of how many possible answers you can have. Imagine you
//                                          //      are at the k index, the amount of possible answers from k to n is
//                                          //      the answers of dp[k + i] where i is every bus stop where you can
//                                          //      come out of the bus and you can take it right at k, and the sum
//                                          //      of all dp[k + i] is stored in the counter mentioned above. Then
//                                          //      you have to take from the counter those answers of the buses you
//                                          //      cannot go in anymore, for which I used a priority queue to take
//                                          //      the buses whose first "take in" index is k (the current index).
//                                          //      The answer is dp[0].

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
ii a[100005];
ll dp[200005];
set<ll> s;
priority_queue<ii> pq;
unordered_map<ll, ll> mapp;
#define MOD 1000000007

bool cmp(ii p, ii o)
{
	if (p.second == o.second)
		return p.first > o.first;

	return p.second < o.second;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n, m;
	cin >> n >> m;

	FOR(i, 0, m)
		cin >> a[i].first >> a[i].second;

	FOR(i, 0, m)
	{
		s.insert(a[i].first);
		s.insert(a[i].second);
	}

	s.insert(n);
	s.insert(0);

	ll cnt = 0;
	for (auto it : s)
	{
		if (mapp.find(it) == mapp.end())
		{
			mapp[it] = cnt;
			cnt++;
		}
	}

	FOR(i, 0, m)
	{
		a[i].first = mapp[a[i].first];
		a[i].second = mapp[a[i].second];
	}

	sort(a, a + m, cmp);

	n = mapp[n];
	dp[n] = 1;
	ll cur = 0;
	ll idx = m - 1;
	ROF(i, n - 1, 0)
	{
		while (idx >= 0 &&
			a[idx].second > i)
		{
			cur += dp[a[idx].second];
			cur %= MOD;
			pq.push(ii(a[idx].first, dp[a[idx].second]));
			idx--;
		}

		dp[i] = cur;

		while (!pq.empty() &&
			pq.top().first >= i)
		{
			ii x = pq.top();
			pq.pop();
			cur = (cur - x.second + MOD) % MOD;
		}
	}

	cout << dp[0] << endl;

	return 0;
}

//======================================================================================================================