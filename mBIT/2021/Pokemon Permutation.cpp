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
	string s; getline(std::cin, s, '\r');
	
	vector<int> letters(26);

	for (int i = 0; i < s.size(); i++)
	{
		letters[int(s[i]) - 97]++;
	}

	int min = 1e6;
	vec usable;
	for (int i = 0; i < letters.size(); i++)
	{
		if (letters[i] < min and letters[i]> 0) min = letters[i];
		if (letters[i] > 0) usable.push_back(letters[i]);
	}
	
	bool canDo = true;
	for (int i = 0; i < usable.size(); i++)
	{
		if (usable[i] % min != 0)
		{
			canDo = false;
			break;
		}
	}
	if (min < 2) canDo = false;
	string ans;
	if (canDo)
	{
		ans = "";
		for (int i = 0; i < letters.size(); i++)
		{
			if (letters[i] > 0)
			{
				for (int j = 0; j < letters[i] / min; j++)
				{
					ans.push_back(char(i + 97));
				}
			}
		}
	}
	else
	{
		 ans = "IMPOSSIBLE";
		 cout << ans;
		 //return 0;
	}

	for (int i = 0; i < letters.size(); i++)
	{
		cout << " " << letters[i];
	}
	

}