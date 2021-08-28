#include<bits/stdc++.h>	
using namespace std;

int main()
{
	int n; cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < s.size() - 1; j++)
		{
			if ((j + 1) % 2)
			{
				int len = ceil(double(j+1) / 2);
				int len2 = ceil(double(s.size()-1-j) / 2);
				string r = s.substr(len - 1, len);
				string r2 = s.substr(len2, len2);
				reverse(r.begin(), r.end());
				reverse(r2.begin(), r2.end());
				if (s.substr(0, len).compare(r)==0 and s.substr(j + 1, len2).compare(r2)==0)
				{
					ans++;
					break;
				}
			}
			else
			{
				int len = ceil(double(j) / 2);
				int len2 = ceil(double(s.size() - 1 - j) / 2);
				string r = s.substr(len, len);
				string r2 = s.substr(len2, len2);
				reverse(r.begin(), r.end());
				reverse(r2.begin(), r2.end());
				if (s.substr(0, len).compare(r)==0 and s.substr(j + 1, len2).compare(r2)==0)
				{
					ans++;
					break;
				}
			}
		}
	}
	cout << ans;
}