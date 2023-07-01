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
        int n;
        cin >>n;
        int ara[n];
        for(int i=0; i<n; i++)cin >>ara[i];
        ll sum=0;
        for (int i=0; i<n-1; i++){
            sum+=(ll)abs(ara[i]-ara[i+1]);
        }
        ll ans=sum;
        for(int i=1; i<n-1; i++){
            ll c=(ll)abs(ara[i]-ara[i-1])+(ll)abs(ara[i]-ara[i+1])-(ll)abs(ara[i-1]-ara[i+1]);
            ans=min(ans,sum-c);
        }   
        ans=min(ans,sum-(ll)abs(ara[0]-ara[1]));
        ans=min(ans,sum-(ll)abs(ara[n-1]-ara[n-2]));
        cout <<ans<<en;
    }
    return 0;
}