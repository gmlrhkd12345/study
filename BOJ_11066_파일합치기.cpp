#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using ll = long long;
using namespace std;
const int MAX = 501;
int dp[MAX][MAX];
int cost[MAX];
int sum[MAX];
int T, K;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &K);
		for (int i = 1;i <= K;i++) {
			scanf("%d", &cost[i]);
			sum[i] = sum[i - 1] + cost[i];
		}

		for (int div = 1;div < K;div++) {
			for (int i = 1;i + div <= K;i++) {
				int j = i + div;
				dp[i][j] = 1e9;
				for (int mid = i;mid < j;mid++) {
					dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + sum[j] - sum[i - 1]);
				}
			}
		}
		printf("%d\n", dp[1][K]);
	}
}