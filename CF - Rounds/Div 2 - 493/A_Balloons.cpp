#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> packs;
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		packs.push_back(temp);
	}
	
	if (n < 2)
	{
		cout << -1;
		return 0;
	}

	vector<int> greg;
	vector<int> ab;
	int g = 0;
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			greg.push_back(packs[n - 1 - i]);
			g += packs[n - 1 - i];
		}
		else
		{
			ab.push_back(packs[n - 1 - i]);
			a += packs[n - 1 - i];
		}
	}
	
	sort(greg.begin(), greg.end());
	sort(ab.begin(), ab.end());

	if (a != g)
	{
		for (auto i : greg)
		{
			cout << i << " ";
		}
	}
	else if (n - greg.size() > 0)
	{
		if (ab[0] < greg[0])
		{
			greg.insert(greg.begin(), ab[0]);
		}
		else
		{
			greg.insert(greg.begin()+1, ab[0]);
		}
		for (auto i : greg)
		{
			cout << i << " ";
		}
	}
	else
	{
		cout << -1;
	}
}