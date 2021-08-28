#include<bits/stdc++.h>
using namespace std;

//funcs
#define mem(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for(int i=j ; i<k ; i+=in)
#define SORT(v) sort(v.begin(), v.end())
#define SORTBY(v, comp) sort(v.begin(), v.end(), comp)
#define mp make_pair
#define pb push_back
#define MAXN (int)1e9

//types
typedef pair<int, int> point;
typedef vector<int> vec;
typedef long long int ll;
typedef string str;

bool decr(point a, point b)
{
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int test; cin >> test;
	FOR(t, 1, test + 1, 1)
	{
		int n; int k;
		cin >> n >> k;
		vector<int> tix;
		for (int i = 0; i < n; i++)
		{
			int temp; cin >> temp;
			tix.pb(temp);
		}
		SORT(tix);
		vector<point> diffs;
		for (int i = 1; i < n; i++)
		{
			diffs.pb({ tix[i] - tix[i - 1] - 1,0 });
		}
		diffs.push_back({ tix[0] - 1,1 });
		diffs.push_back({ k - tix[n - 1]-0,1 });

		sort(diffs.begin(), diffs.end(), decr);

		int nums = 0;

		if (diffs[0].first >= 2 and diffs[0].second == 0)
		{
			diffs[0].first = int(ceil(diffs[0].first / 2.0));
		}
		if (diffs[1].first >= 2 and diffs[1].second == 0)
		{
			diffs[1].first = int(ceil(diffs[1].first / 2.0));
		}
		
		nums += diffs[0].first + diffs[1].first;
		float ans = float(nums) / k;

		cout << "Case #" << t << ": " << ans << "\n";
	}
}