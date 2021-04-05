#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using ll = long long;
using namespace std;

int v;
int visited[100001];
vector<pair<int, int>> tree[100001];
int dist;
int farNode;

void dfs(int n, int d) {
	if (visited[n]) return;
	visited[n] = 1;
	if (dist < d) {
		dist = d;
		farNode = n;
	}
	for (int i = 0;i < tree[n].size();i++)
		dfs(tree[n][i].first, d + tree[n][i].second);
}

int main() {
	scanf("%d", &v);
	for (int i = 0;i < v;i++) {
		int node;
		scanf("%d", &node);
		while (true) {
			int node2, distance;
			scanf("%d", &node2);
			if (node2 == -1) break;
			scanf("%d", &distance);
			tree[node].push_back({ node2,distance });
		}
	}
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	dfs(farNode, 0);
	printf("%d\n", dist);
}