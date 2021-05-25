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
const int MIN = 0;
int N;
int main() {
	int cnt = 0;
	scanf("%d", &N);
	vector<int> v;
	v.push_back(MIN);

	for (int i = 0;i < N;i++) {
		int num;
		scanf("%d", &num);
		if (num > v.back()) {
			v.push_back(num);
			cnt++;
		}
		else {
			vector<int>::iterator low = lower_bound(v.begin(), v.end(), num);
			*low = num;
		}
	}
	printf("%d\n", cnt);
	
}