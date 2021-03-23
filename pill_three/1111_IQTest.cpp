//ax0+b=x1, ax1+b=x2
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
vector<int> v;

int main() {
	int n, a, b;
	int flag = 0;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		int k;
		scanf("%d", &k);
		v.push_back(k);
	}
	if (n == 1) {
		printf("A\n");
		return 0;
	}
	else if (n == 2) {
		if (v[0] == v[1]) {
			printf("%d\n", v[1]);
			return 0;
		}
		else {
			printf("A\n");
			return 0;
		}
	}
	else {
		if (v[0] == v[1]) {
			if (v[1] != v[2]) {
				printf("B\n");
				return 0;
			}
			else {
				a = 1, b = 0;
			}
		}
		else {
			if ((v[2] - v[1]) % (v[1] - v[0])) {
				printf("B\n");
				return 0;
			}
			a = (v[2] - v[1]) / (v[1] - v[0]);
			b = v[1] - a * v[0];
		}
	}
	for (int i = 3;i < v.size();i++) {
		if (v[i] != a * v[i - 1] + b) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		printf("B\n");
		return 0;
	}
	printf("%d", a * v[n - 1] + b);
}

