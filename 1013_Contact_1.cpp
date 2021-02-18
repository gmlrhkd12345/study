//정규표현식 사용 x
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include<string>
using namespace std;

int t;
char rep[200];
int flag;

void check(string str) {
	int index = 0;
	flag = 1;
	while (index < str.size() && flag) {
		if (str[index] == '0') {
			index += 1;
			if (index >= str.size() || str[index] == '0') {
				flag = 0;
				break;
			}
			index += 1;
		}
		if (str[index] == '1') {
			index += 1;
			int one_next_position = str.find('1', index);
			if (one_next_position == string::npos || one_next_position - index < 2) {
				flag = 0;
				break;
			}
			int zero_next_position = str.find('0', one_next_position);
			if (zero_next_position == str.size() - 1) {
				flag = 0;
				break;
			}
			if (zero_next_position == string::npos) {
				index = str.size();
				break;
			}
			index = zero_next_position;
			if (zero_next_position - one_next_position > 1 && str[zero_next_position + 1] == '0') {
				index -= 1;
			}
		}
	}
	if (index == str.size() && flag) printf("YES\n");
	else printf("NO\n");
}

int main() {
	scanf("%d", &t);
	for (int i = 0;i < t;i++) {
		scanf("%s", rep);
		string str(rep);
		check(str);
	}
	return 0;
}