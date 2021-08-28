#include<bits/stdc++.h>
using namespace std;


int main()
{
	vector<char> vow = { 'a','e','i','o','u' };
	int k; cin >> k;
	if (k < 25)
	{
		cout << -1;
		return 0;
	}
	int num1 = -1;
	int num2 = -1;
	for (int i = 5; i * i <= k; i++)
	{
		if (k % i == 0)
		{
			num1 = i;
			num2 =k/i;
		}
	}
	string ans;
	if (num1 >= 5 and num2 >= 5)
	{
		string first;
		for (int i = 0; i < num1; i++)
		{
			first.push_back(vow[i % 5]);
		}
		int x = 0;
		do {
			if (x == num2) break;
			x++;
			ans.append(first);
			first = first.substr(1, first.size() - 1) + first[0];
			
		} while (true);
		x = ans.size();
		cout << ans;
	}
	else
	{
		cout << -1;
	}
}