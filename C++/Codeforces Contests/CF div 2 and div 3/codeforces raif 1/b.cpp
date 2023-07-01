#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    
    w(t){
        int x1,y1,x,y;
        cin >>x1>>y1>>x>>y;
        int cnt=abs(x1-x)+abs(y1-y);
        if (x!=x1 && y!=y1)cout <<cnt+2<<endl;
        else cout <<cnt<<endl;
    }
    return 0;
}