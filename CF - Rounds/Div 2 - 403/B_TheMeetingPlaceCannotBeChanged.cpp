#include<bits/stdc++.h>
using namespace std;

int n;

struct fren {
	double pos;
	double vel;
};

vector<fren> frens;

bool sortfren(fren a, fren b)
{
	return a.pos < b.pos;
}

pair<double, double> intervalReachable(double time)
{
	vector<double> maxPos;
	vector<double> minPos;
	for (int i = 0; i < n; i++)
	{
		//dist = x + vt / x - vt
		maxPos.push_back(frens[i].pos + frens[i].vel * time);
		minPos.push_back(frens[i].pos - frens[i].vel * time);
	}

	pair<double, double> interval;
	interval.first = *min_element(maxPos.begin(), maxPos.end());
	interval.second = *max_element(minPos.begin(), minPos.end());

	return interval;
}

int main()
{
	cout.precision(10);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		fren temp;
		cin >> temp.pos;
		frens.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> frens[i].vel;
	}

	sort(frens.begin(), frens.end(), sortfren);

	double L = 0.0; double R = 1000000000.0;
	double dist = 0;
	while ((R - L) > 1e-6)
	{
		double mid = L + (R - L) / 2;
		pair<double, double> interval = intervalReachable(mid);

		if (abs(interval.first - interval.second) < 1000)
		{
			dist = mid;
		}
		if (interval.first > interval.second)
		{
			R = mid;
		}
		else
		{
			L = mid;
		}
	}
	cout << dist;
}