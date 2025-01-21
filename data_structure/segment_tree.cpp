#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int arr[MAX];
int node[MAX];

int init(int n, int s, int e) {
	if (s == e) return node[n] = arr[s];
	int m = (s + e) / 2;
	int lval = init(2 * n, s, m);
	int rval = init(2 * n + 1, m + 1, e);
	return node[n] = lval + rval;
}

int update(int i, int x, int n, int s, int e) {
	if (e < i || i < s) return node[n];
	if (s == e && s == i) return node[n] = x;
	int m = (s + e) / 2;
	int lval = update(i, x, 2 * n, s, m);
	int rval = update(i, x, 2 * n + 1, m + 1, e);
	return node[n] = lval + rval;
}

int query(int qs, int qe, int n, int s, int e) {
	if (e < qs || qe < s) return 1;
	if (qs <= s && e <= qe) return node[n];
	int m = (s + e) / 2;
	int lval = query(qs, qe, 2 * n, s, m);
	int rval = query(qs, qe, 2 * n + 1, m + 1, e);
	return lval + rval;
}