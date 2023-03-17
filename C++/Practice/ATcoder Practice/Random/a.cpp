#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    w(t){
        int x,y;
        cin>>x>>y;
        int m=max(x,y);
        if (abs(x-y)<=1)cout <<x+y<<en;
        else cout <<2*m-1<<en;
    }   
    return 0;
}