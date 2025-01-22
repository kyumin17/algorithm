#include <bits/stdc++.h>
#define p pair<int, pair<int, int>>
#define MAX 10000

using namespace std;

vector<p> edge;
int parent[MAX];
int v, e;

int find(int x) {
	if (x == parent[x]) {
		return x;
	} else {
		return parent[x] = find(parent[x]);
	}
}

void unionRoot(int x, int y) {
	x = find(x);
	y = find(y);
	
	if (x != y) {
		parent[y] = x;
	}
}

int kruskal() {
	int weight = 0;
	int size = 0;
	
	for (int i = 0; i < e; i++) {
		p n = edge[i];
		
		int f = n.second.first;
		int s = n.second.second;
		
		if (find(f) == find(s)) {
			continue;
		}
		
		weight += n.first;
		size++;
		unionRoot(f, s);
		
		if (size == v - 1) {
			return weight;
		}
	}
}