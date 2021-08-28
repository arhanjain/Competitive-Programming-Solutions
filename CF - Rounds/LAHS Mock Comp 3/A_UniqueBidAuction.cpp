#include<bits/stdc++.h>
using namespace std;
const int maxn = 200001;

vector<int> answers;
int main()
{
	int t; cin >> t;

	while (t--)
	{
		int n; cin >> n;
		vector<int> instances;
		vector<int> indexes;

		for (int i = 0; i < n+1; i++)
		{
			instances.push_back(0);
			indexes.push_back(0);
		}
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			
			instances[a]++;
			indexes[a]+= i+1;		
			
		}

		int answer = -1;
		for (int i = 1; i <= n; i++)
		{
			if (instances[i] == 1)
			{
				answer = indexes[i];
				break;
			}
		}

		answers.push_back(answer);
	}

	for (auto i : answers)
	{
		cout << i << "\n";
	}
}