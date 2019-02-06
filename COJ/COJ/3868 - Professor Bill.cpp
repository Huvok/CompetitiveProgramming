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

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }

const double EPS = .000000001;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
ii a[200005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	sc(n);

	ll x, c;
	ll idx = 0;
	bool can = true;
	FOR(i, 0, n)
	{
		sc(c);
		if (!c)
			can = false;
		FOR(j, 0, c)
		{
			sc(x);
			a[idx++] = mp(x, i);
		}
	}

	sort(a, a + idx);
	
	unordered_map<ll, ll> s;
	ii champ = { INT_MAX, 0 };
	ll l = 0, r = -1;
	while (r + 1 < idx &&
		can)
	{
		while (sz(s) < n &&
			r + 1 < idx)
		{
			r++;
			s[a[r].second]++;
		}

		while (sz(s) >= n &&
			l <= r)
		{
			if (a[r].first - a[l].first < champ.first - champ.second)
			{
				champ = mp(a[r].first, a[l].first);
			}

			s[a[l].second]--;
			if (s[a[l].second] == 0)
				s.erase(a[l].second);
			l++;
		}
	}

	if (can)
		printf("%lld %lld\n", champ.second, champ.first);
	else
		printf("-1\n");

	return 0;
}

//======================================================================================================================