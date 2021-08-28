#include<bits/stdc++.h>
using namespace std;


int main()
{
	int test; cin >> test;
	for (int t = 1; t <= test; t++)
	{
		int n; int a; int b;
		cin >> n >> a >> b;
		if (a > b) swap(a, b);
		vector<int> metals(21);
		int num = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> metals[i];
			num+=metals[i]	;
		}

		for (int i = 1; i <= 400; i++)
		{
			vector<int> metals1(21);
			metals1[i] = 1;
			while ()
			{

			}
		}
	}
}