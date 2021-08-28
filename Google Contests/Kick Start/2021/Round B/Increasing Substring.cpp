#include<bits/stdc++.h>
using namespace std;


int main()
{
	int test; cin >> test;
	for (int t = 1; t <= test; t++)
	{
		int n; string s;
		cin >> n >> s;
		vector<int> answer;
		vector<int> divs;
		for (int i = 1; i < n; i++)
		{
			if (s[i] <= s[i - 1])
			{
				divs.push_back(i);
			}
		}
		if (divs.size() == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				answer.push_back(i);
			}
		}
		else
		{
			for (int j = 1; j <= divs[0]; j++)
			{
				answer.push_back(j);
			}
			for (int i = 1 ; i < divs.size(); i++)
			{
				for (int j = 1; j <= divs[i]-divs[i-1]; j++)
				{
					answer.push_back(j);
				}
			}
			for (int j = 1; j <= n - divs[divs.size() - 1]; j++)
			{
				answer.push_back(j);
			}
		}
		
		

		cout << "Case #" << t << ": ";
		for (auto i : answer)
		{
			cout << i << " ";
		}
		cout << "\n";
	}
}