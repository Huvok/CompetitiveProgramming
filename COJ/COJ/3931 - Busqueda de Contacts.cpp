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
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
#define eps 1e-15
ll mod = 1e6 + 7;
typedef pair<ll, ll> par;
typedef pair<int, par> tri;
#define fauto( i, x ) for(__typeof(x.end())i=x.begin();i!=x.end();++i)
#define mset( a, b ) memset( a, b, sizeof(a) )
#define MAXN 20005
#define PI acos(-1)

#define LEN 1000005
int n, _sa[LEN], _b[LEN], top[LEN], _tmp[LEN];
int LCP[LEN], *SA = _sa, *B = _b, *tmp = _tmp;
char s[LEN];
void build_lcp() {
	for (int i = 0, k = 0; i < n; ++i) {
		if (B[i] == n - 1)
			continue;
		for (int j = SA[B[i] + 1]; i + k < n &&
			j + k < n && s[i + k] == s[j + k] && s[i + k] != '$'; k++);
		LCP[B[i]] = k;
		if (k) k--;
	}
}
void build_sa() {
	s[n] = '\0', n++;
	int na = (n < 256 ? 256 : n);
	for (int i = 0; i < n; i++)
		top[B[i] = s[i]]++;
	for (int i = 1; i < na; i++)
		top[i] += top[i - 1];
	for (int i = 0; i < n; i++)
		SA[--top[B[i]]] = i;
	for (int ok = 1, j = 0; ok < n && j < n - 1; ok <<= 1) {
		for (int i = 0; i < n; i++) {
			j = SA[i] - ok;
			if (j < 0)
				j += n;
			tmp[top[B[j]]++] = j;
		}
		SA[tmp[top[0] = 0]] = j = 0;
		for (int i = 1; i < n; i++) {
			if (B[tmp[i]] != B[tmp[i - 1]] ||
				B[tmp[i] + ok] != B[tmp[i - 1] + ok])
				top[++j] = i;
			SA[tmp[i]] = j;
		}
		swap(B, SA), swap(SA, tmp);
	}
	build_lcp();
	n--, s[n] = '\0';
}

char cad[LEN];
int nu;
int t[LEN], p[LEN];
int A[LEN];
int At[LEN];

int S[LEN];
int S1[LEN];

int main()
{
#ifdef acm
	freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
#endif // acm

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> nu;
	for (int i = 1; i <= nu; i++) {
		cin >> cad;
		int tam = strlen(cad);

		for (int j = 0; j < tam; j++)
			s[n] = cad[j], A[n] = i, At[n] = tam - j, n++;
		if (i < nu) s[n] = '$', n++;
	}

	build_sa();





	int a = 0;
	mset(S, 30);
	mset(S1, 30);

	for (int i = 1; i <= n; i++) {
		if (A[SA[i]] < 1) continue;
		if (A[SA[i]] != A[SA[i - 1]]) {
			S[i] = min(LCP[i - 1], S[i]);
			a = LCP[i - 1];
		}
		else {
			a = min(a, LCP[i - 1]);
			S[i] = min(a, S[i]);
		}
	}
	for (int i = n; i >= 1; i--) {
		if (A[SA[i]] < 1) continue;
		if (A[SA[i]] != A[SA[i + 1]]) {
			S1[i] = min(LCP[i], S1[i]);
			a = LCP[i];
		}
		else {
			a = min(a, LCP[i]);
			S1[i] = min(a, S1[i]);
		}

		S[i] = max(S[i], S1[i]);
	}

	//    for( int i = 1; i <= n; i ++ )
	//        cout << LCP[i] << ' ' << S[i] << ' ' << (s+SA[i]) << '\n';
	//        return 0;


	mset(t, 30);
	int inf = t[0];
	for (int i = 1; i <= n; i++)
		if (A[SA[i]] >= 1 && t[A[SA[i]]] > S[i] + 1 && At[SA[i]] >= S[i] + 1) {
			t[A[SA[i]]] = S[i] + 1, p[A[SA[i]]] = SA[i];
		}
	for (int i = 1; i <= nu; i++) {
		if (t[i] == inf) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		for (int j = 0; j < t[i]; j++)
			cout << s[p[i] + j];
		cout << '\n';
	}


	return 0;
}

