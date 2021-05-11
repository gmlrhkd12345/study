#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
queue<pair<int, int>> q;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[101][101];
int check[101][101];
int bridge[101][101];
int n;
int minb=10000;
int num;
void dfs(int x, int y,int here)
{
	check[x][y] = here;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (1 <= nx&&nx <= n && 1 <= ny&&ny <= n&&arr[nx][ny] == 1 && !check[nx][ny])
		{
			dfs(nx, ny, here);
		}
	}
}
void bfs(int island)
{
	int size;
	while (!q.empty())
	{
		size = q.size();
		num++;
		for (int i = 0; i < size; i++)
		{
			int nr = q.front().first;
			int nc = q.front().second;
			q.pop();
			if (check[nr][nc] != 0 && check[nr][nc] != island)
			{
				minb = min(minb, num);
				return;
			}
			for (int j = 0; j < 4; j++)
			{
				int nnr = nr + dx[j];
				int nnc = nc + dy[j];
				if (1 <= nnr&&nnr <= n && 1 <= nnc&&nnc <= n && bridge[nnr][nnc] == 0)
				{
					bridge[nnr][nnc] = 1;
					q.push(make_pair(nnr, nnc));
				}
			}
		}
	}
}
int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int here = 2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 1 && !check[i][j])
			{
				dfs(i, j, here++);
			}
		}
	}
	for (int k = 2; k < here; k++)
	{
		num = -1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (check[i][j] == k)
				{
					q.push(make_pair(i, j));
					bridge[i][j] = 1;
				}
			}
		}
		bfs(k);
		memset(bridge,0,sizeof(bridge));
		while (!q.empty()) 
		{
			q.pop();
		}
	}
	printf("%d\n", minb-1);
}