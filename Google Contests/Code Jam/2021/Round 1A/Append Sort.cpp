#include<bits/stdc++.h>
using namespace std;

bool firstGreater(string s1, string s2)
{
	for (int i = 0; i < s1.size(); i++)
	{
		if (s2[i] - '0' > s1[i] - '0')
		{
			return false;
		}
	}
	return true;
}

int main()
{
	//cout << char('0' + (('8' - '0') + 1));
	int test; cin >> test;
	for (int t = 1; t <= test; t++)
	{
		int n; cin >> n;
		vector<string> nums(150);
		for (int i = 0; i < n; i++)
		{
			string temp; cin >> temp;
			nums[i] = temp;
		}
		
		int adds = 0;
		for (int i = 1; i < n; i++)
		{
			string s1 = nums[i - 1];
			string s2 = nums[i];
			int diff = s1.size() - s2.size();
			if (s1.size() > s2.size() or s1 > s2)
			{
				//if same length
				if (diff == 0)
				{
					nums[i].push_back('0');
					adds++;
					continue;
				}

				// if prefix is greater
				string s3 = s2;
				for (int j = 0; j < diff; j++) s3.push_back('0');	
				if (s3 > s1)
				{
					nums[i] = s3;
					adds += diff;
					continue;
				}

				
				s3 = s2;
				for (int j = 0; j < diff; j++) s3.push_back('9');
				//if prefix is equal

				if (s3 > s1)	
				{
					nums[i] = s1;
					int place = nums[i].size() - 1;
					while (true)
					{
						if (nums[i][place] != '9')
						{
							nums[i][place] = char(nums[i][place] + 1);
							break;
						}
						nums[i][place] = '0';
						place--;
					}
					adds += s1.size() - s2.size();
				}
				//if need extra 0
				else
				{
					s3 = s2;
					for (int j = 0; j < diff+1; j++) s3.push_back('0');
					adds += diff + 1;
					nums[i] = s3;
				}

			}
			//if numbers are same
			else if (nums[i] == nums[i - 1])
			{
				//assert(nums[i] == nums[i - 1]);
				nums[i].push_back('0');
				adds++;
			}

		}

		cout << "Case #" << t << ": " << adds << "\n";
	}
	
}