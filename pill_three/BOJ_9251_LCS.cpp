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
char arr1[1001];
char arr2[1001];
int dp[1001][1001];
int n,k;
int main() {
	scanf("%s", arr1);
	scanf("%s", arr2);
	for (int i = 1; i <= strlen(arr1); i++) {
		for (int j = 1; j <= strlen(arr2); j++) {
			if (arr1[i - 1] == arr2[j - 1])
				dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1] + 1));
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	printf("%d\n", dp[strlen(arr1)][strlen(arr2)]);

}