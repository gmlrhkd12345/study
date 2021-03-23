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
int N, t[10];
ll Coe[10];
bool isFirst[10];
string s[50];
pair<ll, int> p[10];
int main() {
	cin >> N;
	for (int i = 0;i < N;i++) cin >> s[i];
	for (int i = 0;i < N;i++) {
		string st = s[i];
		ll k = 1;
		for (int j = st.size() - 1;j >= 0;j--) {
			Coe[st[j] - 'A'] += k;
			k *= 10;
		}
	}
	for (int i = 0;i < N;i++) isFirst[s[i][0] - 'A'] = 1;

	for (int i = 0;i < 10;i++) p[i] = { Coe[i],i };
	sort(p, p + 10);

	if (p[0].first != 0 && isFirst[p[0].second]) {
		int idx = 1;
		for (;;idx++) if (!isFirst[p[idx].second]) break;
		pair<ll,int> tmp = p[idx];
		for (int i = idx - 1;i >= 0;i--) p[i + 1] = p[i];
		p[0] = tmp;
	}

	for (int i = 9;i >= 0;i--) {
		if (p[i].first == 0) break;
		t[p[i].second] = i;
	}
	ll ans = 0;

	for (int i = 0;i < N;i++) {
		string st = s[i], ret;
		for (int j = 0;j < st.size();j++) ret += t[st[j] - 'A'] + '0';
		ans += stoll(ret);
	}
	cout << ans;
}