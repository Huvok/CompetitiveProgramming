#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <queue>
#include <string.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int main()
{
	string str;
	cin >> str;
	set<string> s;

	FOR(i, 0, str.length())
	{
		FOR(j, i, str.length())
		{
			s.insert(str.substr(i, j - i + 1));
		}
	}

	cout << s.size() << endl;

	return 0;
}