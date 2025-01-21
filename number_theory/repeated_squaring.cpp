#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll repeatedSquaring(ll x, ll y, ll m) {
	if (y == 1) return x % m;
	if (y % 2 == 0) {
		return repeatedSquaring(x * x % m, y / 2, m);
	} else {
		return x * repeatedSquaring(x * x % m, y / 2, m) % m;
	}
}