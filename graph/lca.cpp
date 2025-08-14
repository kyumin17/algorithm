#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int n;
const int k = 19;

vector<vector<int>> v(MAX);
int parent[k][MAX];
int lv[MAX];
bool vis[MAX];

void dfs(int n) {
    for (int i: v[n]) {
        if (vis[i]) continue;
        lv[i] = lv[n] + 1;
        parent[0][i] = n;
        vis[i] = 1;
        dfs(i);
    }
}

void init(int s) {
    vis[s] = 1;
    dfs(s);

    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
}

int lca(int a, int b) {
    if (lv[a] < lv[b]) swap(a, b);

    int d = lv[a] - lv[b];

    int t = 0;
    while (d != 0) {
        if (d % 2) a = parent[t][a];
        t++; d /= 2;
    }

    if (a == b) return a;

    for (int i = k-1; i >= 0; i--) {
        if (parent[i][a] != parent[i][b]) {
            a = parent[i][a];
            b = parent[i][b];
        }
    }

    return parent[0][a];
}