#include<bits/stdc++.h>
using namespace std;

int calcCost(int idx, string s, int x, int y, char icon)
{
	int sum = 0;
	if (s[idx - 1] == 'J' and icon == 'C')
	{
		sum += y;
	}
	if (s[idx - 1] == 'C' and icon == 'J')
	{
		sum += x;
	}
	if (s[idx + 1] == 'J' and icon == 'C')
	{
		sum += x;
	}
	if (s[idx + 1] == 'C' and icon == 'J')
	{
		sum += y;
	}
	return sum;
}

int main()
{
	int test; cin >> test;
	for (int t = 1; t <= test; t++)
	{
		int x; int y; string s;
		cin >> x >> y >> s;
		vector<pair<int,int>> empty;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '?') {
				int start = i;
				int end = -1;
				for (int j = i + 1; j < s.size(); j++)
				{
					if (s[j] != '?')
					{
						end = j - 1;
						i = j;
						break;
					}
				}
				if (end == -1)
				{
					end = s.size() - 1;
					i = s.size();
				}
				empty.push_back(make_pair(start, end));
			}
		}

		int cost = 0;

		for (int i = 0; i < empty.size(); i++) // costs of the segments of ?
		{
			pair<int, int> seg = empty[i];
			if (seg.first == 0)
			{

			}
			else if (seg.second == s.size()-1)
			{

			}
			else
			{
				char first = s[seg.first - 1];
				char last = s[seg.second + 1];
				if (first == 'J' and last == 'C')
				{
					cost += y;
				}
				else if (first == 'C' and last == 'J')
				{
					cost += x;
				}
			}
		}

		for (int i = 0; i < s.size(); i += 2)			//calculating default cost of the non ?s
		{
			if (i == s.size() - 1)
			{
				if (s[i - 1] == 'J' and s[i] == 'C')
				{
					cost += y;
				}
				if (s[i - 1] == 'C' and s[i] == 'J')
				{
					cost += x;
				}
			}
			else if (i == 0)
			{
				if (s[i + 1] == 'J' and s[i] == 'C')
				{
					cost += x;
				}
				if (s[i + 1] == 'C' and s[i] == 'J')
				{
					cost += y;
				}
			}
			else
			{
				cost += calcCost(i, s, x, y, s[i]);
			}
		}


		cout << "Case #" << t << ": " << cost << "\n";
	}
}