#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test; cin >> test;
	for (int t = 1; t <= test; t++)
	{
		int r; int c;
		cin >> r >> c;
		vector<int> house[300];
		vector<int> maxs(300);
		for (int i = 0; i < r; i++)
		{
			int max = 0;
			for (int j = 0; j < c; j++)
			{
				int temp; cin >> temp;
				house[i].push_back(temp);
				if (temp > max) max = temp;
			}
			maxs[i] = max;
		}
		
		for (int i = 0; i < r; i++)
		{
			for(int j = 0; )
		}
	}
}