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

struct Move
{
	int x1;
	int y1;
	int x2;
	int y2;
};

vec grid[11][11];
int alicePoints = 0;
int bobPoints = 0;
string ans1;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; int m; int x; int y; int a; int b; int c; int d;
	cin >> n >> m >> x >> y >> a >> b >> c >> d;

	int apps = a - n;
	int bones = b - m;
	
	int mins = 0;
	
	n += mins * x;
	m += mins * y;


	if (apps * x < bones * y)
	{
		mins += apps * x;
		mins += min(int(ceil(bones /float(d))) * (x * c), bones * y);
	}
	else
	{
		mins += bones * y;
		mins += min(int(ceil((apps / float(c)))) * (y * d), apps * x);
	}
	cout << mins;
}