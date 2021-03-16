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
#include <functional>
using namespace std;
long long inf = 99999999999;
struct compare {
	bool operator()(pair<int, long long>& a, pair<int, long long>& b) {
		if (a.second == b.second)
			return a.first > b.first;
		else
			return a.second > b.second;
	}
};
int L, S[50], n;
priority_queue<pair<int, long long>, vector<pair<int, long long>>, compare> q;
vector<int> v;
int main() {
	scanf("%d", &L);
	v.push_back(0);
	for (int i = 0;i < L;i++) {
		scanf("%d", &S[i]);
		q.push({ S[i], 0 }); // q.push(make_pair(S[i],0));와 동일
		v.push_back(S[i]);
	}
	sort(v.begin(), v.end());
	scanf("%d", &n);
	for (int i = 1;i < v.size();i++) {
		if (v[i] - v[i-1] == 1) {
			continue;
		}
		if (v[i] - v[i - 1] <= 200) {
			for (long long j = v[i - 1] + 1;j < v[i];j++) {
				q.push({ j, (j - v[i - 1]) * (v[i] - j) - 1 });
			}
		}
		else {
			for (long long j = v[i - 1] + 1; j <= v[i - 1] + 100;j++) {
				q.push({ j,(j - v[i - 1]) * (v[i] - j) - 1 });
			}
			for (long long j = v[i] - 100;j < v[i];j++) {
				q.push({ j,(j - v[i - 1]) * (v[i] - j) - 1 });
			}
		}
	}
	for (int i = v[v.size() - 1] + 1;i <= v[v.size() - 1] + 100;i++) {
		q.push({i,inf });
	}
	for (int i = 0;i < n;i++) {
		printf("%d ", q.top().first);
		q.pop();
	}

}
