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

const double EPS = .000000001;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
vector<string> ans;

void solve(map<ll, ll> &m, string cur, ll left)
{
	if (left == 0)
		ans.pb(cur);
	else
	{
		for (auto it : m)
		{
			ll cnt = it.second;
			if (cnt > 0)
			{
				m[it.first] = cnt - 1;
				solve(m, cur + (char)(it.first > 150 ? it.first - 100 : it.first), left - 1);
				m[it.first] = cnt;
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	string str;

	cin >> n;

	while (n--)
	{
		cin >> str;
		ans.clear();
		map<ll, ll> m;
		FOR(i, 0, sz(str))
		{
			if (str[i] < 96)
				m[str[i] + 100]++;
			else
				m[str[i]]++;
		}

		solve(m, "", sz(str));
		FOR(i, 0, sz(ans))
			cout << ans[i] << endl;
	}

	return 0;
}

//======================================================================================================================