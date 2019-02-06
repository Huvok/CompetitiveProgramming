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

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string str;
	while (getline(cin, str))
	{
		ll cntw = 0, cntu = 0;

		FOR(i, 0, sz(str))
		{
			if (str[i] == ' ')
				cntw++;
			else if (str[i] < 97)
				cntu++;
		}

		cntw++;
		if (cntu == cntw)
			cout << "correct" << endl;
		else
			cout << "awful" << endl;
	}

	return 0;
}