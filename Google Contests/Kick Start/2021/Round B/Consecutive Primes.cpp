#include <bits/stdc++.h>
using namespace std;
vector<long long> primes;
void sieve(long long lim)
{
	vector<int> isPrime(lim, 1);
	for (long long i = 2; i * i < lim; i++)
	{
		if (isPrime[i])
		{
			for (long long j = i * i; j < lim; j += i)
			{
				isPrime[j] = 0;
			}
		}
	}
	for (long long i = 2; i < lim; i++)
	{
		if (isPrime[i])
		{
			primes.push_back(i);
		}
	}
}
void segSieve(long long num)
{
	long long lim = floor(sqrt(num)) + 1;
	sieve(lim);
	long long low = lim;
	long long high = lim + lim;
	while (low < num)
	{
		if (high > num)
		{
			high = num;
		}

		vector<long long> isPrime(lim + 1, 1);
		for (long long i = 0; i < primes.size(); i++)
		{
			long long lower = (low / primes[i]) * primes[i];
			if (lower < low) lower += primes[i];

			for (long long j = lower; j < high; j += primes[i])
			{
				isPrime[j - low] - 0;
			}
		}
		for (long long i = 0; i < high - low; i++)
		{
			if (isPrime[i])
			{
				primes.push_back(i + low);
			}
		}

		low += lim;
		high += lim;
	}
}

int main()
{
	int test; cin >> test;
	segSieve(100000);
	for (int t = 1; t <= test; t++)
	{
		long long z; cin >> z;
		
		long long ans = -1;
		int L = 0; int R = primes.size()-1;

		while (L != R)
		{
			int mid = (L + R +1) / 2;
			long long calc = primes[mid] * primes[mid + 1];
			if (calc > z)
			{
				R = mid-1;
			}
			if (calc <= z)
			{
				L = mid;
			}
		}
		cout << "Case #" << t << ": " << primes[L]*primes[L+1] << "\n";
	}
}