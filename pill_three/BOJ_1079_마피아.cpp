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
#include <functional>
using namespace std;

int N;
int guilty[17];
int R[17][17];
int check[17];
int mapia_loc;
int night = 0;
void go(int num, int cnt) {
	if (num == 1 || check[mapia_loc]) {
		if (cnt > night) night = cnt;
		return;
	}
	
	if (num % 2 == 0) {
		for (int i = 0;i < N;i++) {
			if (i == mapia_loc || check[i]) continue;
			
			check[i] = 1;

			for (int j = 0;j < N;j++) {
				if (!check[j]) guilty[j] += R[i][j];
			}

			go(num - 1, cnt + 1);

			for (int j = 0;j < N;j++) {
				if (!check[j]) guilty[j] -= R[i][j];
			}
			check[i] = 0;
		}
	}
	
	else {
		int kill_loc;
		int max = 0;
		for (int i = 0;i < N;i++) {
			if (!check[i] && guilty[i] > max) {
				max = guilty[i];
				kill_loc = i;
			}
		}
		check[kill_loc] = 1;
		go(num - 1, cnt);
		check[kill_loc] = 0;
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &guilty[i]);
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			scanf("%d", &R[i][j]);
		}
	}
	scanf("%d", &mapia_loc);
	go(N, 0);
	printf("%d\n", night);
	return 0;
}
