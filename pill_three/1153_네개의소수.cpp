#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
using ll = long long;
using namespace std;
vector<int> p;
int a[1000001];
int n;
vector<int> v;
int flag = 0;
void find(int num) {
	if (num < 8) {
		printf("-1\n");
		return;
	}
	if (num % 2) {
		v.push_back(2);
		v.push_back(3);
		num -= 5;
	}
	else {
		v.push_back(2);
		v.push_back(2);
		num -= 4;
	}
	for (int i = 0;i < p.size();i++) {
		if (a[p[i]] != 0 && a[num - p[i]] != 0) {
			v.push_back(p[i]), v.push_back(num - p[i]);
		}
		if (v.size() == 4) break;
	}
	if (v.size() != 4) {
		printf("-1\n");
	}
	else {
		for (int i = 0;i < v.size();i++)
			printf("%d ", v[i]);
	}
}
void prime(int num) {
	int j;
	for (int i = 2;i <= num;i++) a[i] = i;
	for (int i = 2;i <= sqrt(num);i++) {
		if (a[i] == 0) continue;
		for (int j = i + i;j <= num;j += i) a[j] = 0;
	}
	for (int i = 2;i <= num;i++) {
		if (a[i] != 0)	p.push_back(i);
	}
}
int main() {
	scanf("%d", &n);
	prime(n);
	find(n);
	
}