#include<bits/stdc++.h>
using namespace std;

vector<int> answers;

bool decreasing(int a, int b)
{
	return a > b;
}

int main()
{
	int t; cin >> t;

	while (t--)
	{
		int n; cin >> n;

		vector<int> original;
		set<int> visited;
		
		int uniqNums = 0;

		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			original.push_back(a);
			if (visited.insert(a).second)
			{
				uniqNums++;
			}
		}
		vector<vector<int>> lessAdjs;
		for (int i = 0; i <= n; i++)
		{
			lessAdjs.push_back({ 0,0 });
		}
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				if (original[i] > original[i + 1] )
				{
					lessAdjs[original[i]][0]++;
					lessAdjs[original[i]][1] = i;
				}
			}
			else if (i == n - 1)
			{
				if ( original[i] > original[i - 1])
				{
					lessAdjs[original[i]][0]++;
					lessAdjs[original[i]][1] = i;
				}
			}
			else
			{
				if (original[i] > original[i+1] or original[i] > original[i-1])
				{
					lessAdjs[original[i]][0]++;
					lessAdjs[original[i]][1] = i;
				}
			}
		}
		
		if (uniqNums > 1)
		{
			vector<int> sorted(original.begin(), original.end());
			for (int i = sorted.size() - 1; i >= 0; i--)
			{
				if (lessAdjs[sorted[i]][0] >= 1)
				{
					answers.push_back(lessAdjs[sorted[i]][1]+1);
					break;
				}
			}
		}
		else {
			answers.push_back(-1);
		}
	}

	for (auto i : answers)
	{
		cout << i << "\n";
	}
}