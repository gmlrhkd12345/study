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

ll min_init(vector<ll>& v, vector<ll>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = v[start];
	}
	else {
		return tree[node] = min(min_init(v, tree, node * 2, start, (start + end) / 2), min_init(v, tree, node * 2 + 1, (start + end) / 2 + 1, end));
	}
}

ll min_search(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 1e9;
	if (left <= start && end <= right) return tree[node];

	return min(min_search(tree, node * 2, start, (start + end) / 2, left, right), min_search(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<ll> v(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<ll> min_tree(tree_size);

	for (int i = 0;i < n;i++) scanf("%lld", &v[i]);
	min_init(v, min_tree, 1, 0, n - 1);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", min_search(min_tree, 1, 0, n - 1, a - 1, b - 1));
	}
	return 0;
}