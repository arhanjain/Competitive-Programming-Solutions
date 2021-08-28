#include <bits/stdc++.h>
using namespace std;

vector<int> answer;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;

	while (t--) 
	{
		int tempAns = 0;
		int n; cin >> n;
		vector<int> heroes;
		while (n--)
		{
			int temp; cin >> temp;
			heroes.push_back(temp);
		}

		int min = *min_element(heroes.begin(), heroes.end());

		for (auto element : heroes)
		{
			if (element != min) tempAns++;
		}

		answer.push_back(tempAns);
	}

	for (auto element : answer)
	{
		cout << element << "\n";
	}
}