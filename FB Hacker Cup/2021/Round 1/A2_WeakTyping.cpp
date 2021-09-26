#include <bits/stdc++.h>
using namespace std;

int handSwitches(string w) {
    string newString;
    for(int i = 0; i < w.size(); i++) {
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
    return count;
}

int main() {
    ifstream fin;
    fin.open(R"(C:\Users\jmamt\OneDrive\Documents\Competitive Programming\FB Hacker Cup\2021\Round 1\A2_Validation_Input.txt)");
    ofstream fout;
    fout.open(R"(C:\Users\jmamt\OneDrive\Documents\Competitive Programming\FB Hacker Cup\2021\Round 1\A2_Validation_Output.txt)");

    int tests; fin >> tests;
    for(int t = 1; t <= tests; t++) {
        int n; string s; fin >> n >> s;

        long long count = 0;

        for(int i = 2; i <= n; i++) {
            for(int j = 0; j <= n-i; j++) {
                count += handSwitches(s.substr(j,i));
            }
        }

        fout << "Case #" << t << ": " << count << "\n";
    }
}