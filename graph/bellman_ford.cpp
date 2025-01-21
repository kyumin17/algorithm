#include <bits/stdc++.h>
#define p pair<int, pair<int, int>>
#define MAX 10000
#define INF 1e9

using namespace std;

int n;
vector<p> edge;
int dist[MAX];

void bellmanFord() {
    fill(dist, dist + MAX, INF);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < edge.size(); j++) {
            int fr = edge[j].first;
            int to = edge[j].second.first;
            int d = edge[j].second.second;

            if (dist[fr] == INF) continue;

            if (dist[to] > dist[fr] + d) {
                dist[to] = dist[fr] + d;
            }
        }
    }
}