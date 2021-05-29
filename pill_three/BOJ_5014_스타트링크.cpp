#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int f, s, g, u, d;
int arr[1000001];
int check[1000001];
int num;
queue <pair<int,int>> q1;
void bfs(int s,int a)
{

	q1.push(make_pair(s,a));
	check[s] = 1;
	while (!q1.empty())
	{
		int x = q1.front().first;
		int y = q1.front().second;
		q1.pop();
		if (x == g)
		{
			num = y;
			return;
		}
		int nx1 = x + u;
		if (nx1>=1&&nx1 <= f&&!check[nx1])
		{
			q1.push(make_pair(nx1, y + 1));
			check[nx1] = 1;
		}
		int nx2 = x - d;
		if (nx2>=1&&nx2 <= f && !check[nx2])
		{
			q1.push(make_pair(nx2, y + 1));
			check[nx2] = 1;
		}
	}
}
int main()
{
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	bfs(s, 0);
	if (s != g)
	{
		if (num == 0)
			printf("use the stairs\n");
		else
			printf("%d\n", num);
	}
	else if (s == g)
		printf("0\n");

}
