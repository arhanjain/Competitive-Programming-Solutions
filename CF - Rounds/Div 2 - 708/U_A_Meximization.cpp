#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> answers;
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> a;
		vector<int> count(101);

		for (int i = 0; i < n; i++)
		{
			int temp; cin >> temp;
			a.push_back(temp);
		}

		for (int i = 0; i < n; i++)
		{
			count[a[i]]++;
		}
		for (int i = 0; i < 101; i++)
		{
			count[i]--;
		}

		set<int> bUnique(a.begin(), a.end());

		vector<int> b(bUnique.begin(), bUnique.end());

		
		for (int i = bUnique.size() - 1; i >= 0; i--)
		{
			set<int>::iterator it = bUnique.begin();
			advance(it, i);
			for (int j = 0; j < count[*it]; j++)
			{
				b.push_back(*it);
			}
		}

		answers.push_back(b);
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