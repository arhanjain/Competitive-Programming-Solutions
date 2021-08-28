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
	string s; 

	string temp;
	getline(cin, s ,'\r');

	vec spaces;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ' and i!= s.size()-1) spaces.push_back(i);
	}

	vec idxes;
	for (int i = 0; i < s.size(); i++)
	{
		//int save = i;
		if (isupper(s[i]))
		{
			while (s[i] != ' ')
			{
				if (i == s.size())
				{
					//idxes.push_back(i - 1);
					break;
				}
				i++;
			}
		idxes.push_back(i-1);
		}
		
	}
	bool thonk = false;
	if (spaces.size() > 0)
	{
		if (isupper(s[spaces[spaces.size() - 1] + 1]))
		{
			thonk = true;
		}
	}
	else
	{
		if (isupper(s[0])) thonk = true;
	}
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	transform(s.begin(), s.end(), s.begin(), ::tolower);

	for (int i = 0; i < spaces.size(); i++)
	{
		s.insert(spaces[i], " ");
	}

	
	for (int i = 0; i < idxes.size(); i++)
	{
		char e = s[idxes[i]];
		e = toupper(e);
		s[idxes[i]] = e;
	}
	
	
		
	reverse(s.begin(), s.end());

	if (thonk)
	{
		char hm = s[0];
		hm = toupper(hm);
		s[0] = hm;
	}

	
	cout << s;
	
}