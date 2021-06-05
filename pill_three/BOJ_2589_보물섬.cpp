#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
char arr[51][51];
int check[51][51];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
using namespace std;
int n, m;
int bfs(int r, int c)
{
	check[r][c] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	int ret = 0;
	while (!q.empty())
	{
		int nr = q.front().first;
		int nc = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nnr = nr + dr[i];
			int nnc = nc + dc[i];
			if (!check[nnr][nnc] && arr[nnr][nnc] == 'L')
			{
				check[nnr][nnc] = check[nr][nc] + 1;
				ret = max(ret, check[nnr][nnc]);
				q.push(make_pair(nnr, nnc));
			}
		}
	}
	return ret;

}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf(" %c", &arr[i][j]);
		}
	}
	int ans=0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 'L')
			{
				ans = max(ans, bfs(i, j));
				memset(check, 0, sizeof(check));
			}
		}
	}
	printf("%d\n", ans - 1);
}