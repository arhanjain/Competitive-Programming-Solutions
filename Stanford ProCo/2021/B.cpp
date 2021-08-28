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

int grid[11][11];

int alicePoints = 0;
int bobPoints = 0;
string ans1;


void editGrid(Move delta)
{
	int x11 = delta.x1;
	int x22 = delta.x2;
	int y11 = delta.y1;
	int y22 = delta.y2;

	if (delta.x1 == delta.x2)
	{
		if(x11-2>=0)grid[x11 - 2][y11 - 1]++;
		grid[x11 - 1][y11 - 1]++;
	}

	else if (delta.y1 == delta.y2)
	{
		if (y11 -2 >=0)grid[x11 - 1][y11 - 2]++;
		grid[x11 - 1][y11 - 1]++;
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
		if (grid[x1 - 1][y1 - 1] == 4 and x1 - 1 < n - 1)
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
	
	 if (grid[x1 - 1][y1 - 1] == 4 and y1-1 <n-1)
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
	cin >> n;
	int m = n;
	n = 2 * int(pow(n, 2) )- 2 * n;
	//ans1.push_back('A');
	
	vector<Move> moves;

	FOR(i, 0, n, 1)
	{
		Move temp;
		cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2;
		moves.push_back(temp);
	}

	char turn = 'A';
	for (int i = 0; i < moves.size(); i++)
	{
		editGrid(moves[i]);
		bool keepTurn = checkBoxMade(moves[i], turn);

		ans1.push_back(turn);
		if (!keepTurn)
		{
			if (turn == 'B') turn = 'A';
			else turn = 'B';
		}
	}
	//alicePoints--;
	//bobPoints += int(pow(m - 1, 2)) - alicePoints - bobPoints;
	cout << ans1 << "\n" << alicePoints << " " << bobPoints;
}