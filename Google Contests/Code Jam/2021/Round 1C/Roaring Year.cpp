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


vector<ll> pog(string y)
{
	vector<ll> hehe;
	for (int i = 1; i < y.size(); i++)
	{
		vector<string> splits;
		int idx = 0;
		while (idx + i <= y.size())
		{
			splits.push_back(y.substr(idx, i));
			idx += i;
		}

		int away = 0;
		for (int j = 1; j < splits.size(); j++)
		{
			if (stoll(splits[j]) - stoll(splits[j - 1]) > 1)
			{
				away = j;
				break;
			}
			if (stoll(splits[j]) - stoll(splits[j - 1]) < 1)
			{
				away = -j;
				break;
			}
		}
		if (splits.size() < 2) break;
		string boop = "";
		if (away >= 0)
		{
			long long start = stoll(splits[0]) + 1;
			while (boop.size() < y.size())
			{
				boop.append(to_string(start));
				start++;
			}
		}
		else
		{
			long long start = stoll(splits[0]);
			while (boop.size() < y.size())
			{
				boop.append(to_string(start));
				start++;
			}
		}

		if (stoll(boop) < stoll(y))
		{
			long long start = stoll(splits[0]) + 1;
			boop = "";
			while (boop.size() < y.size())
			{
				boop.append(to_string(start));
				start++;
			}
		}
		hehe.push_back(stoll(boop));
	}
	return hehe;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int test; cin >> test;
	FOR(t, 1, test + 1, 1)
	{
		string y; cin >> y;
		if (stoll(y) < 10) y = "10";
		vector<long long> ans;
		vector<ll> te = pog(y);
		ans.insert(ans.end(), te.begin(), te.end());
		if (y[0] == '9') y = to_string(ll(pow(10,int(log10(stoll(y)))  + 1)));
		te = pog(y);
		ans.insert(ans.end(), te.begin(), te.end());
		y = to_string(stoll(y) + 1);
		te = pog(y);
		ans.insert(ans.end(), te.begin(), te.end());
		if (y[0] == '9') y = to_string(ll(pow(10, int(log10(stoll(y))) + 1)));
		te = pog(y);
		ans.insert(ans.end(), te.begin(), te.end());

		long long smol = ans[0];
		for (auto i : ans)
		{
			if (i < smol) smol = i;
		}

		cout << "Case #" << t << ": " << smol << "\n";
	}
}