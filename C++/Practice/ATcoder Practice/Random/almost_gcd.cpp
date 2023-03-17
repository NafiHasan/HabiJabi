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
    
    int n;
    cin >>n;
    int ara[n];
    for (int i=0; i<n; i++)cin >>ara[i];
    int ans=0,best=0,cnt;
    for (int i=0; i<n; i++){
        cnt=0;
        for (int j=0; j<n; j++){
            if (ara[j]%ara[i]==0)cnt++;
        }
        if (cnt>best){
            best=cnt;
            ans=ara[i];
        }
    }
    cout <<ans<<en;
    return 0;
}