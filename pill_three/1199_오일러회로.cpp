#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
using ll = long long;
using namespace std;
string s;
int graph[1001][1001];
int degree[1001];
int n;
void dfs(int u) {
	for (int i = 1;i <= n;i++) {
		if (graph[u][i]) {
			graph[u][i]--;
			graph[i][u]--;
			dfs(i);
		}
	}
	s += to_string(u) + " ";
}
int main() {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			scanf("%d", &graph[i][j]);
			degree[i] += graph[i][j];
		}
	}
	for (int i = 1;i <= n;i++) {
		if (degree[i] % 2 != 0) {
			printf("-1\n");
			return 0;
		}
	}
	dfs(1);
	cout << s;
}