#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>
using namespace std;

int N;
vector<string> arr;
char num[10] = { '0','1','2','3','4','5','6','7','8','9' };
int digit_loc[10];
int main() {
	scanf("%d", &N);
	for (int i = 0;i <= 9;i++) arr.push_back(to_string(i));

	int digit = 1;
	int loc = 1;
	int j = 0;
	int first = 0;
	int k = 0;
	while (digit < 10) {
		for (int i = j;i <= arr.size();i++) {
			if (arr[i][0] < num[loc] && arr[i].length() == digit) {
				arr.push_back(to_string(loc) + arr[i]);
				if (first == 0) {
					k = arr.size()-1;
					first = 1;
				}
			}
			else break;
		}
		loc++;
		if (loc == 10) {
			digit++;
			loc = digit;
			first = 0;
			j = k;
		}
		
	}
	if (N > arr.size()-1) printf("-1\n");
	else cout << arr[N] << endl;
}
