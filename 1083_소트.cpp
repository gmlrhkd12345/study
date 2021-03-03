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

int N,S;
int arr[51];

int main() {
	scanf("%d", &N);
	for (int i = 0;i < N;i++) scanf("%d", &arr[i]);
	scanf("%d", &S);
	for (int i = 0;i < N;i++) {
		int max_num = arr[i];
		int max_loc = i;
		for (int j = i + 1;j < N;j++) {
			if (S - (j - i) >= 0) {
				if (max_num < arr[j]) {
					max_num = arr[j];
					max_loc = j;
				}
			}
		}
		for (int j = max_loc;j > i;j--) {
			int temp = arr[j-1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
		}
		S = S - (max_loc - i);
		if (S == 0) break;
	}
	for (int i = 0;i < N;i++) printf("%d ", arr[i]);
	return 0;
}