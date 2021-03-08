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

int N, M;
vector<int> crane, box;

int main() {
	scanf("%d", &N);
	int a;
	for (int i = 0;i < N;i++) {
		scanf("%d", &a);
		crane.push_back(a);
	}
	scanf("%d", &M);
	for (int i = 0;i < M;i++) {
		scanf("%d", &a);
		box.push_back(a);
	}

	sort(crane.begin(),crane.end(), greater<>());
	sort(box.begin(), box.end(), greater<>());

	if (crane[0] < box[0]) {
		printf("-1\n");
		return 0;
	}
	int ret = 0, j = 0;
	while (!box.empty()) {
		ret += 1;
		for (int i = 0;i < crane.size();i++) {
			for (int j = 0;j < box.size();j++) {
				if (crane[i] >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}