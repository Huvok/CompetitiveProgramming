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
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

typedef tree<ll, null_type, less<ll>, rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n;
	cin >> n;
	ll x;
	indexed_set s;
	FOR(i, 0, n)
	{
		cin >> x;
		s.insert(x);
		cout << s.order_of_key(x) + 1 << '\n';
	}

	return 0;
}