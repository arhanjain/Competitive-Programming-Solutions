#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test; cin >> test;
	for(int t = 1; t <= test; t++)
	{
		long long a; long long b; long long c;
		cin >> a >> b >> c;
		//long long d = (c * 60) / 10000000000;
		long long hour; long long minute; long long second;
		vector<long long> hands = { a,b,c };
		bool br = false;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j == i) continue;
				long long hr = (120*(hands[i] / (30*120000000000)))%12;
				long long min = (hands[j] / 10000000000) %360;
				long long sec = (hands[3 - i - j] * 60) / 10000000000;
				if (min == hr and min == sec)
				{
					hour = hands[i]/120000000000;
					minute = hands[j]/10000000000;
					second = (hands[3 - i - j]*60)/10000000000;
					cout << "Case #" << t << ": " << hour % 12 << " " << minute % 60 << " " << second << " " << 0 << "\n";
					br = true;
					break;
				}
			}
			if (br) break;
		}

		printf("pog");
		//cout << "Case #" << t << ": " << a << " " << b << " " << c << " " << d << "\n";
	}
}