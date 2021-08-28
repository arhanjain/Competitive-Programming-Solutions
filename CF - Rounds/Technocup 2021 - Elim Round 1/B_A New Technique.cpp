#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		int m; int n;
		cin >> m >> n;
		vector<int> a[500];
		vector<int> b[500];
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int temp; cin >> temp;
				a[i].push_back(temp);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int temp; cin >> temp;
				b[i].push_back(temp);
			}
		}
		pair<int, int> place;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[0][0] == b[i][j])
				{
					place = make_pair(i, j);
				}
			}
		}
		//place.first is row value
		map<int, int> rows;
		for (int i = 0; i < m; i++)
		{
			rows.insert({ a[i][0], i });
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << a[rows[b[place.first][i]]][j] << " ";
			}
			cout << "\n";
		}
	}
}