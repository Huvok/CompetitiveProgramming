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
ll cnt[30];

void update(ll &time, ll x, ll &cur, ll rev)
{
	if (time == x)
		return;

	if (rev)
	{
		while (cur != 25)
		{
			cnt[cur--]++;
			cur = (cur + 26) % 26;
			time++;
			if (time == x)
				return;
		}
	}
	else
	{
		while (cur != 0)
		{
			cnt[cur++]++;
			cur %= 26;
			time++;
			if (time == x)
				return;
		}
	}

	FOR(i, 0, 26)
		cnt[i] += (x - time - 1) / 26;

	time += (x - time - 1) / 26 * 26;
	while (time < x)
	{
		time++;
		if (rev)
		{
			cnt[cur--]++;
			cur = (cur + 26) % 26;
		}
		else
		{
			cnt[cur++]++;
			cur %= 26;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	sc(n);
	char str[10];
	ll x;
	char c[10];
	ll time = 0;
	ll cur = 0;
	ll rev = 0;

	FOR(i, 0, n)
	{
		scanf("%s", &str);
		if (strcmp(str, "UPIT") == 0)
		{
			scanf("%lld %s", &x, &c);
			update(time, x, cur, rev);

			printf("%lld\n", cnt[c[0] - 'a']);
		}
		else
		{
			sc(x);
			update(time, x - 1, cur, rev);
			rev = !rev;
			update(time, x, cur, rev);
		}
	}

	return 0;
}

//======================================================================================================================