#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 0;
	cin >> t;
	int t1 = t;
	vector<int> maxScore;

	while (t--)
	{
		int n = 0;
		cin >> n;

		vector<int> a;
		int temp = 0;
		int j = n;
		while (j--)
		{
			cin >> temp;
			a.push_back(temp);
		}

		vector<int> dpScore(n);

		for (int i = n - 1; i > -1; i--)
		{
			dpScore[i] = a[i];
			int idx = i + a[i];

			if (idx < n)
			{
				dpScore[i] += dpScore[idx];
			}
		}
		maxScore.push_back(*max_element(dpScore.begin(),dpScore.end()));
		
	}
	
	for (int i = 0; i < maxScore.size(); i++)
	{
		cout << maxScore[i] << "\n";
	}
	//while()
}