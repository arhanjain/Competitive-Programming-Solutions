#include<bits/stdc++.h>
using namespace std;

struct path
{
	int length;
	int n;
	int m;
};

bool sortPath(path a, path b)
{
	if (a.length != b.length)
	{
		return a.length < b.length;
	}
	return a.n < b.n;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;

	while (t--)
	{
		int m; int n;
		cin >> n >> m;
		vector<path> ordered;
		vector<int> paths[101];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int temp; cin >> temp;
				path tem; tem.length = temp; tem.n = i; tem.m = j;
				paths[i].push_back(temp);
				ordered.push_back(tem);
			}
		}
		sort(ordered.begin(), ordered.end(), sortPath);
		int ans[101][101] = {0};
		for (int i = 0; i < m; i++)
		{
			ans[ordered[i].n][i] = ordered[i].length;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!ans[i][j])
				{
					vector<int>::iterator it = max_element(paths[i].begin(), paths[i].end());
					int idx = distance(paths[i].begin(), it);
					ans[i][j] = paths[i][idx];
					paths[i][idx] = -1;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
}