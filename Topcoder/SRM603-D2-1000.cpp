#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// dp[i][j] means the probability of winning starting at the ith node and playing one or more turns.
// Lets recurse to all v that has an edge from i, and dp[i][j] is the max of all of them,
// where an answer is winprob[v] + k, where the first part is winning in v, and k is
// the probability of winning in the next j - 1 turns i.e. dp[v][j - 1] * (1 - winprob[v] - loseprob[v]) since
// to play the next turns we need that nothing happens in the current one.

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define lld I64d
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ii, ll>> viii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
class GraphWalkWithProbabilities {
public:
	double dp[55][5005];
	double findprob(vector <string> graph, vector <int> winprob, vector <int> looseprob, int Start) {
		FOR(i, 0, sz(graph))
			dp[i][0] = 0.;
		
		FOR(j, 1, 5005) {
			FOR(i, 0, sz(graph)) {
				dp[i][j] = 0.;
				FOR(v, 0, sz(graph)) {
					if (graph[i][v] == '1') {
						dp[i][j] = max(dp[i][j], winprob[v] / 100. + dp[v][j - 1] * (100 - winprob[v] - looseprob[v]) / 100.);
					}
				}
			}
		}

		return dp[Start][5000];
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;
	
	

	return 0;
}