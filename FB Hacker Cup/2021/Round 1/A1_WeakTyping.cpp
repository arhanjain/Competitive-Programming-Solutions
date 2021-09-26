
#include<bits/stdc++.h>
using namespace std;

int main () {
    ifstream fin;
    fin.open("C:\\Users\\jmamt\\OneDrive\\Documents\\Competitive Programming\\FB Hacker Cup\\2021\\Round 1\\A1_Input.txt");
    ofstream fout;
    fout.open("C:\\Users\\jmamt\\OneDrive\\Documents\\Competitive Programming\\FB Hacker Cup\\2021\\Round 1\\A1_Output.txt");

    int tests; fin >> tests;
    for(int t = 1; t <= tests; t++) {
        int n; string w;
        fin >> n >> w;

        string newString;
        for(int i = 0; i < n; i++) {
            if (w[i] != 'F') {
                newString.push_back(w[i]);
            }
        }

        int count = 0;

        if(newString.size() >= 2) {
            for(int i = 0; i < newString.size()-1; i++) {
                if (newString[i] != newString[i + 1]) count++;
            }
        }

        fout << "Case #" << t << ": " << count << '\n';
    }
}
