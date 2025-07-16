#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll rs(ll x, ll y) {
	if (y == 0) return 1;
	if (y == 1) return x % MOD;
	
	if (y % 2 == 0) {
		return rs(x * x % MOD, y / 2);
	} else {
		return x * rs(x * x % MOD, y / 2) % MOD;
	}
}