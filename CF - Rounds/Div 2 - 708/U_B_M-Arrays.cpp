#include<bits/stdc++.h>	
using namespace std;

int binSearch(int target, vector<int> a)
{
	int L = 0; int R = a.size() - 1;
	while (L < R)
	{
		int mid = (L + R) / 2;
		if(mid == target)
		{
			return mid;
		}
		else if (mid < target)
		{
			L = mid;
		}
		else
		{
			R = mid;
		}
	}
	return -1;
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		vector<int> uses(100001);

		int n; int m;
		cin >> n >> m;
		vector<int> a;
		for (int i = 0; i < n; i++)
		{
			int temp; cin >> temp;
			a.push_back(temp);
		}

		sort(a.begin(), a.end());
		vector<int> aRem = a;

		for (int i = 0; i < a.size(); i++)
		{
			int target = ((a[i] / m) + 1) * m - a[i];
			int idx = binSearch(target, a);
			if (idx != -1)
			{

			}
			else
			{
				uses[i]++;
			}
		}
	}
}