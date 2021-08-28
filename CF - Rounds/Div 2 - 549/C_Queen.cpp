#include<bits/stdc++.h>
using namespace std;

int input[100001][2];
vector<int> adjMat[100001];
vector<int> del;


void dfs(int vertex)
{
	if (input[vertex][1] == 1)
	{
		bool nonRespect = true;
		for (int i = 0; i < adjMat[vertex].size(); i++)
		{
			if (input[adjMat[vertex][i]][1] == 0)
			{
				nonRespect = false;
			}
		}
		if (nonRespect)
		{
			del.push_back(vertex);
			
		}
		for (int i = 0; i < adjMat[vertex].size(); i++)
		{
			dfs(adjMat[vertex][i]);
		}
	}
	else
	{
		for (int i = 0; i < adjMat[vertex].size(); i++)
		{
			dfs(adjMat[vertex][i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> input[i][0] >> input[i][1];
	}

	for (int i = 1; i <= n; i++)
	{
		if (input[i][0] == -1)
		{
			adjMat[0].push_back(i);
		}
		else
		{
			adjMat[input[i][0]].push_back(i);
		}
	}
	for (int i = 0; i < adjMat[adjMat[0][0]].size(); i++)
	{
		dfs(adjMat[adjMat[0][0]][i]);
	}

	if (del.size() < 1)
	{
		cout << -1;
		return 0;
	}

	sort(del.begin(), del.end());
	for (auto pog : del)
	{
		cout << pog << " ";
	}

}