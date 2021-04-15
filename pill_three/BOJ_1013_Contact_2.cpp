//regex 정규표현식 사용
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <regex>
using namespace std;

int t;
char rep[200];
int flag;

int main() {
	scanf("%d", &t);
	for (int i = 0;i < t;i++) {
		scanf("%s", rep);
		string str(rep);
		regex pattern("(100+1+|01)+");
		if (regex_match(str, pattern)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
