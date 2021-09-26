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

struct space {
    int pos;
    int emptyAbove;
    int emptyBelow;
};


int main()
{
    ifstream fin;
    fin.open(R"(C:\Users\jmamt\OneDrive\Documents\Competitive Programming\FB Hacker Cup\2021\Round 2\valet_parking_chapter_1_validation_input.txt)");
    ofstream fout;
    fout.open(R"(C:\Users\jmamt\OneDrive\Documents\Competitive Programming\FB Hacker Cup\2021\Round 2\valet_parking_chapter_1_validation_output.txt)");

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

        vector<space> spaces;
        for(int j = 0; j < c; j++) {
            int emptyAbove=0; int emptyBelow=0;
            for(int i = 0; i < k-1; i++) {
                if(grid[i][j] == '.') emptyAbove++;
            }
            for (int i = k; i < r; i++) {
                if(grid[i][j] == '.') emptyBelow++;
            }
            space temp; temp.pos = j; temp.emptyAbove = emptyAbove; temp.emptyBelow = emptyBelow;
            spaces.push_back(temp);

        }

        int possibleUps = 0;
        int possibleDowns = 0;
        for(space x : spaces) {
            if(x.emptyAbove > possibleUps) possibleUps = x.emptyAbove;
            if(x.emptyBelow > possibleDowns) possibleDowns = x.emptyBelow;
        }

        vector<vector<int>> emptyAbove;
        vector<vector<int>> emptyBelow;

        for(int i = 0; i < r; i++) {
            vector<int> temp;
            for(int j = 0; j < c; j++) {
                temp.push_back(0);
            }
            emptyAbove.push_back(temp);
            emptyBelow.push_back(temp);
        }

        for(int j = 0; j < c; j++) {
            int empty = 0;
            for(int i = 0; i < r; i++) {
                emptyAbove[i][j] = empty;
                if(grid[i][j] == '.') empty++;
            }
        }
        for(int j = 0; j < c; j++) {
            int empty = 0;
            for(int i = r-1; i >= 0; i--) {
                emptyBelow[i][j] = empty;
                if(grid[i][j] == '.') empty++;

            }
        }

        vec upMoves;
        vec downMoves;

        for(int i = 0; i <= possibleUps; i++) {
            vector<char> kRow = grid[k-1];
            for(int j = 0; j < c; j++) {
                int newRow = k-1+i;
                if(newRow > r-1) {

                    if(emptyAbove[r-1][j] >= i) {
                        kRow[j] = '.';
                    } else if(grid[r-1][j] == '.') {
                        kRow[j] = '.';
                    } else {
                        kRow[i] = 'X';
                    }
                } else {
                    if(i <= emptyAbove[newRow][j]) {
                        kRow[j] = grid[newRow][j];
                    } else {
                        kRow[j] = grid[newRow-(i-emptyAbove[newRow][j])][j];
                    }
                }
            }
            int carsLeft = 0;
            for(int j = 0; j < c; j++) {
                if(kRow[j] == 'X') carsLeft++;
            }

            upMoves.push_back(carsLeft+i);
        }

        for(int i = 0; i <= possibleDowns; i++) {
            vector<char> kRow = grid[k-1];
            for(int j = 0; j < c; j++) {
                int newRow = k-1-i;
                if(newRow < 0) {
                    if(emptyBelow[0][j] >= i) {
                        kRow[j] = '.';
                    } else if(grid[0][j] == '.') {
                        kRow[j] = '.';
                    } else {
                        kRow[i] = 'X';
                    }
                } else {
                    if(i <= emptyBelow[newRow][j]) {
                        kRow[j] = grid[newRow][j];
                    } else {
                        kRow[j] = grid[newRow+(i-emptyBelow[newRow][j])][j];
                    }
                }
            }
            int carsLeft = 0;
            for(int j = 0; j < c; j++) {
                if(kRow[j] == 'X') carsLeft++;
            }

            downMoves.push_back(carsLeft+i);
        }

        int smallestUp = *min_element(upMoves.begin(), upMoves.end());
        int smallestDown = *min_element(downMoves.begin(), downMoves.end());

        fout << "Case #" << t << ": " << min(smallestDown, smallestUp) << "\n";
    }

}