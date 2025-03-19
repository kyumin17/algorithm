#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll eea(ll x, ll n) {
	ll a = n, b = 0;
	ll c = x % n, d = 1;
	while (c) {
		ll q = a / c;
		ll e = a - q * c;
		ll f = (b - q * d) % n;
		a = c;
		b = d;
		c = e;
		d = f;
	}
	
    return b < 0 ? b + n : b;
}