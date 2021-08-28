#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		vector<long long> fences;
		for (int i = 0; i < m; i++)
		{
			long long temp; cin >> temp;
			fences.push_back(temp);
		}
		sort(fences.begin(), fences.end());

		cout << fences[m - 1] * fences[m - 2] << "\n";
	}
}