#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int arr[101][101];
int dist[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
typedef pair<int, pair<int, int>>P;
priority_queue<P>pq;
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= n;j++) {
			scanf("%1d", &arr[i][j]);
			dist[i][j] = 1e9;
		}
	}
	pq.push(make_pair(0,make_pair(1,1)));
	dist[1][1] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (cost > dist[x][y])continue;
		for (int i = 0;i < 4;i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			int nextDist = cost + arr[nextx][nexty];
			if (nextx>=1&&nexty>=1&&nextx<=m&&nexty<=n) {
				if (dist[nextx][nexty] > nextDist) {
					dist[nextx][nexty] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(nextx, nexty)));
				}
			}
		}
	}
	printf("%d", dist[m][n]);
}