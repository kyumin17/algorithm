#include <bits/stdc++.h>
#define ll long long
#define p pair<ll, pair<int, int>>
#define MAX 10000

using namespace std;

vector<p> edge;
int parent[MAX];
int v, e;

int find(int x) {
	if (x == 0) {
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

ll kruskal() {
	ll weight = 0;
	int size = 0;

	sort(edge.begin(), edge.end());
	
	for (p n: edge) {
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