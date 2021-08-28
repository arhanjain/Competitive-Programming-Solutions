#include <bits/stdc++.h>
using namespace std;

bool inc_difficulty(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	int t; cin >> t;

	for (int test = 1; test <= t; test++) {
		int n; int k;
		cin >> n >> k;
		vector<int> sessions;

		for (int i = 0; i < n; i++)
		{
			int temp; cin >> temp;
			sessions.push_back(temp);
		}
		vector<int> diffs;
		for (int i = 1; i < n; i++)
		{
			diffs.push_back(sessions[i] - sessions[i - 1]);
		}
		sort(diffs.begin(), diffs.end());

		int L = 0;
		int R = diffs[n-2];

		while (L < R)
		{
			int mid = (L + R) / 2;
			int calc = 0;
			for (int i = 0; i < n - 2; i++)
			{
				calc += (diffs[i]/mid) + ((diffs[i]%mid) != 0);
			}
			if (calc <= k)
			{
				R = mid;
			}
			else
			{
				L = mid;
			}
		}
		cout << L;
	}
}