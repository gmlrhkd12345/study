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
#include <stack>
#include <functional>
#define P pair<int, int>

using ll = long long;
using namespace std;
int V, E, parents[1000001];
vector<pair<int,P>> v;
vector<P> X;
vector<P> Y;
vector<P> Z;

struct edge {
	int u, v, w;
	edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

int compare_comp(const edge &a, const edge& b) {
	return a.w < b.w;
}

int find(int u) {
	if (u == parents[u]) return u;
	return parents[u] = find(parents[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u < v) parents[v] = u;
	else parents[v] = u;
}
int main() {
	scanf("%d", &V);
	for (int i = 0; i < V; i++) {
		parents[i] = i;
	}

	for (int i = 0;i < V;i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		X.push_back({ x, i });
		Y.push_back({ y, i });
		Z.push_back({ z, i });
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());
	for (int i = 0;i < V-1;i++) {
		v.push_back({ X[i + 1].first - X[i].first,{X[i].second,X[i + 1].second} });
		v.push_back({ Y[i + 1].first - Y[i].first,{Y[i].second,Y[i + 1].second} });
		v.push_back({ Z[i + 1].first - Z[i].first,{Z[i].second,Z[i + 1].second} });
	}
	sort(v.begin(), v.end());
	int total = 0;

	for (int i = 0;i < v.size();i++) {
		int a = v[i].second.first;
		int b = v[i].second.second;
		int c = v[i].first;

		if (find(a) != find(b)) {
			merge(a, b);
			total += c;
		}
	}
	printf("%d\n", total);
}