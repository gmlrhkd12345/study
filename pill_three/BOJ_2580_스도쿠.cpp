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
const int max_num = 9;
int sdoku[max_num][max_num+1];
int row[max_num][max_num+1];
int col[max_num][max_num+1];
int square[max_num][max_num + 1];
void solve_sdoku(int idx) {
	if (idx == 81)
	{
		for (int i = 0;i < max_num;i++) {
			for (int j = 0;j < max_num;j++) {
				printf("%d ", sdoku[i][j]);
			}
			printf("\n");
		}
		exit(0); 
	}
	int r = idx / 9;
	int c = idx % 9;
	if (sdoku[r][c]) {
		solve_sdoku(idx + 1);
	}
	else {
		for (int i = 1;i <= max_num;i++) {
			if (!row[r][i] && !col[c][i] && !square[(r / 3) * 3 + c / 3][i]) {
				sdoku[r][c] = i;
				row[r][i] = 1;
				col[c][i] = 1;
				square[(r / 3) * 3 + c / 3][i] = 1;
				solve_sdoku(idx + 1);
				sdoku[r][c] = 0;
				row[r][i] = 0;
				col[c][i] = 0;
				square[(r / 3) * 3 + c / 3][i] = 0;
			}
		}
	}
}
int main() {
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			scanf("%d", &sdoku[i][j]);
			if (sdoku[i][j] != 0) {
				row[i][sdoku[i][j]] = 1;
				col[j][sdoku[i][j]] = 1;
				square[(i / 3) * 3 + j / 3][sdoku[i][j]] = 1;
			}
		}
	}
	solve_sdoku(0);
}