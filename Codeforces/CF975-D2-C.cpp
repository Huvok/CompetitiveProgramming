﻿#include <cmath>
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

using namespace std;

//                                          //AUTHOR: Hugo Garcia
//                                          //IDEA: Get the partial sums of the warriors' health and for every query
//                                          //      maintain a pointer that tells you which one is the front warrior.
//                                          //      Then do a binary search to get to the last warrior that dies this
//                                          //      turn using the partial sums of the BS and the one of the pointer.

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

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll a[200005], dp[200005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	ll n, q;
	cin >> n >> q;
	FOR(i, 0, n)
	{
		cin >> a[i];
	}

	dp[0] = a[0];
	FOR(i, 1, n)
		dp[i] = a[i] + dp[i - 1];

	ll x;
	ll cur = 0;
	ll cum = 0;
	FOR(i, 0, q)
	{
		cin >> x;
		auto it = upper_bound(dp + cur, dp + n, x + cum) - dp;
		cur = it;
		cum += x;
		if (it >= n)
		{
			cur = 0;
			cum = 0;
		}

		cout << n - cur << endl;
	}

	return 0;
}

//======================================================================================================================