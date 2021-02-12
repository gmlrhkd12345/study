#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<cmath>
#include <algorithm>
#include<vector>
using namespace std;

int t;
int n;
int check[20];
int dx[20];
int dy[20];
vector <double> v;

void go(int here, int cnt) {
	if (cnt == n / 2) {
		double ans;
		double x = 0, y = 0;
		for (int i = 0;i < n;i++) {
			if (check[i]) {
				x += dx[i];
				y += dy[i];
			}
			else {
				x -= dx[i];
				y -= dy[i];
			}
		}
		ans = sqrt(x * x + y * y);
		v.push_back(ans);
		return;
	}
	for (int i = here;i < n;i++) {
		if (!check[i]) {
			check[i] = 1;
			go(i + 1, cnt+1);
			check[i] = 0;

		}
	}

	
}

int main() {
	scanf("%d", &t);
	for (int i = 0;i < t;i++) {
		double result;
		scanf("%d", &n);
		for (int j = 0;j < n;j++) {
			scanf("%d %d", &dx[j], &dy[j]);
		}
		go(0, 0);
		sort(v.begin(), v.end());
		result = v[0];
		v.erase(v.begin(), v.end());
		printf("%.12f\n", result);
	}
	return 0;
	
}

