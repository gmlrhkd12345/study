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
#include <stack>

using ll = long long;
using namespace std;
int main() {
	int n;
	stack<pair<int, int>> s;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		int a;
		scanf("%d", &a);
		while (!s.empty()) {
			if (s.top().first >= a) {
				printf("%d ", s.top().second + 1);
				s.push({ a,i });
				break;
			}
			s.pop();

		}
		if (s.empty()) {
			s.push({ a,i });
			printf("0 ");
		}
	}
}