#include <bits/stdc++.h>
#define pii pair<int, int>
#define MAX 10000
#define INF 1e9

using namespace std;

vector<pii> graph[MAX];
int dist[MAX];

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    fill(dist, dist + MAX, INF);
    pq.push({dist[s] = 0, s});

    while (!pq.empty()) {
        pii cur = pq.top(); pq.pop();
        int fr = cur.second;
        
        if (cur.first != dist[fr]) continue;
        
        for (int i = 0; i < graph[fr].size(); i++) {
            int to = graph[fr][i].first;
            int d = graph[fr][i].second;

            if (dist[to] > dist[fr] + d) {
                pq.push({dist[to] = dist[fr] + d, to});
            }
        }
    }
}