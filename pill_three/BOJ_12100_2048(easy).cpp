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

const int MAX = 20;
int N;
int adj[MAX][MAX];
int maxNum;

void combine(int type) {
	queue<int> q;

	if (type == 0) { 
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (adj[i][j]) q.push(adj[i][j]);
				adj[i][j] = 0;
			}
			int idx = 0;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (adj[i][idx] == 0) {
					adj[i][idx] = data;
				}
				else if (adj[i][idx] == data) {
					adj[i][idx] *= 2;
					idx++;
				}
				else {
					idx++;
					adj[i][idx] = data;
				}
			}
		}
	}
	else if (type == 1) { 
		for (int i = 0;i < N;i++) {
			for (int j = N-1;j >= 0;j--) {
				if (adj[i][j]) q.push(adj[i][j]);
				adj[i][j] = 0;
			}
			int idx = N-1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (adj[i][idx] == 0) {
					adj[i][idx] = data;
				}
				else if (adj[i][idx] == data) {
					adj[i][idx] *= 2;
					idx--;
				}
				else {
					idx--;
					adj[i][idx] = data;
				}
			}
		}
	}
	else if (type == 2) { 
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (adj[j][i]) q.push(adj[j][i]);
				adj[j][i] = 0;
			}
			int idx = 0;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (adj[idx][i] == 0) {
					adj[idx][i] = data;
				}
				else if (adj[idx][i] == data) {
					adj[idx][i] *= 2;
					idx++;
				}
				else {
					idx++;
					adj[idx][i] = data;
				}
			}
		}
	}
	else {
		for (int i = 0;i < N;i++) {
			for (int j = N - 1;j >= 0;j--) {
				if (adj[j][i]) q.push(adj[j][i]);
				adj[j][i] = 0;
			}
			int idx = N - 1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (adj[idx][i] == 0) {
					adj[idx][i] = data;
				}
				else if (adj[idx][i] == data) {
					adj[idx][i] *= 2;
					idx--;
				}
				else {
					idx--;
					adj[idx][i] = data;
				}
			}
		}

	}
}
void dfs(int cnt) {
	if (cnt == 5) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				maxNum = max(maxNum, adj[i][j]);
			}
		}
		return;
	}
	int copyadj[MAX][MAX];
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			copyadj[i][j] = adj[i][j]; 
		}
	}
	for (int i = 0;i < 4;i++) {
		combine(i);
		dfs(cnt + 1);
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				adj[i][j] = copyadj[i][j]; 
			}
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	dfs(0);
	printf("%d\n", maxNum);
	return 0;
}
