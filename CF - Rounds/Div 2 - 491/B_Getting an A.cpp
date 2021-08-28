#include<bits/stdc++.h>
using namespace std;

int n;
int sum;
vector<int> grades;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		grades.push_back(temp);
		sum += temp;
	}
	
	sort(grades.begin(), grades.end());
	//reverse(grades.begin(), grades.end());

	float diff = ((4.5) * n) - sum;

	int sum2 = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum2 >= diff) break;
		sum2 += 5 - grades[i];
		ans++;
	}

	cout << ans;
}