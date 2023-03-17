#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    freopen("hash.in", "r", stdin);
    freopen("hash.out", "w", stdout);
    int n;
    cin >>n;
    string s="A";
    for (int i=1; i<n; i++)s+='a';
    cout <<s<<en;
    for (int i=0; i<n-1; i++){
        s[i]+=1;
        s[i+1]-=31;
        cout <<s<<en;
    }   
    return 0;
}