#include<bits/stdc++.h>
using namespace std;

const int maxn = 100001;
struct ppp
{
	int val;
	int start;
	int end;
};
int main()
{
	int test; cin >> test;
	for (int t = 1; t <= test; t++)
	{
		int n; cin >> n;
		int a[maxn];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		vector<int> diffs;
		for (int i = 1; i < n; i++)
		{
			diffs.push_back(a[i] - a[i - 1]);
		}

		vector<ppp> intervals; //start and end of each interval
		int curr = diffs[0];
		int start = 0; int end = -1;
		for (int i = 1; i < n-1; i++)
		{
			if (diffs[i] != curr)
			{
				end = i-1;
				ppp temp; temp.val = curr; temp.start = start; temp.end = end;
				intervals.push_back(temp);
				start = i;
				curr = diffs[i];
			}
		}
		
		ppp temp; temp.val = curr; temp.start = start; temp.end = n - 2;
		intervals.push_back(temp);
		

		int idx = -1;
		int maxRange = -1;
		for (int i = 1; i < intervals.size()-2; i++)
		{
			if (intervals[i].start == intervals[i].end and intervals[i+1].start == intervals[i+1].end) //and intervals[i].end == intervals[i + 1].start)
			{
				ppp last = intervals[i - 1]; ppp after = intervals[i + 2];
				if (last.val == after.val)
				{
					if (last.end - last.start + after.end - after.start > maxRange)
					{
						idx = i;
						maxRange = last.end - last.start +2 + after.end - after.start + 2 + 1;
					}
				}
			}
		}
		

		if (maxRange == -1)
		{
			for (int i = 0; i < intervals.size(); i++)
			{
				if (intervals[i].end - intervals[i].start > 0)
				{
					maxRange = intervals[i].end - intervals[i].start + 3;
				}
			}
			for (int i = 0; i < intervals.size(); i++)
			{
				if (intervals[i].end - intervals[i].start > maxRange)
				{
					maxRange = intervals[i].end - intervals[i].start + 3;
				}
			}
		}

		if (intervals.size() == 1)
		{
			maxRange = n;
		}

		cout << "Case #" << t << ": " << maxRange << "\n";
	}
}

/*
1
6
9 8 4 3 8 1
*/