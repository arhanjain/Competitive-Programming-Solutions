#include<bits/stdc++.h>
using namespace std;

vector<int> adjMat[500001];
vector<int> answers;
int n, m;

vector<int> visited(500001);

int dfs(int person)
{
	int pplReached = 1;
	visited[person] = answers.size();
	for (int u = 0; u < adjMat[person].size(); u++)
	{
		if (visited[adjMat[person][u]] == 0)
		{
			pplReached += dfs(adjMat[person][u]);
		}
	}
	return pplReached;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		
		vector<int> groups;
		int temp;
		for (int j = 0; j < k; j++)
		{
			cin >> temp;
			groups.push_back(temp);
		}

		for (int j = 0; j < k - 1; j++)
		{
			adjMat[groups[j]].push_back(groups[j + 1]);
			adjMat[groups[j + 1]].push_back(groups[j]);
		}
	}
	fill(visited.begin(), visited.end(), 0);
	visited[1] = 0;

	for (int i = 1; i <= n; i++)
	{
		
		if (visited[i] == 0)
		{
			answers.push_back(0);
			answers[answers.size()-1] = dfs(i);
		}		
	}

	for (int i = 1; i <= n ; i++)
	{
		cout << answers[visited[i]-1] << " ";
	}

}