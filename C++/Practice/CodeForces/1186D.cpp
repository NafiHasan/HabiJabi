#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >>n ;
    long double a[n];
    ll ara[n], sum=0;
    for(ll i=0; i<n; i++){
        cin >>a[i];
        long double x;
        if (a[i]<0.0)x=ceil(a[i]);
        else x=floor(a[i]);
        ara[i]=(ll)x;
        sum+=(ll)x;
    }   
    for(ll i=0; i<n; i++){
        if(sum==0)break;
        else if (sum<0 && (long double)ara[i]!=a[i] && a[i]>=0.0){
            ara[i]++;
            sum++;
        }
        else if (sum>0 && (long double)ara[i]!=a[i] && a[i]<0){
            ara[i]--;
            sum--;
        }
    }
    for(ll i=0; i<n; i++)cout<< ara[i]<<en;
    return 0;
}