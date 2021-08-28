#include<bits/stdc++.h>
using namespace std;

int main()
{
    const int maxn = 100000;
    vector<pair<int,int>> primes;

    int n; cin >> n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) {
            primes.push_back({ i,0 });
            while (n % i == 0)
            {
                primes.back().second++;
                n /= i;
            }
        }
    }
    if (n > 1) {
        primes.push_back({ n,1 });
    }
    for (auto i : primes) {
        cout << i.first << ' ' << i.second << '\n';
    }
}