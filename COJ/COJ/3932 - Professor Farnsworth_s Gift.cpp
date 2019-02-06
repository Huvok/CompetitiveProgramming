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
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define mem(x, val) memset((x), (val), sizeof(x))
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

const double EPS = .000000001;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

ll a[25];
ll sieve[1000005];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		sort(all(s));
		if (s[0] == '-')
		{
			reverse(s.begin() + 1, s.end());
			if (s[1] == '0')
			{
				FOR(i, 1, sz(s))
				{
					if (s[i] != '0')
					{
						swap(s[i], s[1]);
						break;
					}
				}
			}
		}
		else
		{
			if (s[0] == '0')
			{
				FOR(i, 0, sz(s))
				{
					if (s[i] != '0')
					{
						swap(s[i], s[0]);
						break;
					}
				}
			}
		}

		cout << s << endl;
	}

	return 0;
}

//======================================================================================================================