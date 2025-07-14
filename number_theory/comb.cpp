#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MAX 1000000

ll fac[MAX+1], infac[MAX+1];

ll rs(ll x, ll y) {
	if (y == 0) return 1;
	if (y == 1) return x % MOD;
	
	if (y % 2 == 0) {
		return rs(x * x % MOD, y / 2);
	} else {
		return x * rs(x * x % MOD, y / 2) % MOD;
	}
}

ll comb(ll x, ll y) {
	return fac[x] * infac[y] % MOD * infac[x-y] % MOD;
}

void init() {
	fac[0] = 1;
	for (int i = 1; i <= MAX; i++) fac[i] = fac[i-1] * i % MOD;
	infac[MAX] = rs(fac[MAX], MOD - 2);
	for (int i = MAX - 1; i >= 0; i--) infac[i] = infac[i+1] * (i+1) % MOD;
}