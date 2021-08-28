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
typedef pair<int, int> pointu;
typedef vector<int> vec;
typedef long long int ll;
typedef string str;

int n;

struct point
{
	int x;
	int y;
};

float lengthCalc(point a, point b)
{
	return (float)sqrt(pow(abs(b.x - a.x), 2) + pow(abs(b.y - a.y), 2));
}

float calcAngle(point one, point two, point three)
{
	float a = lengthCalc(one, two);
	float b = lengthCalc(two, three);
	float c = lengthCalc(one, three);

	float frac = (pow(c, 2) - pow(a, 2) - pow(b, 2)) / (-2 * a * b);
	return acosf(frac);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;

	while (t--)
	{
		int n; cin >> n;
		vector<point> vertices1;
		vector<point> vertices2;
		for (int i = 0; i < n; i++)
		{
			point temp;
			cin >> temp.x >> temp.y;
			vertices1.push_back(temp);
		}
		for (int i = 0; i < n; i++)
		{
			point temp;
			cin >> temp.x >> temp.y;
			vertices2.push_back(temp);
		}

		vector<float> angles1;
		angles1.push_back(calcAngle(vertices1[vertices1.size() - 1], vertices1[0], vertices1[1]));
		for (int i = 1; i < vertices1.size() - 1; i++)
		{
			angles1.push_back(calcAngle(vertices1[i - 1], vertices1[i], vertices1[i + 1]));
		}
		angles1.push_back(calcAngle(vertices1[vertices1.size() - 2], vertices1[vertices1.size() - 1], vertices1[0]));

		vector<float> angles2;
		angles2.push_back(calcAngle(vertices2[vertices2.size() - 1], vertices2[0], vertices2[1]));
		for (int i = 1; i < vertices2.size() - 1; i++)
		{
			angles2.push_back(calcAngle(vertices2[i - 1], vertices2[i], vertices2[i + 1]));
		}
		angles2.push_back(calcAngle(vertices2[vertices2.size() - 2], vertices2[vertices2.size() - 1], vertices2[0]));
		
		//SORT(angles1);
		//SORT(angles2);

		int idx2 = -1;
		for (int i = 0; i < angles1.size(); i++)
		{
			if (angles1[0] == angles2[i])
			{
				idx2 = i;
				break;
			}
		}

		bool done = false;
		for (int i = 0; i < angles1.size(); i++)
		{
			int hehe = i + idx2;
			if (hehe > angles1.size() - 1) hehe = hehe % (angles1.size());
			if (angles1[i] - angles2[hehe] > 1e-3)
			{
				cout << "NO" << '\n';
				done = true;
				break;
			}
		}
		float slope1 = (vertices1[1].y - vertices1[0].y) / float(vertices1[1].x - vertices1[0].x);
		float slope2 = (vertices2[1 + idx2].y - vertices2[idx2].y) / float(vertices2[1+idx2].x - vertices2[idx2].x);
		if (slope1 != slope2 and !done)
		{
			cout << "NO" << '\n';
			done = true;
		}
		if(!done) cout << "YES" << '\n';
	}

}