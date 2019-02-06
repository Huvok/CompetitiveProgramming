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
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

#define PI 3.1415926535897932384626433832795

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		if (str.length() % 2 == 0)
			cout << "Non-inhabitant" << endl;
		else
			cout << "The inhabitant " << str << " can have " << pow(((str.length() + 1) / 2), 2) << " children" << endl;
	}

	return 0;
}