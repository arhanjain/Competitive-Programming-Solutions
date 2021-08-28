#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; int x;
	cin >> n >> x;

	vector<int> timeReq;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		timeReq.push_back(a);
	}

	sort(timeReq.begin(), timeReq.end());

	int timeSpend = 0;
	int algos = 0;
	for (int i = 0; i < n; i++)
	{
		if (timeSpend + timeReq[i] <= x)
		{
			timeSpend += timeReq[i];
			algos++;
			//cout << timeSpend;
		}
	}

	cout << algos;
}