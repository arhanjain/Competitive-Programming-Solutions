#include <bits/stdc++.h>
using namespace std;

int a; int b;
map<int, int> segs = { {0,6},{1,2},{2,5},{3,5},{4,4},{5,5},{6,6},{7,3},{8,7},{9,6} };
vector<int> psum = {6};

int main()
{
	cin >> a >> b;
	for (int i = 1; i <= b; i++)
	{
		int sum = 0;
		string s = to_string(i);
		for (int j = 0; j < s.size(); j++)
		{
			sum += segs[s[j] - '0'];
		}
		psum.push_back(psum[i - 1] + sum);
	}

	cout << psum[b] - psum[a-1];
}