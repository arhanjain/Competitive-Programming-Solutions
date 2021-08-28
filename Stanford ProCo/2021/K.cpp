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
	int n; int k;
	cin >> n >> k;
	string s; cin >> s;
	vec marbles; // 0 = black 1 = white
	FOR(i, 0, s.size(), 1)
	{
		if (s[i] == 'W') marbles.push_back(1);
		else marbles.push_back(0);
	}
	
	vec removed;
	int whiteCount = 0;
	FOR(i, 0, marbles.size(), 1)
	{
		if (marbles[i]) whiteCount++;
		else
		{
			removed.pb(whiteCount);
		}
	}


	vec rev_removed;
	reverse(marbles.begin(), marbles.end());
	whiteCount = 0;
	FOR(i, 0, marbles.size(), 1)
	{
		if (marbles[i]) whiteCount++;
		else
		{
			rev_removed.pb(whiteCount);
		}
	}

	//reverse(rev_removed.begin(), rev_removed.end());
	int ans = 0;
	for (int i = 0; i <= k; i++)
	{
		ans = max(rev_removed[k - i] + removed[i], ans);
	}
	cout << ans;
}