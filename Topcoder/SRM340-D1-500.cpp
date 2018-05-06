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
#  define __builtin_popcount __popcnt
#endif

using namespace std;

//                                          //AUTHOR: Hugo Garcia
//                                          //IDEA: The first thing to notice is that if you get an answer of x courses
//                                          //      after n days, where the maximum expire of the x courses is y, then
//                                          //      you can get this answer in y days (y <= n). Let dp[i][j][k] be
//                                          //      the minimum amount of courses you need to take to get from the ith
//                                          //      day with j tv and k pv to any state that fulfills the skillBound.
//                                          //      The minimum amount to get j and k on the ith day is i, so make
//                                          //      everything in dp infinity except all the j and k values greater than
//                                          //      the threshold given (skillBound), make those i. If there an answer,
//                                          //      you can get from any of those non infinity values to dp[0][0][0].
//                                          //      Then start from the y - 1 th day. Check every course l and if the
//                                          //      lth's tv and pv are at most 1 unit bigger than the current j and k,
//                                          //      check if your answer for dp[i][j][k] will get better by taking
//                                          //      the amount of courses of dp[i + 1][max(j, lj)][max(k, lk)], which
//                                          //      means taking one more day (i + 1) to take the course that will
//                                          //      probably make your j or k better, taking the minimum amount of
//                                          //      courses (stored at dp[i + 1]...) needed to get to any valid state.
//                                          //      To reconstruct the answer, everytime you update dp, store the course
//                                          //      l into another array (in my case dpk[i][j][k]). To reconstruct the
//                                          //      answer start at dpk[0][0][0] which has the first course you should
//                                          //      take and start applying it until you get to any valid state (or
//                                          //      you can just do this dp[0][0][0] times since it has stored the
//                                          //      minimum amount of courses needed).

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
#define oo 100000000000000000

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll dp[55][55][55];
ll dpk[55][55][55];

class CsCourses
{
public:
	vector <int> getOrder(vector <int> theoreticalValue, vector <int> practicalValue, vector <int> expire, int skillBound)
	{
		mem(dp, -1);
		ll n = sz(theoreticalValue);

		FOR(i, 0, 55)
		{
			FOR(j, 0, 55)
			{
				FOR(k, 0, 55)
				{
					dp[i][j][k] = oo;
				}
			}
		}

		FOR(i, 0, n + 1)
		{
			FOR(j, skillBound, 55)
			{
				FOR(k, skillBound, 55)
				{
					dp[i][j][k] = i;
					dpk[n][j][k] = -1;
				}
			}
		}

		ROF(i, n - 1, 0)
		{
			FOR(j, 0, 55)
			{
				FOR(k, 0, 55)
				{
					ROF(l, n - 1, 0)
					{
						if (expire[l] > i)
						{
							if (j >= theoreticalValue[l] - 1 &&
								k >= practicalValue[l] - 1)
							{
								ll a = max(j, (ll)theoreticalValue[l]);
								ll b = max(k, (ll)practicalValue[l]);

								if (dp[i + 1][a][b] != oo &&
									dp[i][j][k] >= dp[i + 1][a][b])
								{
									dp[i][j][k] = dp[i + 1][a][b];
									dpk[i][j][k] = l;
								}
							}
						}
					}
				}
			}
		}

		vector<int> ans;
		if (dp[0][0][0] != oo)
		{
			ll j = 0, k = 0;
			FOR(i, 0, dp[0][0][0])
			{
				ll v = dpk[i][j][k];
				j = max(j, (ll)theoreticalValue[v]);
				k = max(k, (ll)practicalValue[v]);
				ans.pb(v);
			}
		}

		return ans;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;

	vector<int> ans;
	CsCourses cs;
	vector<int> theo, pract, expire;
	theo = { 1, 2, 1 };
	pract = { 2, 1, 1 };
	expire = { 3, 2, 1 };
	ans = cs.getOrder(theo, pract, expire, 2);

	return 0;
}

//======================================================================================================================