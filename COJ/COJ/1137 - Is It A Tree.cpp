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

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll adj[100005];
unordered_set<ll> se;

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;
	ll s, d;
	ll cas = 1;
	while (true)
	{
		bool can = true;
		mem(adj, 0);
		se.clear();
		while (true)
		{
			cin >> s >> d;
			if (s == 0 &&
				d == 0)
			{
				ll cnt = 0;
				for (auto it : se)
				{
					if (adj[it] == 0)
						cnt++;
				}

				if (cnt > 1 ||
					cnt == 0 &&
					sz(se) > 0)
					can = false;

				if (can)
					cout << "Case " << cas << " is a tree." << endl;
				else
					cout << "Case " << cas << " is not a tree." << endl;
				cas++;
				break;
			}
			else if (s < 0 &&
				d < 0)
				return 0;

			adj[d]++;
			se.insert(s);
			if (adj[d] > 1)
				can = false;
		}
	}

	return 0;
}

//======================================================================================================================