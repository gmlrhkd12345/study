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
#define MAX 100+1

using ll = long long;
using namespace std;

struct Shark {
	int r;
	int c;
	int s;
	int d;
	int z;
	int num;
};
int R, C, M,size_sum;
vector<int> adj[MAX][MAX];
vector<Shark> shark;
int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,1,-1 };
bool size_greater(int a, int b) {
	if (shark[a].z > shark[b].z) return true;
	return false;
}
bool check() {
	for (int i = 0;i < shark.size();i++) {
		if (shark[i].s != 0) return false;
	}
	return true;
}
void Fishing(int idx) {
	for (int i = 1;i <= R;i++) {
		if (adj[i][idx].size() != 0) {
			size_sum = size_sum + shark[adj[i][idx][0]].z;
			shark[adj[i][idx][0]].z = 0;
			adj[i][idx].clear();
			break;
		}

	}
}
void Moving() {
	for (int i = 0;i < shark.size();i++) {
		if (shark[i].z == 0) continue;
		int r = shark[i].r;
		int c = shark[i].c;
		adj[r][c].clear();
	}
	for (int i = 0;i < shark.size();i++) {
		if (shark[i].z == 0) continue;
		int r = shark[i].r;
		int c = shark[i].c;
		int d = shark[i].d;
		int s = shark[i].s;
		if (d == 1 || d == 2) {
			int goback = (R - 1) * 2;
			if (s >= goback) s %= goback;
			for (int j = 0;j < s;j++) {
				int nr = r + dr[d];
				int nc = c + dc[d];

				if (nr < 1) {
					d = 2;
					nr += 2;
				}
				if (nr > R) {
					d = 1;
					nr -= 2;
				}
				r = nr;
				c = nc;
			}
		}
		else {
			int goback = (C - 1) * 2;
			if (s >= goback) s %= goback;
			for (int j = 0;j < s;j++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				if (nc < 1) {
					d = 3;
					nc += 2;
				}
				if (nc > C) {
					d = 4;
					nc -= 2;
				}
				r = nr;
				c = nc;
			}
		}
		shark[i].r = r;
		shark[i].c = c;
		shark[i].d = d;
		adj[r][c].push_back(i);
	}
}
void Kiling() {
	for (int i = 1;i <= R;i++) {
		for (int j = 1;j <= C;j++) {
			if (adj[i][j].size() > 1) {
				sort(adj[i][j].begin(), adj[i][j].end(), size_greater);
				int live = adj[i][j][0];
				for (int k = 1;k < adj[i][j].size();k++) {
					shark[adj[i][j][k]].z = 0;
				}
				adj[i][j].clear();
				adj[i][j].push_back(shark[live].num);
			}
		}
	}

}
int main() {
	scanf("%d %d %d", &R, &C, &M);
	for (int i = 0;i < M;i++) {
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		shark.push_back({ r,c,s,d,z,i});
		adj[r][c].push_back(i);
	}
	if (M == 0) {
		printf("0\n");
		return 0;
	}
	for (int i = 1;i <= C;i++) {
		if (check()) break;
		Fishing(i);
		Moving();
		Kiling();
		
	}
	printf("%d\n", size_sum);
}