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

struct car {
    int pos;
    int emptyAbove;
    int emptyBelow;
};


int main()
{
    ifstream fin;
    fin.open(R"(C:\Users\jmamt\OneDrive\Documents\Competitive Programming\FB Hacker Cup\2021\Round 2\valet_parking_chapter_1_sample_input.txt)");
    ofstream fout;
    fout.open(R"(C:\Users\jmamt\OneDrive\Documents\Competitive Programming\FB Hacker Cup\2021\Round 2\valet_parking_chapter_1_sample_output.txt)");

    int tests; fin >> tests;
    for(int t = 1; t <= tests; t++) {
        int r; int c; int k; fin >> r >> c >> k;
        vector<vector<char>> grid;
        for(int i = 0; i < r; i++) {
            vector<char> tempy;
            for(int j = 0; j < c; j++) {
                char temp; fin >> temp;
                tempy.push_back(temp);
            }
            grid.push_back(tempy);
        }

        vector<car> carsLeft;
        for(int j = 0; j < c; j++) {
            if(grid[k-1][j] == 'X') {
                int emptyAbove=0; int emptyBelow=0;
                for(int i = 0; i < k-1; i++) {
                    if(grid[i][j] == '.') emptyAbove++;
                }
                for (int i = k; i < r; i++) {
                    if(grid[i][j] == '.') emptyBelow++;
                }
                car temp; temp.pos = j; temp.emptyAbove = emptyAbove; temp.emptyBelow = emptyBelow;
                carsLeft.push_back(temp);
            }
        }
        int moveDown = 0;
        int moveUp = 0;
        int remove = 0;
        for(car x : carsLeft) {
            if(x.emptyAbove > 0) moveUp++;
            if(x.emptyBelow > 0) moveDown++;
        }
        int moves;
        if(moveUp>moveDown and moveUp > 0) {
            moves = 1 + carsLeft.size() - moveUp;
        } else if (moveDown>moveUp and moveDown > 0){
            moves = 1 + carsLeft.size() - moveDown;
        } else {
            moves = carsLeft.size();
        }

        fout << "Case #" << t << ": " << moves << "\n";
    }

}