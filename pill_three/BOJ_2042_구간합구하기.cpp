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


ll init(vector<ll> &v, vector<ll> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = v[start];
	}
	else {
		
		return tree[node] = init(v, tree, node * 2, start, (start + end) / 2) + init(v, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
	
}

void update(vector<ll>& tree, int node, int start, int end, int index, ll diff) {
	if (index<start || index>end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

ll sum(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0; 
	if (left <= start && end <= right) return tree[node]; 
	
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<ll> v(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<ll> tree(tree_size);
	m += k;
	for (int i = 0;i < n;i++) scanf("%lld", &v[i]);
	init(v, tree, 1, 0, n - 1); 
	while (m--) {
		int t1;
		scanf("%d", &t1);
		if (t1 == 1) {
			int t2;
			ll t3;
			scanf("%d %lld", &t2, &t3);
			t2 -= 1; 
			ll diff = t3 - v[t2];
			v[t2] = t3;
			update(tree, 1, 0, n - 1, t2, diff);
		}
		else if (t1 == 2) {
			int t2, t3;
			scanf("%d %d", &t2, &t3);
			printf("%lld\n", sum(tree, 1, 0, n - 1, t2 - 1, t3 - 1));
		}
	}
	return 0;
}
