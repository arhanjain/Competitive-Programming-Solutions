#include<bits/stdc++.h>
using namespace std;

int t = 0;
vector<string> answers;
int main()
{
	cin >> t;
	int n = 0;
	string b;	
	string a;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> b;
		a = a + "1";
		for (int j = 1; j < n; j++)
		{
			if ((a[j - 1] == '1' && b[j - 1] == '1') and (b[j] == '1')) // if last is 1,1 and b[j] is 1
			{
				a = a + '0';
			}
			else if ((a[j - 1] == '1' && b[j - 1] == '1') and (b[j] == '0')) // if last is 1,1 and b[j] is 0
			{
				a = a + "1";
			}
			else if ((a[j - 1] == '0' && b[j - 1] == '1') and (b[j] == '1')) // if last is 0,1 and b[j] is 1
			{
				a = a + "1";
			}
			else if ((a[j - 1] == '0' && b[j - 1] == '1') and (b[j] == '0')) // if last is 0,1 and b[j] is 0
			{
				a = a + '0';
			}
			else if ((a[j - 1] == '1' && b[j - 1] == '0') and (b[j] == '1')) // if last is 1,0 and b[j] is 1
			{
				a = a + "1";
			}
			else if ((a[j - 1] == '1' && b[j - 1] == '0') and (b[j] == '0')) // if last is 1,0 and b[j] is 0
			{
				a = a + '0';
			}
			else if ((a[j - 1] == '0' && b[j - 1] == '0')) // if last is 0,0 it doesnt matter what b[j] is
			{
				a = a + "1";
			}
		}
		answers.push_back(a);
		a = "";

	}

	for (int i = 0; i < answers.size(); i++) {
		cout << answers[i] << "\n";
	}
}
