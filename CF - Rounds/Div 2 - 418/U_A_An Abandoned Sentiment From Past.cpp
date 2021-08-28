#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; int k;
	vector<int> hitagi;
	vector<int> kaiki;

	vector<int> zeros;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		if (temp == 0) zeros.push_back(i);
		hitagi.push_back(temp);
	}
	for (int i = 0; i < k; i++)
	{
		int temp; cin >> temp;
		kaiki.push_back(temp);
	}

	sort(kaiki.begin(), kaiki.end());
	
	for (int i = 0; i < zeros.size(); i++)
	{
		hitagi[zeros[i]] = kaiki[k - 1 - i];
	}
	int last = 0;
	for (int i = 0; i < n; i++)
	{
		if (hitagi[i] < last)
		{
			cout << "Yes";
			return 0;
		}
		last = hitagi[i];
	}
	cout << "No";
}