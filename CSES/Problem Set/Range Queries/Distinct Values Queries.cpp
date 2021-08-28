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
	int n; int q; cin >> n >> q;	
	vec nums;

	FOR(i, 0, n, 1)
	{
		int temp; cin >> temp;
		nums.pb(temp);
	}

}