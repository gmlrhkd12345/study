#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
char arr[22][22];
int dr[4] = {0,0,1,-1 };
int dc[4] = {1,-1,0,0 };
int alp[30];
int n,m;
int cnt = 1;
void dfs(int r,int c,int count)
{
	if (cnt < count)
		cnt = count;
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		int nal = arr[nr][nc] - 'A' + 1;
		if (1 <= nr&&nr <= n && 1 <= nc&&nc <= m&&!alp[nal])
		{
			alp[nal] = 1;
			dfs(nr, nc,count+1);
			alp[nal] = 0;
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int al = arr[1][1] - 'A' + 1;
	alp[al] = 1;
	dfs(1, 1, 1);
	cout << cnt << endl;
}