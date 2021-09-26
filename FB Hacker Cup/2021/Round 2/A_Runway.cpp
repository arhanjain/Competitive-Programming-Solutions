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


int main()
{
    ifstream fin;
    fin.open("");
    ofstream fout;
    fout.open("");

    int test; fin >> test;
    for(int t = 1; t <= test; t++) {
        int n; int m; fin >> n >> m;
        vec models;
        for(int i = 0; i < m; i++) {
            int temp; fin >> temp;
            models.push_back(temp);
        }

        vector<int> styles[1e6][1e6];
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                fin >> styles[i][j];
            }
        }



    }

}