#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

typedef pair<int,int> ii;
typedef vector<ii>vii;
typedef vector<int>vi;

vi dfs_num;

void dfs(int u){
    dfs_num[u]=VISITED;
    for (int j=0; j<(int)AdjList[u].size(); j++){
        ii v=AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED){
            dfs(v.first);
        }
    }
}
//2.11