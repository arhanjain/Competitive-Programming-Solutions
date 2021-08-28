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


void editGrid(Move delta)
{
	int x1 = delta.x1;
	int x2 = delta.x2;
	int y1 = delta.y1;
	int y2 = delta.y2;

	if (delta.x1 == delta.x2)
	{
		grid[x1 - 2][y1-1]++;
		grid[x1-1][y1-1]++;
	}

	if (delta.y1 == delta.y2)
	{
		grid[x1 - 1][y1 - 2]++;
		grid[x1 - 1][y1 - 1]++;
	}
}

bool checkBoxMade(Move delta, char turn)
{
	int x1 = delta.x1;
	int x2 = delta.x2;
	int y1 = delta.y1;
	int y2 = delta.y2;
	bool keepTurn = false;
	if (delta.x1 == delta.x2)
	{
		if (grid[x1 - 2][y1 - 1] == 4)
		{
			keepTurn = true;
			if (turn == 'A')
			{
				alicePoints++;
			}
			else
			{
				bobPoints++;
			}
		}
		if (grid[x1 - 1][y1 - 1] == 4)
		{
			keepTurn = true;
			if (turn == 'A')
			{
				alicePoints++;
			}
			else
			{
				bobPoints++;
			}
		}
	}

	if (delta.y1 == delta.y2)
	{
		if (grid[x1 - 1][y1 - 2] == 4)
		{
			keepTurn = true;
			if (turn == 'A')
			{
				alicePoints++;
			}
			else
			{
				bobPoints++;
			}
		}
		if (grid[x1 - 1][y1 - 1] == 4)
		{
			keepTurn = true;
			if (turn == 'A')
			{
				alicePoints++;
			}
			else
			{
				bobPoints++;
			}
		}
	}
	return keepTurn;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	ans1.push_back('A');

	vector<Move> moves;

	FOR(i, 0, n, 1)
	{
		Move temp;
		cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2;
		moves.push_back(temp);
	}

	char turn = 'B';
	for (int i = 0; i < moves.size(); i++)
	{
		editGrid(moves[i]);
		bool keepTurn == checkBoxMade(moves[i], turn);
		
		ans1.push_back(turn);
		if (!keepTurn)
		{
			if (turn == 'B') turn = 'A';
			else turn = 'B';
		}
	}

	cout << ans1 << "\n" << alicePoints << " " << bobPoints;
}