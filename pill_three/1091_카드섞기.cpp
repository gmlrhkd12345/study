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
int P[48], S[48], init_card[48], tmp[48];

int main() {
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &P[i]);
		init_card[i] = P[i];
	}
	for (int i = 0;i < N;i++) scanf("%d", &S[i]);

	int count = 0;
	bool complete;
	while (true) {
		for (int i = 0;i < N;i++) {
			if (P[i] != (i % 3)) {
				complete = false;
				break;
			}
			complete = true;
		}
		if (complete) break;
        
		count++;
		
		for (int i = 0;i < N;i++) {
			tmp[i] = P[i]; 
		}
		for (int i = 0;i < N;i++) {
			P[S[i]] = tmp[i]; 
        }
        
		for (int i = 0;i < N;i++) {
			if (P[i] != init_card[i]) break;
			if (i == N - 1) {
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", count);
}
