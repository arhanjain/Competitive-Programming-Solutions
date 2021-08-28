#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> students(2*n);
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> students[i];
		}
		sort(students.begin(), students.end());
		
		cout << students[n ] - students[n-1] << "\n";

	}
}