#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using ll = long long;
using namespace std;
int n;
int fence[17];
int loc[17];
int flag[17];

double s[65536];

double tri_area(int a, int b, int c) {
	int maxnum, sum;
	double p;
	maxnum = a;
	
	if (maxnum < b) maxnum = b;
	if (maxnum < c) maxnum = c;
	
	sum = a + b + c;
	if (sum - maxnum > maxnum) {
		p = sum / 2.0;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	else return -1.0;
}
int check(int num) {
	int n = 0;

	for (int i = 0;i < 16;i++) flag[i] = 0;
	int loc = 0;
	while (num > 0) {
		if (num % 2 == 1) {
			n++;
			flag[loc] = 1;
		}
		else flag[loc] = 0;
		num /= 2;
		loc++;
	}
	return n;
}
int main() {
	scanf("%d", &n);
	loc[0] = 1;
	for (int i = 1;i <= 16;i++) loc[i] = loc[i - 1] * 2;

	for (int i = 0;i < n;i++) scanf("%d", &fence[i]);

	for (int i = 0;i < n;i++) {
		for (int j = i+1;j < n;j++) {
			for (int k = j+1;k < n;k++) {
				s[loc[i] + loc[j] + loc[k]] = tri_area(fence[i], fence[j], fence[k]);
			}
		}
	}
	
	for (int i = 6;i <= n;i += 3) {
		for (int j = 0;j < loc[n];j++) {
			if (check(j) == i) {
				for (int k = 0;k < n;k++) {
					for (int l = k+1;l < n;l++) {
						for (int m = l+1;m < n;m++) {
							if (flag[k] == 1 && flag[l] == 1 && flag[m] == 1) {
								double a;
								if (s[loc[k] + loc[l] + loc[m]] < 0.0 || s[j - (loc[k] + loc[l] + loc[m])] < 0.0) a = -1.0;
								else a = s[loc[k] + loc[l] + loc[m]] + s[j - (loc[k] + loc[l] + loc[m])];

								if (s[j] < a) s[j] = a;
							}
							
						}
					}
				}
			}
		}
	}

	double max_num = s[0];
	for (int i = 1;i < loc[n];i++) {
		if (max_num < s[i]) max_num = s[i];
	}
	printf("%.9lf\n", max_num);
}