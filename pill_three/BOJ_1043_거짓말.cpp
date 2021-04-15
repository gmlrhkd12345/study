#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>
using namespace std;

int n, m, known_num, result;
vector<int> know;
vector<int> party[51];
int parent[51];
int Rank[51];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);	
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	
	if (x == y) return;
	
	if (Rank[x] > Rank[y]) {
		parent[y] = x;
		Rank[x] += Rank[y];
	}
	else {
		parent[x] = y;
		Rank[y] += Rank[x];
	}
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d", &known_num);
	for (int i = 0;i < known_num;i++) {
		int a;
		scanf("%d", &a);
		know.push_back(a);
	}
	for (int i = 0;i < m;i++) {
		int party_people;
		scanf("%d", &party_people);
		for (int j = 0;j < party_people;j++) {
			int a;
			scanf("%d", &a);
			party[i].push_back(a);
		}
	}
	for (int i = 1;i <= n;i++) {
		parent[i] = i;
		Rank[i] = 1;
	}

	
	for (int i = 0;i < m;i++) {
		int now = party[i][0];
		for (int j = 0;j < party[i].size();j++)
			Union(now, party[i][j]);
	}
	
	for (int i = 0;i < m;i++) {
		bool isTrue = true;
		int now = party[i][0];
		for (int j = 0;j < know.size();j++) {
			if (Find(now) == Find(know[j])) {
				isTrue = false;
				break;
			}
		}
		if (isTrue) result++;
	}
	printf("%d\n", result);
}
