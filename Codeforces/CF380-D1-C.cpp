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
#  define __builtin_popcountll __popcnt64
#endif

using namespace std;

//                                          //AUTHOR: Hugo Garcia
// Use a segment tree where each node will store three numbers: a, b and c. a is the answer for the range, b the
// number of openings and c the closings. For a father, calculate the new amount of closings, which is, for its children
// x and y, min(x.b, y.c). Then, for the father, its a is x.a + y.a + new, its b is x.b + y.b - new and
// c is x.c + y.c - new.

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
#define sz(x) (ll)(x).size()
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
#define maxN 1000005
struct boi {
	ll a, b, c;
	boi() { a = 0; b = 0; c = 0; }
	boi(ll _a, ll _b, ll _c) { a = _a; b = _b; c = _c; }
};

boi segmentTree[3 * maxN];
ll ss;
ll a[maxN];
ll n;

void precalcSegmentTree()
{
	FOR(i, 0, n) {
		if (a[i])
			segmentTree[ss + i].b = 1;
		else
			segmentTree[ss + i].c = 1;
	}

	for (ll i = ss - 1; i; i--) {
		ll common = min(segmentTree[i << 1].b, segmentTree[i << 1 | 1].c);
		segmentTree[i].a = segmentTree[i << 1].a + segmentTree[i << 1 | 1].a + common;
		segmentTree[i].b = segmentTree[i << 1].b + segmentTree[i << 1 | 1].b - common;
		segmentTree[i].c = segmentTree[i << 1].c + segmentTree[i << 1 | 1].c - common;
	}
}

boi query(ll n, ll l, ll r, ll d)
{
	if (l > r) {
		boi ret;
		return ret;
	}

	if (!l &&
		r == d - 1)
		return segmentTree[n];

	d /= 2;
	boi ret = boi();
	boi a = query(n << 1, l, min(d - 1, r), d);
	boi b = query(2 * n + 1, max(0LL, l - d), r - d, d);
	ll common = min(a.b, b.c);
	ret.a = a.a + b.a + common;
	ret.b = a.b + b.b - common;
	ret.c = a.c + b.c - common;

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	string str;
	cin >> str;
	n = sz(str);
	FOR(i, 0, n) {
		if (str[i] == '(')
			a[i] = 1;
		else
			a[i] = 0;
	}

	ss = 1LL << (ll)ceil(log2(n));
	precalcSegmentTree();

	ll q;
	cin >> q;
	while (q--) {
		ll l, r;
		cin >> l >> r;
		boi ans = query(1, l - 1, r - 1, ss);
		cout << ans.a * 2 << endl;
	}

	return 0;
}