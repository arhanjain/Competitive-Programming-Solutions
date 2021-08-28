#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test; cin >> test;
	for (int t = 1; t <= test; t++)
	{
		int n; int k; string s;
		cin >> n >> k >> s;
		
		int realScore = 0;
		for (int i = 0; i < n/2 + (n%2 != 0); i++)
		{
			if (s[i] != s[n - 1 - i]) realScore++;
		}

		cout << "Case #" << t << ": " << abs(k-realScore) << "\n";
	}
}