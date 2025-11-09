#include <bits/stdc++.h>
using ll = long long;
#define MAX 1000000

using namespace std;

vector<ll> v(4 * MAX), lazy(4 * MAX);

ll init(int n = 1, int s = 1, int e = MAX) {
	if (s == e) return node[n] = arr[s];
	int m = (s + e) / 2;
	ll lval = init(2 * n, s, m);
	ll rval = init(2 * n + 1, m + 1, e);
	return node[n] = lval + rval;
}

void update_lazy(int n, int s, int e) {
    if (!lazy[n]) return;
    if (s != e) {
        lazy[2*n] += lazy[n];
        lazy[2*n+1] += lazy[n];
    }
    v[n] += lazy[n] * (e - s + 1);
    lazy[n] = 0;
}

ll query(int l, int r, int n = 1, int s = 1, int e = MAX) {
    update_lazy(n, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return v[n];
    int m = (s + e) / 2;
    return query(l, r, n*2, s, m) + query(l, r, n*2+1, m+1, e);
}

ll update(int l, int r, ll x, int n = 1, int s = 1, int e = MAX) {
    update_lazy(n, s, e);
    if (r < s || e < l) return v[n];
    if (l <= s && e <= r) {
        if (s != e) {
            lazy[2*n] += x;
            lazy[2*n+1] += x;
        }
        return v[n] += x * (e - s + 1);
    }
    int m = (s + e) / 2;
    return v[n] = update(l, r, x, n*2, s, m) + update(l, r, x, n*2+1, m+1, e);
}