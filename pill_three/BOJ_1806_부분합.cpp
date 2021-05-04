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

int arr[100001];
int main(void) {
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	int left = 1, right = 1;
	int sum = 0,ans=100000;
	while (left <= n + 1) {
		if (right == n + 1 || sum >= s) {
			if (right == n + 1 && sum < s)
				sum -= arr[left++];
			else {
				ans = ans > (right - left) ? (right - left) : ans;
				sum -= arr[left++];
			}
		}
		else sum += arr[right++];
	}
	if (ans == 100000)
		printf("0\n");
	else
		printf("%d\n", ans);
}