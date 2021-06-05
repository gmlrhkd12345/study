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

using ll = long long;
using namespace std;
const int MAX = 32e3;
int N,M, indegree[MAX+1];
int main() {
	vector<int> v[MAX + 1];
	priority_queue<int, vector<int>, greater<int>> pq;

	scanf("%d %d", &N, &M);
	for (int i = 0;i < M;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		indegree[b]++;
	}

	for (int i = 1;i <= N;i++) {
		if (!indegree[i]) pq.push(i);
	}
	while (!pq.empty()) {
		int n = pq.top();
		pq.pop();
		printf("%d ", n);
		for (int i = 0;i < v[n].size();i++) {
			int next = v[n][i];
			indegree[next]--;

			if (indegree[next] == 0) pq.push(next);
		}
	}
	return 0;
}