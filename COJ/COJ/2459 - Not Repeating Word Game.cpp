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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
unordered_set<string> a, b, c;

void process(string line, ll x)
{
	ll idx = 0;
	string cur = "";
	while (idx < sz(line))
	{
		if (line[idx] == ' ')
		{
			if (cur != "")
			{
				if (x == 1)
					a.insert(cur);
				else if (x == 2)
					b.insert(cur);
				else
					c.insert(cur);
				cur = "";
			}
		}
		else
			cur += line[idx];

		idx++;
	}

	if (cur != "")
	{
		if (x == 1)
			a.insert(cur);
		else if (x == 2)
			b.insert(cur);
		else
			c.insert(cur);
		cur = "";
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	string x, y, z;

	string line;
	while (getline(cin, line))
	{
		process(line, 1);
		getline(cin, line);
		process(line, 2);
		getline(cin, line);
		process(line, 3);

		ll pa = 0;
		ll pob = 0;
		ll pc = 0;

		for (auto it : a)
		{
			if (b.find(it) != b.end() &&
				c.find(it) != c.end())
				pa++;
			else if (b.find(it) != b.end() ||
				c.find(it) != c.end())
				pa += 2;
			else
				pa += 3;
		}

		for (auto it : b)
		{
			if (a.find(it) != a.end() &&
				c.find(it) != c.end())
				pob++;
			else if (a.find(it) != a.end() ||
				c.find(it) != c.end())
				pob += 2;
			else
				pob += 3;
		}

		for (auto it : c)
		{
			if (a.find(it) != a.end() &&
				b.find(it) != b.end())
				pc++;
			else if (a.find(it) != a.end() ||
				b.find(it) != b.end())
				pc += 2;
			else
				pc += 3;
		}

		a.clear(); b.clear(); c.clear();
		printf("%lld/%lld/%lld\n", pa, pob, pc);
		getline(cin, line);
	}

	return 0;
}

//======================================================================================================================