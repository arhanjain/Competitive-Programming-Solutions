#include <bits/stdc++.h>
using namespace std;
vector<int> answers;
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; int k;
		cin >> n >> k;

		if (n % 2 == 0)
		{
			if (k % n == 0)
			{
				answers.push_back(n);
			}
			else 
			{
				answers.push_back(k % n);
			}
		}
		else
		{
			//3 3
			k--;
			int overlaps = k / int(floor(n / 2.0));
			
			answers.push_back((k + overlaps) % n +1);
		}
	}

	for (auto i : answers)
	{
		cout << i << "\n";
	}
}