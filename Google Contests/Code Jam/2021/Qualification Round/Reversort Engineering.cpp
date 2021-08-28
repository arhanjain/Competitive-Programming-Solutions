#include <bits/stdc++.h>
using namespace std;
vector<int> perms[6000];
int main()
{
	int test; cin >> test;
	for (int t = 1; t <= test; t++)
	{
		int n; int c;
		cin >> n >> c;
		
		vector<int> initial;
		//initial
		int factorial = 1;
		for (int i = 1; i <= n; i++)
		{
			initial.push_back(i);
			factorial = factorial * i;
		}
		//make permutations
		int idx = 0;
		do {
			perms[idx] = initial;
			idx++;
		} while (next_permutation(initial.begin(), initial.end()));

		int ans = -1;
		vector<int> ansV;
		for (int i = 0; i < factorial; i++)
		{
			int sum = 0;
			ansV = perms[i];
			for (int k = 1; k < n; k++)
			{
				int j = distance(perms[i].begin(), min_element(perms[i].begin() + k - 1, perms[i].end())) + 1;
				reverse(perms[i].begin() + k - 1, perms[i].begin() + j);
				sum += j - k + 1;
			}
			if (sum == c)
			{
				ans = i;
				break;
			}
		}
		cout << "Case #" << t << ": ";
		if (ans == -1)
		{
			cout << "IMPOSSIBLE" << "\n";
		}
		else
		{
			for (auto i : ansV)
			{
				cout << i << " ";
			}
			cout << "\n";
		}
	}
}