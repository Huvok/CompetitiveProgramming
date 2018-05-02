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

using namespace std;

//                                          //AUTHOR: Hugo Garcia
//                                          //IDEA: First lets supppose we need N=5, M=3, K=2, we can have a palindrome
//                                          //      starting at the index 0 and another starting at the 2nd, but if
//                                          //      we fix the second character of the third character of the first
//                                          //      palindrome, we are also fixing the first and third characters of
//                                          //      the second palindrome, so lets build a graph with these characters
//                                          //      connected and count how many free characters we have in total (many
//                                          //      linked characters count as one free character). Finally, we must
//                                          //      use Inclusion-Exclusion due to multiple counting (explained below).

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
class PalindromfulString
{
public:
	ll marked[(1LL << 12)];
	vi adj[15];
	bool vis[15];

	void dfs(ll i)
	{
		vis[i] = true;

		FOR(j, 0, sz(adj[i]))
		{
			ll v = adj[i][j];

			if (!vis[v])
			{
				dfs(v);
			}
		}
	}

	ll fastPow(ll x, ll n)
	{
		ll ret = 1;
		while (n)
		{
			if (n & 1)
				ret = ret * x;
			x = x * x;
			n >>= 1;
		}

		return ret;
	}

	ll countBits(ll x)
	{
		ll cnt = 0;
		while (x)
		{
			if (x & 1)
				cnt++;

			x >>= 1;
		}

		return cnt;
	}

	long long count(int N, int M, int K)
	{
		// Make N - M groups, meaning the minimum number of palindromes needed
		ll possibleGroupsLimit = N - M + 1;
		ll bitmaskLimit = (1LL << possibleGroupsLimit);
		ll ans = 0;
		mem(marked, 0);

		FOR(i, 0, bitmaskLimit)
		{
			if (countBits(i) >= K)
				marked[i] = 1;
		}

		// Try every subset of groups. Only those with at least K palindromes (i.e. K on bits or K places where a group
		//      start, for example if the kth bit is on, a group will start on the kth character and end on the
		//      (k + M)th character.
		FOR(i, 0, bitmaskLimit)
		{
			if (marked[i] != 0)
			{
				FOR(j, 0, N)
				{
					adj[j].clear();
				}

				// We need to "link" the characters of the palindromes. For example, we want N=3, M=2, K=2
				// A valid combination would be to link the first to the second character and the second to the third,
				//      so in the graph the first, second and third nodes would be connected since fixing a character
				//      to the first node also fixes a character to the other two nodes.
				FOR(j, 0, possibleGroupsLimit)
				{
					if ((i & (1 << j)) > 0)
					{
						ll l = j, r = j + M - 1;
						while (l < r)
						{
							adj[l].pb(r);
							adj[r].pb(l);
							l++;
							r--;
						}
					}
				}

				mem(vis, 0);
				ll cnt = 0;

				// This is equivalent to counting how many independent characters we have, 26 possibilities for each one.
				FOR(j, 0, N)
				{
					if (!vis[j])
					{
						cnt++;
						dfs(j);
					}
				}

				ans += marked[i] * fastPow(26LL, cnt);

				// Inclusion-Exclusion: Supose we added to the answer the palindromes 110 and 011 (N=3, M=2, K=1) we have counted something like
				//      AAA twice, since the first two A's are fixed due to the 110 and the third A is one possibility, put once again in 011 we
				//      have the same, so when we reach 111 we have to know how many times we have counted this combination and above the
				//      multiplication takes care of substracting it.
				FOR(j, i + 1, bitmaskLimit)
				{
					if (i == (i & j))
					{
						marked[j] -= marked[i];
					}
				}
			}
		}

		return ans;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	PalindromfulString hue;
	cout << hue.count(2, 2, 1) << endl;
	cout << hue.count(2, 2, 0) << endl;
	cout << hue.count(3, 2, 1) << endl;
	cout << hue.count(4, 4, 1) << endl;
	cout << hue.count(7, 3, 3) << endl;

	return 0;
}

//======================================================================================================================