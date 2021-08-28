#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> answers;
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; int k;
		cin >> n >> k;

		int a1 = n / k;
		int a2 = n / k;
		int a3 = n / k;

		int rem = n % 3;

		int theCase = 1;
		if (rem > 0) { a1++; theCase = 2; }
		if (rem > 1) { a2++; theCase = 3; }

		if (theCase == 1)
		{
			answers.push_back({ a1, a2, a3 });
		}
		else
		{
			if (n % 2 == 0 and (n / 2) % 2 == 0)
			{
				answers.push_back({ n / 2, n / 4, n / 4 });
			}
			else if (n % 2 == 0 and (n / 2) % 2 == 1)
			{
				answers.push_back({ (n / 2) - 1, (n / 2) - 1, 2 });
			}
			else if (n % 2 == 1)
			{
				answers.push_back({ (n / 2), (n / 2), 1 });
			}
		}
	}

	for (auto x : answers)
	{
		for (auto i : x)
		{
			cout << i << " ";
		}
		cout << "\n";
	}
}