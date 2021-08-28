#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> cubes;
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		cubes.push_back(temp);
	}
	
	for (int i = 0; i < n / 2; i+=2)
	{
		int temp = cubes[i];
		cubes[i] = cubes[n - 1 - i];
		cubes[n - 1 - i] = temp;
	}

	for (auto i : cubes)
	{
		cout << i << " ";
	}
}