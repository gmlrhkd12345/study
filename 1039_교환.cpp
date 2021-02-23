#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>
#include <queue>
#include <cstdlib>
using namespace std;

int N, K;
int visited[1000001][11];
void bfs() {
	queue <pair <int, int>> q;
	visited[N][0] = 1;
	q.push(make_pair(N, 0));


	string s = to_string(N);
	int len = s.length();

	while (!q.empty()) {
		int n = q.front().first;
		int k = q.front().second;
		if (k == K) break;
		q.pop();

		k++;
		for (int i = 0;i < len - 1;i++) {
			for (int j = i + 1;j < len;j++) {
				int new_n;
				string new_s = to_string(n);
				if (i == 0 && new_s[j] == '0') new_n = -1;
				else {
					swap(new_s[i], new_s[j]);
					new_n = atoi(new_s.c_str());
				}
				if (new_n != -1 && !visited[new_n][k]) {
					visited[new_n][k] = 1;
					q.push(make_pair(new_n, k));
				}
			}
		}
	}
	int max = -1;
	while (!q.empty()) {
		if (max < q.front().first) max = q.front().first;
		q.pop();
	}
	printf("%d\n", max);
}
int main() {
	scanf("%d %d", &N, &K);
	bfs();
}