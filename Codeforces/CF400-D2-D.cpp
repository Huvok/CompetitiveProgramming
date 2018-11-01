#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

//                                                          // AUTHOR: Hugo Garcia
// Create a DSU and unite all cells with edge of cost 0. Then, iterate over every cell and check if it is inside the
// same component as the first cell of that type. If no, answer is no. After that, run floyd-warshall over types of cells.

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
#define sz(x) (ll)(x).size()
#define endl '\n'
#define oo 2000000000000000000LL
#define EPS 1e-6

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define MOD 1000000007

//----------------------------------------------------------------------------------------------------------------------
class UnionFind
{
private:
	vi p, rank;
public:
	UnionFind(ll N) {
		rank.assign(N, 0);
		p.assign(N, 0);

		for (ll i = 0; i < N; ++i)
			p[i] = i;
	}

	ll findSet(ll i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(ll i, ll j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(ll i, ll j) {
		if (!isSameSet(i, j)) {
			ll x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y])
				p[y] = x;
			else {
				p[x] = y;

				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};

ll dp[505][505];
ll who[100005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll v, e, k;
	cin >> v >> e >> k;
	FOR(i, 1, k + 1) {
		FOR(j, 1, k + 1) {
			dp[i][j] = oo;
		}

		dp[i][i] = 0;
	}

	vi starts;
	ll cur = 1;
	ll j = 1;
	FOR(i, 0, k) {
		ll x;
		cin >> x;
		starts.pb(cur);
		cur += x;
		while (j < cur)
			who[j++] = i + 1;
	}

	UnionFind dsu(v + 1);
	FOR(i, 0, e) {
		ll s, d, w;
		cin >> s >> d >> w;

		if (w == 0)
			dsu.unionSet(s, d);

		s = who[s];
		d = who[d];
		dp[s][d] = dp[d][s] = min(dp[s][d], w);
	}

	bool can = true;
	FOR(i, 1, v + 1) {
		ll hue = starts[who[i] - 1];
		if (!dsu.isSameSet(hue, i)) {
			can = false;
			break;
		}
	}

	if (can) {
		cout << "Yes" << endl;
		FOR(l, 1, k + 1) {
			FOR(i, 1, k + 1) {
				FOR(j, 1, k + 1) {
					dp[i][j] = min(dp[i][j], dp[i][l] + dp[l][j]);
				}
			}
		}

		FOR(i, 1, k + 1) {
			FOR(j, 1, k + 1) {
				if (dp[i][j] == oo)
					cout << -1 << " ";
				else
					cout << dp[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
		cout << "No" << endl;

	return 0;
}

