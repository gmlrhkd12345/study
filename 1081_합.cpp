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

long long L, U;

long long Sum(long long n) {
	if (n <= 0) return 0;
	long long num[10] = { 0, }, s = 1, sum = 0, q, r;
	while (n > 0) {
		q = n / (s * 10);
		r = n % (s * 10);

		for (int i = 0;i < 10;i++) 
			num[i] += q * s;

		for (int i = 1;i <= r / s;i++) 
			num[i] += s;

		num[(r / s + 1) % 10] += r % s;
		n -= 9 * s;
		s *= 10;
	}
	for (int i = 1;i < 10;i++) 
		sum += i * num[i];
	return sum;
}
int main() {
	scanf("%lld%lld", &L, &U);
	printf("%lld\n", Sum(U)-Sum(L-1));
}