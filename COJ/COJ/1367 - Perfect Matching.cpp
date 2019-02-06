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

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
#define MAX_N 605

ll GaussianElimination(int n, vector<bitset<MAX_N>> a)
{
	ll det = 1;
	for (int col = 0, row = 0; col < n && row < n; col++)
	{
		for (int i = row; i < n; i++)
		{
			if (a[i][col])
			{
				swap(a[i], a[row]);
				break;
			}
		}

		if (!a[row][col])
			return 0;

		det *= (a[row][col]);

		for (int i = 0; i < n; i++)
			if (i != row && a[i][col])
				a[i] ^= a[row];
		row++;
	}

	return det;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		string str;
		vector<bitset<MAX_N>> a(MAX_N);
		FOR(i, 0, n)
		{
			cin >> str;
			FOR(j, 0, n)
			{
				if (str[j] == '1')
					a[i][j] = 1;
				else
					a[i][j] = 0;
			}
		}

		ll det = GaussianElimination(n, a);

		if (det != 0)
			cout << "Odd" << endl;
		else
			cout << "Even" << endl;
	}

	return 0;
}

//======================================================================================================================