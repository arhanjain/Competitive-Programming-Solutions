#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	vector<string> answers;

	while (t--)
	{
		int n = 0;
		cin >> n;

		vector<int> aOdds;
		vector<int> aEvens;
		int m = n;
		int temp = 0;
		while (m--)
		{
			cin >> temp;
			if(!(temp % 2)) aEvens.push_back(temp);
			if ((temp % 2)) aOdds.push_back(temp);
			
		}
		/*int runs = min(aEvens.size(), aOdds.size());
		
		int alice = accumulate(aEvens.begin(), aEvens.begin() + runs, 0);
		int bob = accumulate(aOdds.begin(), aOdds.begin() + runs, 0);
		if (aOdds.size() > runs)
		{
			for (int i = runs+1; i < aOdds.size(); i++)
			{
				if ((i % 2))
				{
					bob += aOdds[i];
				}
			}
		}
		else if (aEvens.size() > runs)
		{
			for (int i = runs + 1; i < aEvens.size(); i++)
			{
				if ((i % 2))
				{
					alice += aEvens[i];
				}
			}
		}
		
		if (alice == bob)
		{
			answers.push_back("Tie");
		}
		else if (alice > bob)
		{
			answers.push_back("Alice");
		}
		else
		{
			answers.push_back("Bob");
		}*/
		int alice = 0;
		int bob = 0;
		
		while (aEvens.size() > 0 and aOdds.size() > 0)
		{
			int maxEven = *max_element(aEvens.begin(), aEvens.end());
			int maxOdd = *max_element(aOdds.begin(), aOdds.end());
			if (maxEven > 0 and maxOdd > 0)
			{
				if (maxEven >= maxOdd)
				{
					alice += maxEven;
					bob += maxOdd;

					aEvens.erase(max_element(aEvens.begin(), aEvens.end()));
					aOdds.erase(max_element(aOdds.begin(), aOdds.end()));
				}
				else
				{

				}
			}
		}
	}

	

	for (int i = 0; i < answers.size(); i++)
	{
		cout << answers[i];
	}
}