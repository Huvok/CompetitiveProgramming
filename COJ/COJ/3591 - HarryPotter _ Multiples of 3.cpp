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
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a) - 1; i>=ll(b); i--)
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

ll segmentTree[3 * 100005], lazy[3 * 100005], ss;
ll n;
ll a[100005];



int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll q;
	cin >> n >> q;

	string str;
	cin >> str;

	ll cur = 0;
	ll idx = 0;
	mem(a, 0);
	ll cnt = 0;
	for (ll i = sz(str) - 1; i >= 0; i--)
	{
		if (str[i] == '1')
		{
			cnt++;
			if (idx % 2 == 0)
				cur++;
			else
				cur += 2;
		}

		idx++;
	}

	char c;
	ll l, r;
	FOR(i, 0, q)
	{
		cin >> c;
		if (c == 'P')
		{
			if (cur % 3 == 0 &&
				cnt > 0)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else if (c == 'S')
		{
			cin >> l >> r;
			if (r)
			{
				if (str[sz(str) - l - 1] == '0')
				{
					str[sz(str) - l - 1] = '1';
					cnt++;
					if (l % 2 == 0)
						cur++;
					else
						cur += 2;
				}
			}
			else
			{
				if (str[sz(str) - l - 1] == '1')
				{
					str[sz(str) - l - 1] = '0';
					cnt--;
					if (l % 2 == 0)
						cur--;
					else
						cur -= 2;
				}
			}
		}
		else
		{
			cin >> l;
			if (str[sz(str) - l - 1] == '1')
			{
				str[sz(str) - l - 1] = '0';
				cnt--;
				if (l % 2 == 0)
					cur--;
				else
					cur -= 2;
			}
			else
			{
				str[sz(str) - l - 1] = '1';
				cnt++;
				if (l % 2 == 0)
					cur++;
				else
					cur += 2;
			}
		}
	}

	return 0;
}