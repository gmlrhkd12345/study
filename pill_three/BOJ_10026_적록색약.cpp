#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
char arr[101][101];
int check1[101][101];
int check2[101][101];
int dr[4] = {0,0,1,-1 };
int dc[4] = {1,-1,0,0 };
int n;
void dfs1(int r,int c,int count)
{
	check1[r][c] = count;
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (1<=nr&&nr<=n&&1<=nc&&nc<=n&&arr[r][c] == arr[nr][nc]&&!check1[nr][nc])
		{
			dfs1(nr, nc, count);
		}
	}
}
void dfs2(int r, int c, int count)
{
	check2[r][c] = count;
	if (arr[r][c] == 'R' || arr[r][c] == 'G')
	{
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (1 <= nr&&nr <= n && 1 <= nc&&nc <= n&&!(arr[nr][nc]=='B') && !check2[nr][nc])
			{
				dfs2(nr, nc, count);
			}
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (1 <= nr&&nr <= n && 1 <= nc&&nc <= n&&arr[nr][nc]=='B' && !check2[nr][nc])
			{
				dfs2(nr, nc, count);
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	int max1 = 0;
	int max2 = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf(" %c",&arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!check1[i][j])
			{
				max1++;
				dfs1(i, j,max1);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!check2[i][j])
			{
				max2++;
				dfs2(i, j, max2);
			}
		}
	}
	printf("%d ", max1);
	printf("%d\n", max2);
}