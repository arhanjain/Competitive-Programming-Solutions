#include<bits/stdc++.h>
using namespace std;

vector<int> answers;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 0;
	cin >> t;

	int n = 0;
	for (int i = 0; i < t; i++)
	{
		vector<int> balls;
		int max = 1;

		cin >> n;


		int temp = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			balls.push_back(temp);
		}

		int currentVal = balls[0];
		int occurrences = 1;
		for (int j = 1; j < n; j++)
		{
			
			
			if (balls[j] == currentVal)
			{
				occurrences++;
				if (j == n - 1)
				{
					if (max < occurrences)
					{
						max = occurrences;
					}
				}
			}
			else
			{
				if (max < occurrences)
				{
					max = occurrences;
				}
				currentVal = balls[j];
				occurrences = 1;
			}
		}

		answers.push_back(max);
	}

	for (int i = 0; i < answers.size(); i++)
	{
		cout << answers[i] << "\n";
	}
}