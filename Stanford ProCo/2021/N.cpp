#include<bits/stdc++.h>
using namespace std;

//funcs
#define mem(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for(int i=j ; i<k ; i+=in)
#define SORT(v) sort(v.begin(), v.end())
#define SORTBY(v, comp) sort(v.begin(), v.end(). comp)
#define mp make_pair
#define pb push_back
#define MAXN (int)1e9

//types
typedef pair<int, int> point;
typedef vector<int> vec;
typedef long long int ll;
typedef string str;

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vec seats;
	FOR(i, 0, n, 1)
	{
		int temp; cin >> temp;
		seats.push_back(temp);
	}
	//start second
	int second = 0;

		bool lastOdd = false;
		if (seats[0] % 2 == 1)
		{
			lastOdd = true;
		}

		for (int i = 1; i < n; i++)
		{
			if (lastOdd)
			{
				if (seats[i] % 2 == 1)
				{
					second++;
				}
			}
			else
			{
				if (seats[i] % 2 == 0)
				{
					second++;
				}
			}
			lastOdd = !lastOdd;
		}


	//start first
	int first = 0;

		seats[0]++;
		first++;
		lastOdd = false;
		if (seats[0] % 2 == 1)
		{
			lastOdd = true;
		}

		for (int i = 1; i < n; i++)
		{
			if (lastOdd)
			{
				if (seats[i] % 2 == 1)
				{
					first++;
				}
			}
			else
			{
				if (seats[i] % 2 == 0)
				{
					first++;
				}
			}
			lastOdd = !lastOdd;
		}


	cout << min(second, first) << "\n";
}