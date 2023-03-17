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
        ll n,k;
        cin >>n>>k;
        ll ans=k;
        ll num=0;
        ll tmp=0;
        while((ans/n-num/n )!=0){
            tmp=ans;
            ans+=(ans/n-num/n);
            num=tmp;
        }
        cout <<ans<<en;
    }   
    return 0;
}