#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

ll bin_srch(ll x,ll y,ll n){
    for (ll i=0; i<=10; i++){
        if ((ll)pow(x,i) *(ll)pow(y,10-i) >=n)return i;
    }
    return (ll)10;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    ll n;
    cin >>n;
    ll total=pow(n,0.1);
    ll x = bin_srch(total+1, total, n); 
    //cout <<x<<en;
    char s[] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
    for (int i=0; i< x ; i++){
        for (int j=1; j<= total+1; j++)cout <<s[i];
    }
    for (int i=x; i<10; i++){
        for (int j=1; j<=total; j++)cout <<s[i];
    }
    cout << en;
    return 0;
}