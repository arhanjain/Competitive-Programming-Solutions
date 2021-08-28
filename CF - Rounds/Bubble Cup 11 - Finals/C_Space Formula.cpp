#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; int d;
	cin >> n >> d;
	vector<int> s;
	vector<int> p;

	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		s.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		p.push_back(temp);
	}
	reverse(p.begin(), p.end());
	s[d - 1] += p[n - 1];
	int val = s[d - 1];
	int idx = -1;
	for (int i = 0; i < n - 1; i++)
	{

		if (s[d - 1] < s[d - 2] + p[i])
		{
			idx = i - 1;
			break;
		}
	}
	if (idx == -1)
	{
		idx = n - 2;
	}
	for (int i = 0; i <= idx; i++)
	{
		if (d - 2 - i < 0) break;
		s[d - 2 - i] += p[idx - i];
	}

	sort(s.begin(), s.end()); reverse(s.begin(), s.end());

	for (int i = 0; i < n; i++)
	{
		if (s[i] == val)
		{
			cout << i + 1;
			return 0;
		}
	}
}