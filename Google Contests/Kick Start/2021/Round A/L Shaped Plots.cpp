#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test; cin >> test;
	for (int t = 1; t <= test; t++)
	{
		int r; int c;
		cin >> r >> c;
		vector<int> plot[1000];
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int temp; cin >> temp;
				plot[i].push_back(temp);
			}
		}
		
		vector<pair<int, int>> segsVert[1000]; //start of seg, end of seg
		for (int j = 0; j < c; j++) // create good segments for each column 
		{
			for (int i = 0; i < r; i++)
			{
				if (plot[i][j] == 1)
				{
					int start = i;
					int end = 0;
					int k = i;
					for (k = i; k < r; k++)
					{
						if (plot[k][j] == 0)
						{
							break;
						}
					}
					end = k - 1;
					if(end-start > 0) segsVert[j].push_back(make_pair(start, end));
					i = end + 1;
				}
			}
		}

		vector<pair<int, int>> segsHor[1000]; //start of seg, end of seg
		for (int i = 0; i < r; i++) // create good segments for each column 
		{
			for (int j = 0; j < c; j++)
			{
				if (plot[i][j] == 1)
				{
					int start = j;
					int end = 0;
					int k = j;
					for (k = j; k < c; k++)
					{
						if (plot[i][k] == 0)
						{
							break;
						}
					}
					end = k - 1;
					if (end - start > 0) segsHor[i].push_back(make_pair(start, end));
					j = end + 1;
				}
			}
		}

		for (int col = 0; col<segsVert) { for(auto segVert : col)
		{
			for (auto row : segsHor) { for(auto segHor : row)
			{

			}}
		}}
		
	}
}