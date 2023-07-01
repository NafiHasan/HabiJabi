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
        int n,k;
        cin >>n>>k;
        int mid=(n+1)/2;
        int ara[n*k];
        for (int i=0; i<(n*k); i++)cin >>ara[i];
        ll cnt=0;
        for (int i=(n*k)-(n/2)-1,j=1; i>=0,j<=k; j++,i-=n/2+1)cnt+=(ll)ara[i];
        cout <<cnt<<en;
    }   
    return 0;
}