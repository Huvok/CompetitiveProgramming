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
//                                          //IDEA: Lets say the root of a tree has three children, the main string
//                                          //      will be composed of three parts. Each part divides in the amount
//                                          //      of children they have. Two strings are equal if each of their parts
//                                          //      is present in the other one, so lets make some kind of dfs, you will
//                                          //      always open (0) before closing (1) so if s[i] is a 0, recurse to
//                                          //      the next part. The minimum part is always 01, then when you come
//                                          //      back, to recurse to the next part, you go to i + sz(lastpart).
//                                          //      You put each part at that level at that subtree in a vector and sort
//                                          //      them. Do the same for the second string, and you will have each part
//                                          //      in order at the end.

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
string s;
string get(ll i)
{
	if (i > sz(s))
		return "";

	vector<string> v;
	while (i < sz(s) &&
		s[i] == '0')
	{
		v.pb("0" + get(i + 1));
		i += v.back().size();
	}

	sort(all(v));

	string ret = "";
	FOR(i, 0, sz(v))
		ret += v[i];

	ret += "1";
	return ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll t;
	cin >> t;

	while (t--)
	{
		cin >> s;
		string a = get(0);
		cin >> s;
		string b = get(0);

		if (a == b)
			cout << "same" << endl;
		else
			cout << "different" << endl;
	}

	return 0;
}

//======================================================================================================================