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
const int MAX = 4000001;
const ll MOD = 1000000007LL;
int N, K;

ll POW(ll b, ll m) {
	if (m == 0) return 1;
	else if (m == 1) return b;

	if (m % 2) return (b * (POW(b, m - 1) % MOD)) % MOD;
	else {
		ll midb = POW(b, m / 2) % MOD;
		return (midb * midb) % MOD;
	}
}

int main() {
	
	int N, K;
	scanf("%d %d", &N, &K);
	long long A = 1;
	long long B = 1;

	for (ll i = 2; i <= N; i++)
	{
		A *= i;
		A %= MOD;
	}
	for (ll i = 2; i <= N - K; i++)
	{
		B *= i;
		B %= MOD;
	}
	for (ll i = 2; i <= K; i++)
	{
		B *= i;
		B %= MOD;
	}
	printf("%lld\n", (A * POW(B, MOD - 2)) % MOD);

}