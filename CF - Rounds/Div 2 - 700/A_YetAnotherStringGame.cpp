#include<bits/stdc++.h>	
using namespace std;

vector<string> answers;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;

	while (t--)
	{
		string s; cin >> s;

		int len = s.size();

		char turn = 'a';

		for (int i = 0; i < len; i++)
		{
			if (turn == 'a')
			{
				//char temp = *min_element(alphabet.begin(), alphabet.end());
				if (s[i] == 'a') s[i] = 'b';
				else s[i] = 'a';
				turn = 'b';
			}
			else
			{
				if (s[i] == 'z') s[i] = 'y';
				else s[i] = 'z';
				turn = 'a';
			}
			
		}
		answers.push_back(s);
	}

	for (auto element : answers)
	{
		cout << element << "\n";
	}
}