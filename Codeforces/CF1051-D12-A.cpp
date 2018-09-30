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
//                                          //IDEA: Try to complete the characters only using the first 3.

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

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sync;

	ll n;
	cin >> n;

	FOR(i, 0, n)
	{
		string str;
		cin >> str;
		ll a = 0, b = 0, c = 0;
		FOR(j, 0, sz(str))
		{
			if (str[j] < 58)
				a++;
			else if (str[j] < 97)
				b++;
			else
				c++;
		}

		if (a == 0 && b == 0 && c == 0)
		{
			str[0] = 'A';
			str[1] = 'b';
			str[3] = '3';
		}
		else if (b == 0 && c == 0)
		{
			if (str[0] < 58)
			{
				str[1] = 'A';
				str[2] = 'b';
			}
			else
			{
				if (str[1] < 58)
				{
					str[0] = 'A';
					str[2] = 'b';
				}
				else
				{
					str[0] = 'A';
					str[1] = 'b';
				}
			}
		}
		else if (a == 0 && c == 0)
		{
			if (str[0] < 97 && str[0] > 58)
			{
				str[1] = '3';
				str[2] = 'b';
			}
			else
			{
				if (str[1] < 97 && str[1] > 58)
				{
					str[0] = '3';
					str[2] = 'b';
				}
				else
				{
					str[0] = '3';
					str[1] = 'b';
				}
			}
		}
		else if (a == 0 && b == 0)
		{
			if (str[0] >= 97)
			{
				str[1] = 'A';
				str[2] = '3';
			}
			else
			{
				if (str[1] >= 97)
				{
					str[0] = 'A';
					str[2] = '3';
				}
				else
				{
					str[0] = 'A';
					str[1] = '3';
				}
			}
		}
		else if (a == 0)
		{
			if (b > 1)
			{
				if (str[0] < 97)
					str[0] = '5';
				else
					str[1] = '5';
			}
			else
			{
				if (str[0] < 97)
					str[1] = '5';
				else
					str[0] = '5';
			}
		}
		else if (b == 0)
		{
			if (a > 1)
			{
				if (str[0] < 58)
					str[0] = 'A';
				else
					str[1] = 'A';
			}
			else
			{
				if (str[0] < 58)
					str[1] = 'A';
				else
					str[0] = 'A';
			}
		}
		else if (c == 0)
		{
			if (a > 1)
			{
				if (str[0] < 58)
					str[0] = 'a';
				else
					str[1] = 'a';
			}
			else
			{
				if (str[0] < 58)
					str[1] = 'a';
				else
					str[0] = 'a';
			}
		}

		cout << str << endl;
	}

	return 0;
}

//======================================================================================================================