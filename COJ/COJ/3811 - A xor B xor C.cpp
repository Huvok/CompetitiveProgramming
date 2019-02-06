#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <queue>
#include <string.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll arr[1500];

int main()
{
	ll n, k;
	cin >> n >> k;

	FOR(i, 0, n)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	ll cur;
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			cur = k ^ arr[i] ^ arr[j];

			if (i == j)
				continue;

			auto it = lower_bound(arr, arr + n, cur) - arr;

			if (it == i ||
				it == j)
			{
				while (it < n &&
					(it == i ||
						it == j))
					it++;
			}
			
			if (it >= n)
				continue;

			if (arr[it] == cur)
			{
				cout << "YES" << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;
	return 0;
}