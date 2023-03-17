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
    
    int n,m;
    cin >>n>>m;
    int ara[n],ara2[n];
    for(int i=0; i<n; i++)cin>> ara[i];   
    for(int i=0; i<n; i++)cin>> ara2[i];
    sort(ara,ara+n);
    sort(ara2,ara2+n);
    int ans=m;
    for(int i=0; i<n; i++){
        int dif=abs(ara[i] - ara2[i]);
        if (dif>0)ans=min(ans,dif);
    }
    if (ans==m)cout <<"0\n";
    else cout <<ans<<en;
    return 0;
}