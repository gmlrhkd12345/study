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
const int MAX = 501;
int N, M;
int visited[MAX][MAX];
int adj[MAX][MAX];
int xr[4] = { 0,1,0,-1 };
int xc[4] = { 1,0,-1,0 };
int dp(int x, int y) {
	
	if (visited[x][y] != -1) return visited[x][y];
	if (x == M && y == N) return 1;

	visited[x][y] = 0;
	for (int i = 0;i < 4;i++) {
		int nx = x + xr[i];
		int ny = y + xc[i];
		if (adj[nx][ny] < adj[x][y] && nx>0 && nx <= M && ny > 0 && ny <= N) {
			visited[x][y] += dp(nx, ny);
		}
	}
	return visited[x][y];
	
}
int main() {
	scanf("%d %d", &M, &N);

	for (int i = 1;i <= M;i++) {
		for (int j = 1;j <= N;j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	memset(visited, -1, sizeof(visited));

	printf("%d\n", dp(1, 1));
	return 0;
}