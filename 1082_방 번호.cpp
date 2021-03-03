#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>
#include <queue>
#include <cstdlib>
using namespace std;

int N, money[50], M;
string num[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
string str;
int main() {
	scanf("%d", &N);
	int min = 50, min_idx, first = 0, num_cnt = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &money[i]);
		if (min >= money[i]) {
			min = money[i];
			min_idx = i;

		}
	}
	scanf("%d", &M);
	while (M >= min) {
		str.append(num[min_idx]);
		M -= min;
		num_cnt++;
	}
	for (int i = 0; i < num_cnt; i++) {
		for (int j = N - 1; j >= 0; j--)
			if (money[j] <= min + M) { 
				str.replace(i, 1, num[j]);
				M += min - money[j]; 
				break; 
		}
		if (str[first] == '0') {
			str.erase(0, 1);
			M += min;
			num_cnt--;
			i = -1;
		}
	}
	if (first == num_cnt) str = "0";
	cout << str << endl;
	return 0;
}