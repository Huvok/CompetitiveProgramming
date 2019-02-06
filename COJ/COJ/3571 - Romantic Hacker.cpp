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
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a) - 1; i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

double a[2100];
double aux[2100];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];

	ll cur = 1;
	while (cur <= n / 2)
	{
		FOR(i, 0, cur)
		{
			aux[2 * i] = a[i] + a[cur + i];
			aux[2 * i + 1] = a[i] - a[cur + i];
		}

		FOR(i, 0, cur * 2)
			a[i] = aux[i];

		cur *= 2;
	}

	FOR(i, 0, n)
		cout << (ll)(a[i] + .5) << " ";

	cout << endl;

	return 0;
}