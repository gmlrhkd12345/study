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
int X, Y, D, T;
int main() {
	scanf("%d %d %d %d", &X, &Y, &D, &T);
	double dist = sqrt(X * X + Y * Y);
	double dep_time = dist;
	int jump = dist / D;
	dist -= jump * D;
	if (jump == 0) {
		dep_time = min(dep_time, T+(D-dist)); 
		dep_time = min(dep_time, T * 2.0); 
	}
	else {
		dep_time = min(dep_time, T * jump + dist);
		dep_time = min(dep_time, T * (jump + 1.0));
	}
	printf("%.9f", dep_time);

}