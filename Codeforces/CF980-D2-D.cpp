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
//                                          //IDEA: A perfect square has all factors with an even power, so we can
//                                          //      reduce every factor of every number and let only those with an odd
//                                          //      power, and leave that power be one i.e. 12 turns to 6, -4 turns to
//                                          //      -2. Then we just iterate over the new array and count the number of
//                                          //      different elements in range, excluding zero. We need coordinate
//                                          //      compresion since a set causes TLE.

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
ll ans[5005];
ll a[5005], b[5005];

vii factors;

void getFactors(ll n)
{
	factors.clear();

	ll step = 1;
	for (ll i = 2; i * i <= n; i += step, step = 2)
	{
		if (n % i == 0)
		{
			factors.pb(mp(i, 0));

			while (n % i == 0)
			{
				n /= i;
				factors.back().second++;
			}
		}
	}

	if (n != 1)
		factors.pb(mp(n, 1));
}

void get(ll x)
{
	bool neg = false;
	if (x < 0)
	{
		neg = true;
		x *= -1;
	}

	getFactors(x);
	if (neg)
		factors.pb(mp(-1, 1));
}

ll cnt[5005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll n;
	sc(n);
	
	FOR(i, 0, n)
	{
		ll x;
		cin >> x;
		if (x == 0)
		{
			a[i] = 0;
			continue;
		}
		get(x);
		a[i] = 1;
		FOR(j, 0, sz(factors))
		{
			if (factors[j].second & 1)
				a[i] *= factors[j].first;
		}
	}

	set<ll> s;
	FOR(i, 0, n)
	{
		if (a[i] == 0)
			continue;
		
		s.insert(a[i]);
	}

	ll cur = 1;
	map<ll, ll> m;
	for (auto it : s)
	{
		m.insert(mp(it, cur));
		cur++;
	}

	FOR(i, 0, n)
		a[i] = (a[i] == 0 ? 0 : m[a[i]]);

	ll aux = 0;
	FOR(i, 0, n)
	{
		mem(cnt, 0);
		aux = 0;
		FOR(j, i, n)
		{
			cnt[a[j]]++;
			if (cnt[a[j]] == 1 &&
				a[j] != 0)
				aux++;

			ans[max(aux, 1LL)]++;
		}
	}

	FOR(i, 1, n + 1)
		printf("%lld ", ans[i]);

	printf("\n");

	return 0;
}

//======================================================================================================================