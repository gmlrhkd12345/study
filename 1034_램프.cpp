#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>
using namespace std;
string arr[50];
int n, m, k;
int num = -1;

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	scanf("%d", &k);
	for (int i = 0;i < n;i++) {
		int zero_num = 0;
		for (int j = 0;j < m;j++) {
			if (arr[i][j] == '0') zero_num++;
		}
		int sum = 0;
		if (zero_num <= k && zero_num % 2 == k % 2)
		{
			for (int j = 0;j < n;j++) {
				if (arr[i] == arr[j])
				{
					sum++;
				}
			}
		}
		num = max(sum, num);
	}
	printf("%d", num);
	return 0;
}