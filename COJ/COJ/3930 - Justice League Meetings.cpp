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

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll ax[100005], ay[100005];
ll ans[100005], ans2[100005];
ii qx[100005], qy[100005];

ll dist(ll a, ll b)
{
	return abs(a - b);
}

ll n, q;
ll getAll(ll i, ll a[])
{
	ll ret = 0;

	FOR(j, 0, n)
	{
		ret += dist(i, a[j]);
	}

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n;
	FOR(i, 0, n)
	{
		cin >> ax[i] >> ay[i];
	}

	sort(ax, ax + n);
	sort(ay, ay + n);

	cin >> q;
	FOR(i, 0, q)
	{
		cin >> qx[i].first >> qy[i].first;
		qx[i].second = qy[i].second = i;
	}

	sort(qx, qx + q);
	sort(qy, qy + q);

	ans[qx[0].second] = getAll(qx[0].first, ax);

	ll queries = 1, points = 0;
	ll cur = getAll(qx[0].first, ax);
	ans[qx[0].second] = cur;

	while (points < n &&
		ax[points] < qx[0].first)
	{
		points++;
	}

	ll prev = qx[0].first;
	while (queries < q)
	{
		while (points < n &&
			ax[points] < qx[queries].first)
		{
			cur -= (abs(ax[points] - prev) * (n - points));
			cur += (abs(ax[points] - prev) * (points));
			prev = ax[points];
			points++;
		}

		cur -= (abs(qx[queries].first - prev) * (n - points));
		cur += (abs(qx[queries].first - prev) * (points));
		prev = qx[queries].first;
		ans[qx[queries].second] = cur;
		queries++;
	}

	cur = getAll(qy[0].first, ay);
	ans[qy[0].second] += cur;
	queries = 1;
	points = 0;


	while (points < n &&
		ay[points] < qy[0].first)
	{
		points++;
	}

	prev = qy[0].first;

	while (queries < q)
	{
		while (points < n &&
			ay[points] < qy[queries].first)
		{
			cur -= (abs(ay[points] - prev) * (n - points));
			cur += (abs(ay[points] - prev) * (points));
			prev = ay[points];
			points++;
		}

		cur -= (abs(qy[queries].first - prev) * (n - points));
		cur += (abs(qy[queries].first - prev) * (points));
		prev = qy[queries].first;
		ans[qy[queries].second] += cur;
		queries++;
	}

	/*FOR(i, 0, q)
	{
		ans2[qx[i].second] += getAll(qx[i].first, ax);
		ans2[qy[i].second] += getAll(qy[i].first, ay);
	}*/

	FOR(i, 0, q)
	{
		//cout << ans[i] << " --- " << ans2[i] << '\n';
		cout << ans[i] << '\n';
	}

	return 0;
}
