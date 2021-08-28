#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	string s; cin >> s;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		s[i] = s[i - arr[i]];
	}
	cout << s;
}