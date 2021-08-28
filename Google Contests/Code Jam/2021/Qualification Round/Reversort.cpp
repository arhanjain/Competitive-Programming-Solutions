#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	for (int test = 1; test <= t; test++)
	{
		int n; cin >> n;
		vector<int> l;
		for (int i = 0; i < n; i++)
		{
			int temp; cin >> temp;
			l.push_back(temp);
		}
		int sum = 0;
		for (int i = 1; i < n; i++)
		{
			int j = distance(l.begin(), min_element(l.begin() + i - 1, l.end())) + 1;
			reverse(l.begin() + i - 1, l.begin() + j);
			sum += j - i + 1;
		}
		cout << "Case #" << test << ": " << sum << "\n";
	}
}