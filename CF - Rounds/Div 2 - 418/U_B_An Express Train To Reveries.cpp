#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a;
	vector<int> b;
	vector<int> diffs;
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		if (temp != a[i]) diffs.push_back(i);
		b.push_back(temp);
	}
	vector<int> a1 = a;

	if (diffs.size() > 1)
	{
		a[diffs[0]] = b[diffs[0]];
		a1[diffs[1]] = b[diffs[1]];
		set<int> aSet;
		for (int i = 0; i < n; i++)
		{
			if (!aSet.insert(a[i]).second)
			{
				for (auto x : a1)
				{
					cout << x << " ";
				}
				return 0;
			}
		}
		for (auto x : a)
		{
			cout << x << " ";
		}
	}
	else
	{
		a[diffs[0]] = 0;
		set<int> aSet(a.begin(), a.end());
		for (int i = 1; i <= n; i++)
		{
			if (aSet.insert(i).second)
			{
				a[diffs[0]] = i;
			}
		}
		for (auto x : a)
		{
			cout << x << " ";
		}
	}
}