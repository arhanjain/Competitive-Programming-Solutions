#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	
	vector<string> answers;

	for (int i = 0; i < t; i++)
	{
		int q = 0;
		int d = 0;
		
		vector<int> lastDigsfake;
		int lastDigs[9];
		cin >> q >> d;

		for (int j = 1; j < 10; j++)
		{
			string mult = to_string(j * d);
			lastDigsfake.push_back(mult[mult.size()-1] - '0');
		}
		for (int j = 0; j < 9; j++)
		{
			lastDigs[lastDigsfake[j]-1] = j+1;
		}
		
		
		string temp = "";
		for (int j = 0; j < q; j++)
		{
			cin >> temp;
			int translated;
			if (stoi(temp) > 99)
			{
				for (int k = 0; k < temp.size(); k++)
				{
					if (temp[k] - '0' == d)
					{
						answers.push_back("YES");
						j++;
						cin >> temp;
						break;
					}
				}
			}
			if (temp[temp.size() - 1] == 0 and stoi(temp) % d == 0)
			{
				answers.push_back("YES");
				j++;
				cin >> temp;
			} 
			else if (temp[temp.size() - 1] == 0 and stoi(temp) % d != 0)
			{
				answers.push_back("NO");
				j++;
				cin >> temp;
			}

			int index = temp[temp.size() - 1] - '0';
			translated = stoi(temp) - lastDigs[index-1] * d;

			if ((translated == 0 or translated % 10 == 0) and translated >= 0)
			{
				answers.push_back("YES");
			}
			else
			{
				answers.push_back("NO");
			}
			
		}

	}

	for (int i = 0; i < answers.size(); i++)
	{
		cout << answers[i] << "\n";
	}
}