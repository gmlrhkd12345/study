#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

using ll = long long;
using namespace std;
int V, E, parents[100001];

struct edge {
	int u, v, w;
	edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

int compare_comp(const edge& a, const edge& b) {
	return a.w < b.w;
}

int find(int u) {
	if (u == parents[u]) return u;
	return parents[u] = find(parents[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	parents[v] = u;
}

int main() {
	vector<edge> v;
	ll ans = 0;
	scanf("%d %d", &V, &E);
	int A, B, C;

	for (int i = 1;i <= V;i++) {
		parents[i] = i;
	}

	for (int i = 1;i <= E;i++) {
		scanf("%d %d %d", &A, &B, &C);
		v.push_back(edge(A, B, C));
	}

	sort(v.begin(), v.end(), compare_comp);

	for (int i = 0;i < v.size();i++) {
		if (find(v[i].u) != find(v[i].v)) {
			merge(v[i].u, v[i].v);
			ans += v[i].w;
		}
	}

	printf("%d\n", ans);
	return 0;
	
}