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
char number[5][39] = {
{'#','#','#','.','.','.','#','.','#','#','#','.','#','#','#','.','#','.','#','.','#','#','#','.','#','#','#','.','#','#','#','.','#','#','#','.','#','#','#'},
{'#','.','#','.','.','.','#','.','.','.','#','.','.','.','#','.','#','.','#','.','#','.','.','.','#','.','.','.','.','.','#','.','#','.','#','.','#','.','#'},
{'#','.','#','.','.','.','#','.','#','#','#','.','#','#','#','.','#','#','#','.','#','#','#','.','#','#','#','.','.','.','#','.','#','#','#','.','#','#','#'},
{'#','.','#','.','.','.','#','.','#','.','.','.','.','.','#','.','.','.','#','.','.','.','#','.','#','.','#','.','.','.','#','.','#','.','#','.','.','.','#'},
{'#','#','#','.','.','.','#','.','#','#','#','.','#','#','#','.','.','.','#','.','#','#','#','.','#','#','#','.','.','.','#','.','#','#','#','.','#','#','#'}
};
char s[5][39];
int n;
vector<vector<int>> v;
void go(int n) {


}
int main() {
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 4 * n - 1;j++) {
			scanf(" %c", &s[i][j]);
		}
	}
	int number_index = 0;
	int s_index = 0;
	int flag = 0;
	while (true) {
		if (s_index == n) break;
		for (int i = 0;i < 5;i++) {
			for (int j = 0;j < 3;j++) {
				if (s[i][j + 4 * s_index] != number[i][j + 4 * number_index]) {
					if (s[i][j+4*s_index] == '#' && number[i][j+4*number_index] == '.') {
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1) break;
		}
		if (flag == 0) {
			v[s_index].push_back(number_index);
		}
		flag = 0;
		number_index++;
		if (number_index==10) {
			number_index = 0;
			s_index++;
		}
	}
	double dig = pow(10, n-1);
	double avg = 0;
	for (int i = 0;i < v.size();i++) {
		if (v[i].size() == 0) {
			printf("-1\n");
			return 0;
		}
		double sum = 0;
		for (int j = 0;j < v[i].size();j++) {
			sum += v[i][j] * dig;
		}
		dig /= 10;
		avg += sum/v[i].size();
	}
	printf("%f", avg);
}
