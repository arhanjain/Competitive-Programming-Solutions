#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; int q; 
	cin >> n >> q;
	
	for (int i = 0; i < q; i++)
	{
		long long x; long long y;
		cin >> x >> y;
		
		long long n1 = (x - 1) * ceil(double(n) / 2) + ceil(double(y) / 2);
		
		if ((x + y) % 2)
		{
			n1 += ceil(pow(double(n), 2) / 2);
		}
		if (n % 2)
		{
			if (x % 2)//if x odd
			{
				if (y % 2)// y is odd
				{
					n1 = (x - 1) * ceil(double(n) / 2) + ceil(double(y) / 2) - (x/2);
				}
				else
				{
					n1 = (x - 1) * ceil(double(n) / 2) + ceil(double(y) / 2) - (x / 2) + ceil(pow(double(n), 2) / 2);
				}
			}
			else
			{
				if (y % 2)
				{
					n1 = (x - 1) * ceil(double(n) / 2) + ceil(double(y) / 2) - ceil(double(x) / 2) + ceil(pow(double(n), 2) / 2);

				}
				else
				{
					n1 = (x - 1) * ceil(double(n) / 2) + ceil(double(y) / 2) - ((x-1) / 2);
				}
			}
		}
		cout << n1 << "\n";
	}
}