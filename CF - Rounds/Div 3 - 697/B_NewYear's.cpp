#include <bits/stdc++.h>
using namespace std;

vector<string> answers;

int main()
{

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		if (n < 2020)
		{
			answers.push_back("NO");
		}
		else
		{
			int nDiv = floor(n / 2020);

			string stringN = to_string(n);
			stringN.erase(stringN.end() - 1);
			if (n % 2020 <= nDiv)
			{
				answers.push_back("YES");
			}
			else
			{
				answers.push_back("NO");
			}
		}
	}

	for (auto element : answers)
	{
		cout << element << "\n";
	}
}