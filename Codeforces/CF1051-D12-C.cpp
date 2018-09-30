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
//                                          //IDEA: Forget about duplicates. If number of elements that appear only
//                                          //      once is even, split them in half and put the other elements on
//                                          //      one half. If it is odd, take one element that appears > 2 times
//                                          //      and use one of its appearances to complete the single count.

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
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
ll a[105];
ll freq[105];
ll marks[105];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;

	ll single = 0, db = 0, bad = 0;
	ll n;
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	FOR(i, 0, n)
		freq[a[i]]++;

	FOR(i, 0, 101)
	{
		if (freq[i] > 0)
		{
			if (freq[i] == 1)
			{
				single++;
				marks[i] = 1;
			}
			else if (freq[i] == 2)
			{
				db++;
				marks[i] = 2;
			}
			else
			{
				bad++;
				marks[i] = 3;
			}
		}
	}

	ll mode = 0;
	if (single % 2 == 0)
		mode = 1;
	else if (bad > 0)
		mode = 2;
	else
	{
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	bool tg = 1;
	FOR(i, 0, n)
	{
		if (marks[a[i]] == 2)
			cout << 'A';
		else if (marks[a[i]] == 3)
		{
			if (mode == 2)
			{
				cout << 'B';
				mode = 1;
			}
			else
				cout << 'A';
		}
		else
		{
			if (tg)
			{
				cout << 'A';
			}
			else
				cout << 'B';

			tg = !tg;
		}
	}

	cout << endl;

	return 0;
}

//======================================================================================================================