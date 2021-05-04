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

int dp[17][1 << 16];
int val[17][17];
int n;
int go(int state,int now) {
	int &ret = dp[now][state];
	if (ret != -1) return ret;
	if (state == (1 << n) - 1)
		return ret = val[now][0] > 0 ? val[now][0] : inf;
	ret = inf;
	for (int i = 0; i < n; i++) {
		if (val[now][i] > 0 && !(state&(1 << i))) {
			ret = min(ret, go(state | (1 << i), i) + val[now][i]);
		}
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j =0; j <n; j++)
			scanf("%d", &val[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(1,0));
}
