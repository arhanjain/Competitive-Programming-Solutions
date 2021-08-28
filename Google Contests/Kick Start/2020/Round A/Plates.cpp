#include <bits/stdc++.h>
using namespace std;

struct plate {
	int val;
	int row;
	int col;
};

bool decreasingPlates(plate a, plate b)
{
	if (a.val == b.val)
	{
		return a.col < b.col;
	}
	return a.val < b.val;
}

plate stacks[50][30];
vector<plate> plates;

int main()
{
	int t; cin >> t;
	for (int j = 0; j <= t; j++)
	{
		plates.clear();
		memset(stacks, 0, sizeof(stacks));

		int n; int k; int p;
		cin >> n >> k >> p;
	
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < k; c++)
			{
				plate temp;
				cin >> temp.val;
				temp.row = r;
				temp.col = c;

				stacks[r][c] = temp;
				plates.push_back(temp);
			}
		}

		sort(plates.begin(), plates.end());

		int count = 0;
		int idx = 0;
		vector<int> used(50);
		while (count < p)
		{
			plate currPlate = plates[idx];

			if (count + (currPlate.col + 1 - used[currPlate.row]) <= p)
			{
				count += currPlate.col + 1 - used[currPlate.row];
				used[currPlate.row] = currPlate.col + 1;

			}

			idx++;
		}
	}
}