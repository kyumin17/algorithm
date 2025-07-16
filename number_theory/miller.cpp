#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll base[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };

ll rs(ll x, ll y, ll m) {
	if (y == 0) return 1;
	if (y == 1) return x % m;
	
	if (y % 2 == 0) {
		return rs(x * x % m, y / 2, m);
	} else {
		return x * rs(x * x % m, y / 2, m) % m;
	}
}

bool isPrime(ll n) {
	if (n < 2) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;

	ll d = n - 1;
	ll s = 0;

	while (d % 2 == 0) {
		d >>= 1;
		s++;
	}

	for (ll a : base) {
		if (a % n == 0) continue;

		ll val = rs(a, d, n);
		if (val == 1 || val == n - 1) continue;

		bool comp = 1;
		for (ll i = 0; i < s; i++) {
			val = val * val % n;
			if (val == n - 1) {
				comp = 0;
				break;
			}
		}

		if (comp) return 0;
	}

	return 1;
}