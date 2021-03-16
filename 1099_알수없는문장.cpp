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

int inf = 1e7;
int N;
string sen;
string word[50];
const char* c;
int word_cost[50][50]; 
int getCost(int start, int index) {
	int end = start + word[index].size();
	if (end > sen.size()) return - 1; 

	int cost = 0;
	int alpha[26] = { 0 };

	for (int i = 0;i < word[index].size();i++) {
		alpha[word[index][i] - 'a']++;
	}
	for (int i = 0;i < word[index].size();i++) {
		if (c[start + i] != word[index][i]) cost++;
		alpha[c[start + i] - 'a']--;
	}
	for (int i = 0;i < 26;i++) {
		if (alpha[i] != 0) return -1; 
	}
	return cost;
}
int go(int start, int index) {
	if (start >= sen.size()) return 0; 
	if (index >= N) return inf;

	int& ret = word_cost[start][index];
	if (ret != -1) return ret;

	ret = inf;
	int cost = getCost(start, index);
	if (cost == -1) return inf;
	int nextstart = start + word[index].size();
	for (int i = 0;i < N;i++) {
		ret = min(ret, go(nextstart, i));
	}
	ret += cost;
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	memset(word_cost, -1, sizeof(word_cost));

	cin >> sen;
	cin >> N;
	c = sen.c_str();
	for (int i = 0;i < N;i++) cin >> word[i];
	int mincost = inf;
	for (int i = 0;i < N;i++) {
		mincost = min(mincost, go(0, i));
	}
	cout << (mincost == inf ?  -1 : mincost) << endl;
	
}