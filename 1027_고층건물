#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
using namespace std;

int n;
int arr[50];
int result = 0;

int check(int now) {
	int left=0, right=0;
	double mingradient, maxgradient;
	if (now > 0) {
		mingradient = (arr[now] - arr[now - 1]) / 1;
		left++;
	}
	if (now < n - 1) {
		maxgradient = (arr[now + 1] - arr[now]) / 1;
		right++;
	}
	//왼쪽
	for (int i = now - 2;i >= 0;i--) {
		double x1 = i, x2 = now;
		double y1 = arr[i], y2 = arr[now];
		double gradient = (y2 - y1) / (x2 - x1);
		if (mingradient > gradient) {
			mingradient = gradient;
			left++;
		}
	}
	//오른쪽
	for (int i = now + 2;i < n;i++) {
		double x1 = i, x2 = now;
		double y1 = arr[i], y2 = arr[now];
		double gradient = (y2 - y1) / (x2 - x1);
		if (maxgradient < gradient) {
			maxgradient = gradient;
			right++;
		}
	}
	return left + right;
}
int main() {
	int ans;
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d", &arr[i]);
	for (int i = 0;i < n;i++) {
		ans = check(i);
		if (result < ans) result = ans;

	}
	printf("%d", result);
	return 0;
}

