#include <bits/stdc++.h>
using ll = long long;
#define MAX 1000000

using namespace std;

ll arr[MAX];
ll node[4 * MAX];

ll init(int n, int s, int e) {
	if (s == e) return node[n] = arr[s];
	int m = (s + e) / 2;
	ll lval = init(2 * n, s, m);
	ll rval = init(2 * n + 1, m + 1, e);
	return node[n] = lval + rval;
}

ll update(int i, ll x, int n, int s, int e) {
	if (e < i || i < s) return node[n];
	if (s == e && s == i) return node[n] = x;
	int m = (s + e) / 2;
	ll lval = update(i, x, 2 * n, s, m);
	ll rval = update(i, x, 2 * n + 1, m + 1, e);
	return node[n] = lval + rval;
}

ll query(int qs, int qe, int n, int s, int e) {
	if (e < qs || qe < s) return 0;
	if (qs <= s && e <= qe) return node[n];
	int m = (s + e) / 2;
	ll lval = query(qs, qe, 2 * n, s, m);
	ll rval = query(qs, qe, 2 * n + 1, m + 1, e);
	return lval + rval;
}