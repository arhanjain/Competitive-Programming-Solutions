#include<bits/stdc++.h>
using namespace std;

int main () {
    int tests; cin >> tests;

    for(int t = 1; t<=tests; t++) {

        int lowestMoves = 1e9;
        set<vector<pair<int,int>>> moves;

        int n; cin >> n;
        int grid[100][100]; // empty = 0, X = 1, O = 2

        string s;
        for(int i = 0; i < n; i++) {
            cin >> s;
            for(int j = 0; j < n; j++) {
                if(s[j] == '.') grid[i][j] = 0;
                else if (s[j] == 'X') grid[i][j] = 1;
                else grid[i][j] = 2;
            }
        }

        //scan rows
        for(int i = 0; i < n; i++) {
            int emptyCount = 0;
            vector<pair<int,int>> moveSet;
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    emptyCount++;
                    moveSet.push_back({i,j});
                }
                else if(grid[i][j] == 2) {
                    emptyCount = 1e9;
                    break;
                }
            }
            if(emptyCount == lowestMoves) {
                moves.insert(moveSet);
            }
            else if(emptyCount < lowestMoves) {
                lowestMoves = emptyCount;
                moves = {moveSet};
            }
        }

        //scan columns
        for(int j = 0; j < n; j++) {
            int emptyCount = 0;
            vector<pair<int,int>> moveSet;
            for(int i = 0; i < n; i++) {
                if (grid[i][j] == 0) {
                    emptyCount++;
                    moveSet.push_back({i,j});
                }
                else if(grid[i][j] == 2) {
                    emptyCount = 1e9;
                    break;
                }
            }
            if(emptyCount == lowestMoves) {
                moves.insert(moveSet);
            }
            else if(emptyCount < lowestMoves) {
                lowestMoves = emptyCount;
                moves = {moveSet};
            }
        }

        //check for duplicates of only 1 move

        //print result
        if(lowestMoves == 1e9) cout << "Case #" << t << ": Impossible" << '\n';
        else cout << "Case #" << t << ": " << lowestMoves << " " << moves.size() << "\n";
    }
}