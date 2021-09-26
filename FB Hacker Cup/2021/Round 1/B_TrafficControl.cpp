#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin;
    fin.open(R"(C:\Users\jmamt\OneDrive\Documents\Competitive Programming\FB Hacker Cup\2021\Round 1\traffic_control_input.txt)");
    ofstream fout;
    fout.open(R"(C:\Users\jmamt\OneDrive\Documents\Competitive Programming\FB Hacker Cup\2021\Round 1\B_Output.txt)");

    int tests; fin >> tests;
    for(int t = 1; t <= tests; t++) {
        int n; int m; int a; int b;
        fin >> n >> m >> a >> b;
        int top_left = a-(n+m-2);
        int top_right = b-(n+m-2);

        fout << "Case #" << t << ": ";
        if(top_left < 1 || top_right < 1) {
            fout << "Impossible" << "\n";
            continue;
        } else {
            fout << "Possible" << "\n";
        }

        fout << top_left << " ";
        for(int j = 0; j < m-2; j++) {
            fout << 1 << " ";
        }
        fout << top_right << "\n";

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < m-1; j++) {
                fout << 1 << " ";
            }
            fout << 1 << "\n";
        }
    }

}
