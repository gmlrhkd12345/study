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
const int MAX = 10000;
int A, B;
int visited[MAX];
int T;

string bfs(void) {
	queue<pair<int, string>> q;
	q.push({ A,"" });
	visited[A] = 1;
	while (!q.empty()) {
		int num = q.front().first;
		string s = q.front().second;
		int cur_num;
		q.pop();

		if (num == B) return s;

		cur_num = num * 2 % 10000;
		if (!visited[cur_num]) {
			visited[cur_num] = 1;
			q.push({ cur_num, s + "D" });
		}

		cur_num = (num - 1) < 0 ? 9999 : num - 1;
		if (!visited[cur_num]) {
			visited[cur_num] = 1;
			q.push({ cur_num, s + "S" });
		}
		
		cur_num = (num % 1000) * 10 + (num / 1000);
		if (!visited[cur_num]) {
			visited[cur_num] = 1;
			q.push({ cur_num, s + "L" });
		}
		
		cur_num = (num % 10) * 1000 + (num / 10);
		if (!visited[cur_num]) {
			visited[cur_num] = 1;
			q.push({ cur_num, s + "R" });
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf("%d", &T);
	for (int i = 0;i < T;i++) {
		scanf("%d %d", &A, &B);
		cout << bfs() << endl;
		memset(visited, 0, sizeof(visited));

	}
}