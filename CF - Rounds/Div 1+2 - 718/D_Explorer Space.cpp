#include<bits/stdc++.h>
using namespace std;

int mright[500][500] = { 0 };
int mdown[500][500] = { 0 };
int ans[500][500] = { 0 };
int n; int m; int k;

int dfs(int n1, int m1, int steps)
{
	if (steps == 0)
	{
		return 0;
	}
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { -1,0,1,0 };
	int curr = 0;
	vector<int> bores;
	for (int i = 0; i < 4; i++)
	{
		int n2 = n + dy[i]; int m2 = m + dx[i];
		if (0 <= n2 and n2 < n and 0 <= m2 and m2 < m)
		{
			if (i == 0)
			{
				curr = mdown[n2][m2];
			}
			if (i == 1)
			{
				curr = mright[n2][m2];
			}
			if (i == 2)
			{
				curr = mdown[n1][m1];
			}
			if (i == 3)
			{
				curr = mright[n1][m1];
			}
			bores.push_back(dfs(n2, m2, steps - 1));
		}
	}
	if (bores.size() > 0)
		return curr + *min_element(bores.begin(), bores.end());
	else
		return curr;
}

int main()
{
	
	cin >> n >> m >> k;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			cin >> mright[i][j];
		}
	}
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mdown[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (k % 2)
			{
				ans[i][j] = -1;
				continue;
			}
			int steps = k / 2;
			ans[i][j] = dfs(n, m, steps);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
}