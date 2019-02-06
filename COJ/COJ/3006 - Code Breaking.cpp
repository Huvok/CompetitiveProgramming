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

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define readarr(a, b) FOR(i, 0, (b)) scanf("%lld", &(a)[i])
#define sz(x) (ll)(x).size()
#define sc(x) scanf("%lld", &(x))
#define debug(...) fprintf(stderr, VA_ARGS), fflush(stderr)
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define find(x, val) (x).find((val)) != (x).end()

const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
#define MOD 1234567
ll parents[20005];
ll dpThree[70000], dpPath[70000], acums[70000];
vi adj[70000];
unordered_map<ll, ll> dp[20005];
ll n, m;

ll segmentTree[20005 * 2], ss;

struct node
{
	ll code, id;

	node(ll a, ll b) : code(a), id(b) {}

	bool operator ==(const node o) const
	{
		return o.code == code && o.id == id;
	}

	bool operator <(const node o) const
	{
		if (code == o.code)
			return id < o.id;
		return code < o.code;
	}
};

vector<node> adjPaths[20005];

ll fastPow(ll x, ll n, ll m)
{
	ll ret = 1;
	while (n)
	{
		if (n & 1) ret = ret * x % m;
	x = x * x % m;
	n >>= 1;
	}

	return ret;
}

void precalcSegmentTree()
{
	FOR(i, 0, 20005 * 2)
	{
		segmentTree[i] = 1;
	}
}

void modify(ll n)
{
	while (n >>= 1)
	{
		segmentTree[n] = (segmentTree[n << 1] % MOD * segmentTree[n << 1 | 1] % MOD) % MOD;
	}
}

void query(ll idx, ll cur);

void propagate(ll idx, ll cur, vi path)
{
	dpThree[cur] = segmentTree[1];
	FOR(i, 0, sz(adj[cur]))
		query(idx, adj[cur][i]);

	ll j = 0;
	FOR(i, acums[cur], sz(adjPaths[idx]))
	{
		if (adjPaths[idx][i].code != cur)
			break;

		segmentTree[ss + adjPaths[idx][i].id] = path[j];
		j++;
		modify(ss + adjPaths[idx][i].id);
	}
}

unordered_set<ll> three[20005], four[20005];
void query(ll idx, ll cur)
{
	vi path;
	FOR(i, acums[cur], sz(adjPaths[idx]))
	{
		if (adjPaths[idx][i].code != cur)
			break;

		ll aux = dp[adjPaths[idx][i].id][cur];
		ll aux2 = segmentTree[ss + adjPaths[idx][i].id];
		segmentTree[ss + adjPaths[idx][i].id] = aux;
		aux = aux2;
		modify(ss + adjPaths[idx][i].id);
		path.pb(aux);
	}

	propagate(idx, cur, path);
}

void init()
{
	mem(dpPath, -1);
	mem(segmentTree, 0);

	ss = 1 << (ll)ceil(log2(n));
	FOR(i, 0, n)
	{
		three[i].insert(0);

		if (i > 0)
		{
			cin >> parents[i];
			adjPaths[parents[i]].pb(node(0, i));
		}
	}
}

ll hexEncode(string str)
{
	ll ret = 0;
	FOR(j, 0, sz(str))
	{
		ll digit = str[j] - '0';
		ret = ret | digit;
		ret++;
		if (j < sz(str) - 1)
			ret = ret << 4;
	}

	return ret;
}

void setIt(ll idx, ll a, ll b, ll c) { dpPath[idx] = a; (b == -1 ? adj[idx].clear() : adj[idx].pb(b)); acums[idx] = c; }

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sync;
	cin >> n >> m;

	mem(parents, -1);
	init();
	ll from;
	string str;
	FOR(i, 0, m)
	{
		cin >> from >> str;
		ll sequence = hexEncode(str);

		four[from].insert(sequence);

		for (ll j = 16; j >= 4; j = j - 4, from = parents[from])
		{
			ll ecneuqes = sequence;
			ecneuqes &= ((1LL << j) - 1);
			three[from].insert(ecneuqes);
			adjPaths[parents[from]].pb(node(ecneuqes, from));
		}
	}

	FOR(i, 0, n)
	{
		sort(all(adjPaths[i]));
		vector<node> aux;

		if (sz(adjPaths[i]))
			aux.pb(adjPaths[i][0]);
		FOR(j, 1, sz(adjPaths[i]))
		{
			if (adjPaths[i][j] == adjPaths[i][j - 1])
				continue;
			aux.pb(adjPaths[i][j]);
		}

		swap(adjPaths[i], aux);
	}

	ss = 20005;
	precalcSegmentTree();

	ll cur = n - 1;
	while (cur >= 0)
	{
		if (sz(adjPaths[cur]) == 0)
			query(cur, 0);

		FOR(i, 0, sz(adjPaths[cur]))
		{
			ll sequence = adjPaths[cur][i].code;

			if (sequence != 0 &&
				(!i ||
					sequence != adjPaths[cur][i - 1].code))
			{
				setIt(sequence, cur, -1, i);

				for (; sequence >> 4 != 0 && !(dpPath[sequence >> 4] == cur); sequence = sequence >> 4)
					setIt(sequence >> 4, cur, sequence, i), adj[sequence >> 4] = vi(1, sequence);

				adj[sequence >> 4].pb(sequence);
			}

			if (i == sz(adjPaths[cur]) - 1)
				query(cur, 0);
		}

		for (auto j : three[cur])
		{
			ll sequence = j;
			while (sequence &&
				sequence < 4096)
			{
				sequence = sequence << 4;
			}

			ll ans = 0;
			FOR(d, 1, 11)
			{
				ll mask = d << 16;
				if (!(find(four[cur], mask | sequence)))
				{
					mask = mask | sequence;
					mask = mask >> 4;
					while (mask != 0)
					{
						if (dpPath[mask] == cur)
							break;

						mask = mask >> 4;
					}

					ans += dpThree[mask];
					ans %= MOD;
				}
			}

			dp[cur][j] = ans;
		}

		setIt(0, 0, -1, 0);
		cur--;
	}

	ll ans = 0;
	FOR(i, 0, 65536)
		ans = max(ans, dp[0][i]);

	cout << (fastPow(10, n, MOD) - ans + MOD) % MOD << endl;

	return 0;
}

//======================================================================================================================