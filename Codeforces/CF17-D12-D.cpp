#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//                                                          // AUTHOR: Hugo Garcia
// The answer is obviously b ^ (n - 1) * (b - 1) mod c. First b = b % c. Then,
// You need to calculate A ^ B % C where B is really big. First factorize C and use
// CRT. For each modulo, a power prime, check if it divides A, if it does not, use
// euler theorem since A ^ B mod C == A ^ (B mod phi(C)) mod C. If the modulo divides
// A, check if B is equal or greater than the power of that prime. If it is, the answer is 0,
// if it is smaller, you can naively calculate it.

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
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
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
ll getIt(string a, ll mod) {
	ll ret = 0;
	FOR(i, 0, sz(a)) {
		ret = ret * 10 % mod;
		ret = (ret + (a[i] - '0')) % mod;
	}

	return ret;
}

vii getFactors(ll n) {
	vii ret;
	ll step = 1;
	for (ll i = 2; i * i <= n; i += step, step = 2)
	{
		if (n % i == 0)
		{
			ret.pb(mp(i, 0));
			while (n % i == 0)
			{
				n /= i;
				ret.back().second++;
			}
		}
	}

	if (n != 1)
		ret.pb(mp(n, 1));

	return ret;
}

ll fastPow(ll x, ll n, ll m) {
	ll ret = 1;
	while (n > 0) {
		if (n & 1) ret = ret * x % m;
		x = x * x % m;
		n = n >> 1;
	}

	return ret;
}

bool checkGt(string a, ll b) {
	string x = to_string(b);
	if (sz(a) > sz(x))
		return true;
	else if (sz(a) < sz(x))
		return false;

	ROF(i, sz(a) - 1, 0) {
		if (a[i] > x[i])
			return true;
		else if (a[i] < x[i])
			return false;
	}

	return true;
}

string substract(string x) {
	string ret = x;
	if (ret[sz(ret) - 1] == '0'){
		ret[sz(ret) - 1] = '9';
		ROF(i, sz(ret) - 2, 0) {
			if (ret[i] != '0') {
				ret[i] = ret[i] - 1;
				break;
			}

			ret[i] = '9';
		}
	}
	else
		ret[sz(ret) - 1] = ret[sz(ret) - 1] - 1;
	
	return ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main() {
	sync;

	string inputB, inputN;
	ll inputC;
	cin >> inputB >> inputN >> inputC;
	inputN = substract(inputN);
	ll A = getIt(inputB, inputC);
	vii factors = getFactors(inputC);

	vi as, cs;
	FOR(i, 0, sz(factors)) {
		ll cur = 1;
		ll limit = factors[i].second;
		FOR(j, 0, limit)
			cur *= factors[i].first;
		if (A % factors[i].first != 0) {
			ll B = getIt(inputN, cur - (cur / factors[i].first));
			as.pb(fastPow(A, B, cur));
		}
		else {
			if (checkGt(inputN, factors[i].second))
				as.pb(0);
			else {
				ll B = getIt(inputN, cur);
				as.pb(fastPow(A, B, cur));
			}
		}

		ll m = inputC / cur;
		cs.pb(m * (fastPow(m, cur - (cur / factors[i].first) - 1, cur)));
	}

	ll ans = 0;
	FOR(i, 0, sz(as)) {
		ans = (ans + as[i] * cs[i] % inputC) % inputC;
	}

	inputB = substract(inputB);
	ll last = getIt(inputB, inputC);
	ans = (ans * last) % inputC;
	if (ans == 0)
		ans = inputC;
	cout << ans << endl;

	return 0;
}