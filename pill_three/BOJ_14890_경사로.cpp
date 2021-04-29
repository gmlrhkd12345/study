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
const int MAX = 100;
int n, l;
int adj[MAX * 2][MAX];
int main() {
	int num = 0;
	int j;
	int block;
	scanf("%d %d", &n, &l);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%hd", &adj[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			adj[i + n][j] = adj[j][i];

	for (int i = 0; i < n * 2; i++) {
		block = 1;
		for (j = 0; j < n - 1; j++) {
			if (adj[i][j] == adj[i][j + 1]) block++;
			else if (adj[i][j] + 1 == adj[i][j + 1] && block >= l) block = 1; // 올리는 경우
			else if (adj[i][j] - 1 == adj[i][j + 1] && block >= 0) block = -l + 1; //내려가는 경우
			else break;
		}
		if (j == n-1 && block >= 0) num++;
	}
	printf("%d", num);
	return 0;
}