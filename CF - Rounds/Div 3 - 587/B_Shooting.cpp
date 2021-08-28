#include<bits/stdc++.h>
using namespace std;

struct can {
	int d;
	int idx;
};

bool decr(can a, can b)
{
	return a.d > b.d;
}

int main()
{
	int n; cin >> n;
	vector<can> cans;
	for (int i = 0; i < n; i++)
	{
		can temp; cin >> temp.d;
		temp.idx = i + 1;
		cans.push_back(temp);
	}

	sort(cans.begin(), cans.end(), decr);

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += cans[i].d * i + 1;
	}

	cout << sum << "\n";
	for (can i : cans)
	{
		cout << i.idx << " ";
	}

}