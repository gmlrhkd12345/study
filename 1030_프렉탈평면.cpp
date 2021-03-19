#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>
using namespace std;

int s, n, k;
int size; 

int getColor(int y, int x)
{
	int square_num = size / n; 
	int border_dist = (n - k) / 2; 
	while (square_num > 0)
	{
		if (y / square_num >= border_dist && y / square_num <= (n-1) - border_dist && x / square_num >= border_dist && x / square_num <= (n-1) - border_dist) {
			return 1;
		}
		
		if (y >= square_num) y %= square_num;
		if (x >= square_num) x %= square_num;
		square_num /= n;

	}
	return 0;
}
int main()
{
	int r1, r2, c1, c2;
	scanf("%d %d %d %d %d %d %d", &s, &n, &k, &r1, &r2, &c1, &c2);

	size = pow(n, s); //s에 따른 nxn의 확장된 가로/세로 크기

	for (int i = r1;i <= r2;i++) {
		for (int j = c1;j <= c2;j++) {
			printf("%d", getColor(i, j));
		}
		printf("\n");
	}
}