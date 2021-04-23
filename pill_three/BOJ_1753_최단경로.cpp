#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#define inf 987654321;
using namespace std;
vector <vector <pair<int,int>>> adj;
int dist[20001];
int n;
void dijikstra(int src) {
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextdist = cost + adj[here][i].second;
			if (dist[there] > nextdist) {
				dist[there] = nextdist;
				pq.push(make_pair(-nextdist, there));
			}
		}
	}
}
int main() {
	int v, e;
	scanf("%d %d", &v, &e);
	scanf("%d", &n);
	adj.resize(v + 1);
	for (int i = 0; i < 20001; i++)
		dist[i] = inf;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(make_pair(b,c));
	
	}
	dijikstra(n);
	for (int i = 1; i <= v; i++) {
		if (i == n)
			printf("0\n");
		else {
			if (dist[i] == 987654321)
				printf("INF\n");
			else
				printf("%d\n", dist[i]);
		}

	}
}