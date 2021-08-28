#include<bits/stdc++.h>
using namespace std;
int board[500][500] = {0};
bool checkLeft(int x, int y)
{
	if (x - 1 >= 0 and board[y][x - 1] == 0)
	{
		return true;
	}
	return false;
}

int main()
{
	int n; cin >> n;
	vector<int> perm(501);
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		perm[i] = temp;
	}
	
	
	for (int i = 0; i < n; i++)
	{
		int x = i; int y = i;
		for (int j = 0; j < perm[i]; j++)
		{
			board[y][x] = perm[i];
			if (checkLeft(x, y))
			{
				x--;
			}
			else
			{
				y++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}