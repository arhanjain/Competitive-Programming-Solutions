#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test; cin >> test;
	for (int t = 1; t <= test; t++)
	{
		int m; cin >> m;
		long long cards[500] = { 0 };
		long long sum = 0;
		for (int i = 0; i < m; i++)
		{
			long long p; long long n; cin >> p >> n;
			cards[p] = n;
			sum += p * n;
		}
		
		//go from sum to 1
		// prime factorize, if all numbers are less than amount of cards,
		// then check if theres a combination of cards that add up to i
		//return largest number

		for (long long i = sum; i >= 0; i--)
		{
			if (i == 0)
			{
				cout << "Case #" << t << ": " << 0 << "\n";
				break;
			}
			//prime factorize
			int prime[500] = { 0 };
			int num = i;
			while(num % 2 == 0)
			{
				prime[2]++;
				num /= 2;
			}

			for (int j = 3; j <= sqrt(num); j += 2)
			{
				while (num % j == 0)
				{
					prime[j]++;
					num /= j; 
				}
			}
			if (num > 499) continue;
			if (num > 2) prime[num]++;

			int next = 0;
			for (int j = 0; j < 500; j++)
			{
				if (prime[j] > cards[j])
				{
					next = 1;
					break;
				}
				prime[j] = cards[j] - prime[j]; // how many number left to work with
			}
			if (next) continue;
			int sum = 0;
			for (int j = 0; j < 500; j++)
			{
				sum += j * prime[j];
			}
			
			if (sum == i)
			{
				cout << "Case #" << t << ": " << i << "\n";
				break;
			}
		}	
	}
}