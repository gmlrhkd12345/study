#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>
#include <queue>
#include <cstdlib>
using namespace std;

int S, F, M;
int a[100001];
vector<int> p;
int c[100001];
vector<pair<long long, long long>> v;
long long solve(int num, int index) {
	long long j = 1, cnt = 0;
	while (true) {
		if (num / (p[index] * j)) cnt += num / (p[index] * j);
		else break;
		j *= p[index];

	}
	return cnt;
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
	long long com_num;
	scanf("%d %d %d", &S, &F, &M);
	prime(M);
	for (int i = 0;i < p.size();i++) {
		com_num = solve(S + F, i) - solve(S, i) - solve(F, i);
		c[p[i]] = com_num;
	}
	int ans = 1;
	for (int i = M;i >= 2;i--) {
		int t = i;
		int j;
		for (j = 0;j < p.size();j++) {
			int k = 0;
			while (t % p[j] == 0) {
				t /= p[j];
				k++;
			}
			if (k > c[p[j]]) break;
		}
		if (j == p.size()) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);

}
