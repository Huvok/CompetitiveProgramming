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

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
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

ll a[100005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll n, k;
	cin >> n >> k;

	ll ori = n;
	ll cur = 0;
	ll small = 1;
	ll big = n;
	n--;
	while (n >= 0)
	{
		if (k >= n)
		{
			a[cur] = big;
			k -= n;
			n--;
			big--;
			cur++;
		}
		else
		{
			a[cur] = small;
			small++;
			n--;
			cur++;
		}
	}

	FOR(i, 0, ori)
	{
		cout << a[i] << " ";
	}

	cout << endl;

	return 0;
}