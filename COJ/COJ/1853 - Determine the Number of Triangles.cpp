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
#define debug(...) fprintf(stderr, _VA_ARGS_), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll a[15];

bool dif(ll a, ll b, ll c, ll d)
{
	return a != c || b != d;
}

bool coll(ll a, ll b, ll c, ll d, ll e, ll f)
{
	if ((a * (d - f) + c * (f - b) + e * (b - d)) == 0)
		return true;
	return false;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	FOR(i, 0, 11)
	{
		FOR(j, 0, 11)
		{
			FOR(k, i, 11)
			{
				FOR(l, 0, 11)
				{
					if (k == i &&
						!l)
						l = j;

					FOR(x, k, 11)
					{
						FOR(y, 0, 11)
						{
							if (x == k &&
								!y)
								y = l;

							if (dif(i, j, k, l) &&
								dif(k, l, x, y) &&
								dif(i, j, x, y))
							{
								if (!coll(i, j, k, l, x, y))
									a[max(x, max(y, max(i, max(j, max(k, l)))))]++;
							}
						}
					}
				}
			}
		}
	}

	FOR(i, 1, 11)
		a[i] += a[i - 1];

	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		cout << a[n] << endl;
	}

	return 0;
}

//======================================================================================================================