#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;

	while (t--)
	{
		long long n; cin >> n;
		
		long long rem = n % 2050;

		if (rem == 0)
		{
			long long div = n / 2050;
			string s = to_string(div);
			int sum = 0;
			for (int i = 0; i < s.size(); i++)
			{
				sum += s[i] - '0';
			}
			cout << sum << "\n"; 
		}
		else
		{
			cout << -1 << '\n';
		}
	}
}