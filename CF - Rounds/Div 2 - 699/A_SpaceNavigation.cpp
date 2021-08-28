#include<bits/stdc++.h>	
using namespace std;
vector<string> answers;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--)
	{
		string willReach = "YES";

		int xpos; int ypos;
		cin >> xpos >> ypos;

		string s; cin >> s;

		int ups = 0; int downs = 0; int lefts = 0; int rights = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'U') ups++;
			if (s[i] == 'D') downs++;
			if (s[i] == 'L') lefts++;
			if (s[i] == 'R') rights++;
		}

		if (xpos > 0 and rights < xpos)
		{
			willReach = "NO";
		}
		if (xpos < 0 and lefts < abs(xpos))
		{
			willReach = "NO";
		}
		if (ypos >  0 and ups < ypos)
		{
			willReach = "NO";
		}
		if (ypos < 0 and downs < abs(ypos))
		{
			willReach = "NO";
		}

		answers.push_back(willReach);
	}

	for (auto i : answers)
	{
		cout << i << "\n";
	}
}