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
    
    int n;
    long double eu=0;
    ll man=0,best=0,abb;
    cin >>n;
    long double ara[n];
    for (int i=0; i<n; i++){
        cin >> ara[i];
        man+=abs(ara[i]);
        eu+=pow(ara[i],2);
        abb=abs(ara[i]);
        best=max(best,abb);
    }
    cout <<man<<endl;
    long double ans=sqrt(eu);
    cout <<fixed<<setprecision(15)<<ans<<endl;
    cout <<best<<endl;
    return 0;
}