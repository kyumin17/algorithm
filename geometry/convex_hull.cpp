#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
 
using namespace std;

vector<ll> v;
vector<pll> point;

ll ccw(pll a, pll b, pll c) {
	return (b.first - a.first) * (c.second - b.second) - (c.first - b.first) * (b.second - a.second);
}

ll dist(pll a, pll b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool cmp1(pll a, pll b) {
	if (a.second == b.second) {
		return a.first < b.first;
	} else {
		return a.second < b.second;
	}
}

bool cmp2(pll a, pll b) {
	ll c = ccw(point[0], a, b);
	if (c == 0) {
		return dist(point[0], a) < dist(point[0], b);
	}
	
	return c > 0;
}

void convexHull() {
	sort(point.begin(), point.end(), cmp1);
	sort(point.begin() + 1, point.end(), cmp2);

	v.push_back(0);
	v.push_back(1);

	for (int i = 2; i < point.size(); i++) {
		while (v.size() >= 2 && ccw(point[i], point[*(v.end() - 2)], point[*(v.end() - 1)]) <= 0) {
			v.pop_back();
		}
		
		v.push_back(i);
	}
}