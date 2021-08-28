#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		int idx = -1;
		for (int j = s.size() - 2; j >= 0; j--)
		{
			int len = ceil(double(j) / 2);
			if ((j+1) % 2)
			{
				if (s.substr(0, len).compare(s.substr(len - 1, len)) == 0)
				{
					idx = j;
					break;
				}
			}
			else
			{
				if (s.substr(0, len).compare(s.substr(len, len - 1)) == 0)
				{
					idx = j;
					//break;
				}
			}
		}
		int len = ceil(double(idx) / 2);
		if (s.substr(idx, len).compare(s.substr(len, len - 1)) == 0)
		{
			ans++;
		}
	}
	cout << ans;
}