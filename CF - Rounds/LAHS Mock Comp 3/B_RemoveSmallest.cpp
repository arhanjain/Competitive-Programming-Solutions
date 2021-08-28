#include<bits/stdc++.h>	
using namespace std;

vector<string> answers;

int main()
{
	int t; cin >> t;

	while (t--)
	{
		int n; cin >> n;

		vector<int> arr;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			arr.push_back(a);
		}

		sort(arr.begin(), arr.end());

		string ans = "YES";
		for (int i = 1; i < n; i++)
		{
			if (arr[i] > arr[i - 1] + 1)
			{
				ans = "NO";
			}
		}

		answers.push_back(ans);
	}

	for (auto i : answers)
	{
		cout << i << "\n";
	}
}