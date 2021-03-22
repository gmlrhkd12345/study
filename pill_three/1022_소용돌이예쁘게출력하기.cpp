#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
using namespace std;

int n;
int arr[50][5];
int dx[4] = { 0, -1, 0, 1 }; 
int dy[4] = { 1, 0, -1, 0 };

int main() {
	int r1, r2, c1, c2;
	int row, col;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	for (int i = 0; i <= r2 - r1; i++) {

		for (int j = 0; j <= c2 - c1; j++)

			arr[i][j] = 0;

	}
	int x =0, y = 0;
	int direct = 0;
	int num = 1, direct_cnt = 1;
	int cnt = 0; 

	while (!((arr[0][0] != 0) && (arr[0][c2-c1] != 0) && (arr[r2 - r1][0] != 0 )&& (arr[r2-r1][c2 - c1] != 0))) {
		if (x - r1 >= 0 && x - r1 <= (r2 - r1) && y - c1 >= 0 && y - c1 <= (c2 - c1)){
			arr[x - r1][y - c1] = num;
		}
		num++;
		cnt++;

		x = x + dx[direct];
		y = y + dy[direct];

		if (cnt == direct_cnt) {
			cnt = 0;
			direct = (direct + 1) % 4;
			if (direct == 0 || direct == 2)
				direct_cnt++;
		}
	}
	cnt = 0;

	while (num > 0) {
		num /= 10;
		cnt++;
	}
	for (int i = 0;i <= (r2 - r1);i++) {
		for (int j = 0;j <= (c2 - c1);j++) {
			printf("%*d ", cnt, arr[i][j]);
		}
		printf("\n");
	}
	

	
}

