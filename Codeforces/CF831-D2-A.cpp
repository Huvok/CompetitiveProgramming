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

using namespace std;

//															//AUTHOR: Hugo Garcia
// Just check the section where you are and if there's something wrong output no, at the end output yes.

//======================================================================================================================
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)

//======================================================================================================================
ll arr[105];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;

	ll intMode = -1;
	FOR(intI, 0, intN)
	{
		cin >> arr[intI];
		if (intI)
		{
			if (intMode == -1)
			{
				if (arr[intI] < arr[intI - 1])
				{
					intMode = 1;
				}
				if (arr[intI] == arr[intI - 1])
				{
					intMode = 0;
				}
			}
			else if (intMode == 0)
			{
				if (arr[intI] > arr[intI - 1])
				{
					cout << "NO" << endl;
					return 0;
				}
				else if (arr[intI] < arr[intI - 1])
				{
					intMode = 1;
				}
			}
			else
			{
				if (arr[intI] >= arr[intI - 1])
				{
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}

	cout << "YES" << endl;
	return 0;
}