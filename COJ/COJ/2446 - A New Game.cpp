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

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	string a, b;
	cin >> a >> b;
	ll x, y;
	sort(all(b));
	if (a == "BBB")
		x = 1;
	else if (a == "WWW")
		x = 3;
	else
		x = 2;

	if (b == "BBB")
		y = 1;
	else if (b == "WWW")
		y = 3;
	else if (b == "BBW")
		y = 1;
	else
		y = 3;

	if (x == 1 && y == 3)
		cout << "Bianka won with Rock" << endl << "Williams lost with Scissors" << endl;
	else if (x == 2 && y == 3)
		cout << "Williams won with Scissors" << endl << "Bianka lost with Paper" << endl;
	else if (x == 2)
		cout << "Bianka won with Paper" << endl << "Williams lost with Rock" << endl;
	else if (x == 3)
		cout << "Williams won with Rock" << endl << "Bianka lost with Scissors" << endl;

	return 0;
}

//======================================================================================================================