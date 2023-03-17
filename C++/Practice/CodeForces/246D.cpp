#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

set<int> st[101000];

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, m ;
    cin >> n>> m;
    int clr[n];
    for(int i=0; i<n; i++)cin >>clr[i];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u>> v;
        u--,v--;
        int cu=clr[u], cv=clr[v];
        if(cu!=cv)
            st[cu].insert(cv);
        if(cu!=cv)
            st[cv].insert(cu);
    }
    sort(clr, clr + n);
    int best=0, ans=clr[0];
    for(int i=0; i<n; i++){
        if(st[clr[i]].size()>best){
            best=st[clr[i]].size();
            ans=clr[i];
        }
    }
    cout << ans<< "\n";
    return 0;
}