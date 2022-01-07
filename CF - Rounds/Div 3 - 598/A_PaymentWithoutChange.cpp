#include <bits/stdc++.h>
using namespace std;

int main () {
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int a; int b; int n; int s;
        cin >> a >> b >> n >> s;

        //a of n value coins, b of 1 value
        if(n == 1 and s <= (a+b))
        {
            cout << "YES \n";
            continue;
        }
        if(s/n <= a and s%n <= b) {
            cout << "YES \n";
        } else {
            cout << "NO \n";
        }
    }

}
