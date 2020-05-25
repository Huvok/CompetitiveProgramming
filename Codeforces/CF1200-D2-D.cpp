#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	
//                                                          // AUTHOR: Hugo Garcia
	
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
ll mat[2005][2005];
ii rows[2005], cols[2005];
ll srows[2005][2005], scols[2005][2005];

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	ll n, k;
	cin >> n >> k;
	FOR(i, 0, n) {
		string str;
		cin >> str;
		FOR(j, 0, n) {
			if (str[j] == 'W')
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
	}

	mem(rows, -1);
	mem(cols, -1);
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			if (mat[i][j] == 0) {
				if (rows[i].first == -1)
					rows[i].first = j;
				if (cols[j].first == -1)
					cols[j].first = i;
				rows[i].second = j;
				cols[j].second = i;
			}
		}
	}

	ll wh = 0;
	FOR(i, 0, n) {
		if (rows[i].first == -1)
			wh++;
		if (cols[i].first == -1)
			wh++;
	}

	ll curRows = 0, curCols = 0;
	ll sumCols = 0, sumRows = 0;
	FOR(i, 0, n - k + 1) {
		sumCols = 0;
		curCols = 0;
		FOR(j, 0, n - k + 1) {
			while (curCols <= j + k - 1) {
				if (cols[curCols].first != -1 &&
					cols[curCols].first >= i &&
					cols[curCols].second <= i + k - 1)
					sumCols++;
				curCols++;
			}

			scols[i][j] = sumCols;

			if (cols[j].first != -1 &&
				cols[j].first >= i &&
				cols[j].second <= i + k - 1)
				sumCols--;
		}
	}

	FOR(j, 0, n - k + 1) {
		sumRows = 0;
		curRows = 0;
		FOR(i, 0, n - k + 1) {
			while (curRows <= i + k - 1) {
				if (rows[curRows].first != -1 &&
					rows[curRows].first >= j &&
					rows[curRows].second <= j + k - 1)
					sumRows++;
				curRows++;
			}

			srows[i][j] = sumRows;

			if (rows[i].first != -1 &&
				rows[i].first >= j &&
				rows[i].second <= j + k - 1)
				sumRows--;
		}
	}

	ll champ = 0;
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			champ = max(champ, srows[i][j] + scols[i][j]);
		}
	}

	cout << champ + wh << endl;

	return 0;
}