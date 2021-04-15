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

int cnt = 0;
int n;
int chess[15];
int check(int row) {
	for (int i = 0;i < row;i++) {
		if (chess[row] == chess[i] || row - i == abs(chess[row] - chess[i])) { 
			return 0;
		}
	}
	return 1;
}
void nqueen(int row) {
	if (row == n) {
		cnt++;
		return;
	}
	for (int i = 0;i < n;i++) {
		chess[row] = i;
		if (check(row)) {
			nqueen(row + 1);
		}
	}
}
int main() {
	scanf("%d", &n);
	nqueen(0);
	printf("%d\n", cnt);
}