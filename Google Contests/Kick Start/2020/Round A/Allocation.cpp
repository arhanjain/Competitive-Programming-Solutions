#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	for(int p = 1; p<= t; p++)
	{
		int n; int b;
		cin >> n >> b;
		vector<int> houses;
		for (int i = 0; i < n; i++)
		{
			int temp; cin >> temp;
			houses.push_back(temp);
		}

		sort(houses.begin(), houses.end());

		int count = 0;
		int sum = 0;
		for (auto x : houses)
		{
			if ((sum += x) <= b)
			{
				count++;
			}
			else
			{
				break;
			}
		}

		cout << "Case #" << p << ": " << count << "\n";
	}
}