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
        ll n,cnt=0;
        cin >>n;
        ll ara[]={1,2,3,5,6,9,10,13,17};
        for (ll i=0; i<9; i++)if (ara[i]==n)cnt=1;
        if (cnt==1)cout <<"No\n";
        else cout <<"Yes\n"; 
    }   
    return 0;
}