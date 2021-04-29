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
const int N_MAX = 10 + 1;
const int H_MAX = 30 + 1;

int ladder[H_MAX][N_MAX];
int N, M, H;
int ans = 1e9;

int check() {
	for (int i = 1;i <= N;i++) {
		int nc = i;
		for (int j = 1;j <= H;j++) {
			if (ladder[j][nc - 1]) nc--; 
			else if (ladder[j][nc]) nc++; 
		}
		if (nc != i) return 0;
	}
	return 1;
}
void dfs(int idx, int cnt) {
	if (cnt >= 4) return;
	if (check() == 1) {
		ans = min(ans, cnt);
		return;
	}
	for (int i = idx; i <= H; i++) {
		for (int j = 1;j <= N;j++) {
			if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1]) continue;			
			ladder[i][j] = 1;
			dfs(i, cnt + 1);
			ladder[i][j] = 0;
		}
	}
}
int main() {
	scanf("%d %d %d", &N, &M, &H);
	for (int i = 0;i < M;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		ladder[a][b] = 1;
	}
	dfs(1, 0);
	if (ans == 1e9) ans = -1;
	printf("%d\n", ans);
}