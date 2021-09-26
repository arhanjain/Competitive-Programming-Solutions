#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> vowelIndexes = {0,4,8,14,20};

int main() {
    //cout << "sus";
    vector<char> letters = {'A','B','C','D','E','F','G','H',
                            'I','J','K','L','M','N','O','P',
                            'Q','R','S','T','U','V','W','X',
                            'Y','Z'};

    int tests; cin >> tests;
    for(int t = 1; t <= tests; t++) {
        int lowestTime = 1e9;
        vector<int> vowels;
        int vowelCount = 0;
        vector<int> consonants;
        int consonantCount = 0;
        set<char> usedChars;

        string s; cin >> s;

        for(char i : letters) {
            int count = 0;
            for(char j : s) if(j==i) count++;

            if((i=='A' or i=='E' or i=='I' or i=='O' or i=='U') and count >0) {
                vowels.push_back(count);
                vowelCount+=count;
            } else if(count > 0) {
                consonants.push_back(count);
                consonantCount+=count;
            }
        }

        for(int count : vowels) {
            int changed = consonantCount+2*(vowelCount-count);
            if(changed<lowestTime) lowestTime=changed;
        }

        for(int count : consonants) {
            int changed = vowelCount+2*(consonantCount-count);
            if(changed<lowestTime) lowestTime=changed;
        }

        if(vowelCount == 0) if(consonantCount < lowestTime) lowestTime = consonantCount;
        if(consonantCount == 0) if(vowelCount < lowestTime) lowestTime = vowelCount;
        cout << "Case #" << t << ": " << lowestTime << '\n';
    }

}
