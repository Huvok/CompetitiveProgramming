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
#define MAX_N 200010
char T[MAX_N];
ll n;
ll RA[MAX_N], tempRA[MAX_N];
ll SA[MAX_N], tempSA[MAX_N];
ll c[MAX_N];

void countingSort(ll k)
{
	ll sum, maxi = max(300LL, n);
	mem(c, 0);

	FOR(i, 0, n)
		c[i + k < n ? RA[i + k] : 0]++;

	for (ll i = sum = 0; i < maxi; i++)
	{
		ll t = c[i]; 
		c[i] = sum; 
		sum += t;
	}

	FOR(i, 0, n)
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];

	FOR(i, 0, n)
		SA[i] = tempSA[i];
}

void constructSA()
{
	ll r;
	FOR(i, 0, n)
	{
		RA[i] = T[i];
		SA[i] = i;
	}

	for (ll k = 1; k < n; k <<= 1)
	{
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;

		FOR(i, 1, n)
		{
			tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] &&
				RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		}

		FOR(i, 0, n)
			RA[i] = tempRA[i];

		if (RA[SA[n - 1]] == n - 1)
			break;
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	scanf("%s", &T);
	n = (ll)strlen(T);
	FOR(i, 0, n)
		T[n + i] += T[i];
	n *= 2;
	T[n++] = '|';

	constructSA();

	FOR(i, 0, n)
	{
		if (SA[i] + 1 > 0 &&
			SA[i] + 1 <= (n - 1) / 2)
			printf("%lld\n", SA[i] + 1);
	}

	return 0;
}

//======================================================================================================================