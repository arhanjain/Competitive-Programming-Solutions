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
	int s; int n; cin >> s >> n;
	vec lates;
	FOR (i, 0, n, 1)
	{
		int temp; cin >> temp;
		lates.push_back(temp);
	}
	SORT(lates);

	//individual counts
	map<int, int> pushups;
	FOR(i, 0, n, 1)
	{
		if (pushups.find(lates[i]) == pushups.end())
		{
			pushups.insert({ lates[i], 1 });
		}
		else
		{
			pushups[lates[i]]++;
		}
	}

	//set of players
	set<int> unique(lates.begin(), lates.end());
	//make the psum
	FOR(i, 1, unique.size(), 1)
	{
		pushups[*next(unique.begin(), i)] += pushups[*next(unique.begin(), i - 1)];
	}

	//switch
	map<int, int> switched;
	vec ups;
	FOR(i, 0, unique.size(), 1)
	{
		switched[pushups[*next(unique.begin(), i)]] = *next(unique.begin(), i);
		ups.push_back(pushups[*next(unique.begin(), i)]);
	}
	SORT(ups);

	int q; cin >> q;
	FOR(i, 0, q, 1)
	{
		int x; cin >> x;
		if (x < ups[0])
		{
			cout << 0 << "\n";
			continue;
		}
		vector<int>::iterator idx = lower_bound(ups.begin(), ups.end(), x);
		//int num = *next(ups.begin(), distance(ups.begin(),idx) - 1);
		
		if (*idx > x)
		{
			idx = next(ups.begin(), distance(ups.begin(), idx) - 1);
		}
		cout << switched[*idx]  << "\n";
	}
}