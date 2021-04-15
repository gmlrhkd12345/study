#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int error[10];
int n, m;
bool pos(int num) {
	if (num == 0) {
		if (!error[num])
			return true;
		else return false;
	}
	while (num) {
		if (error[num % 10]) return false;
		num /= 10;
	}
	return true;
}
int main(){
	int click;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0;i < m;i++) {
		int a;
		scanf("%d", &a);
		error[a] = 1;
	}
	click = abs(100 - n);
	int chan = 0;
	int min_num = 1e9;
	for (int i = 0;i < 1000001;i++) {
		if (pos(i)) {
			int cnt = abs(n - i);
			if (min_num > cnt) {
				min_num = cnt;
				chan = i;
			}
		}
	}
	min_num += to_string(chan).length();
	click = min(min_num, click);
	printf("%d", click);
}
