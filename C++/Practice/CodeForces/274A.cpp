#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

ll bin_srch(ll ara[], ll n, ll lo, ll k)
{
    ll hi=n-1, mid;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(ara[mid]==k)return mid;
        else if(ara[mid]<k)lo=mid+1;
        else hi=mid-1;
    }
    return -1;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, k;
    cin >> n >>k;
    ll ara[n];
    int cnt=0;
    bool found [n];
    memset (found, true, sizeof(found));    
    for (int i=0; i<n; i++)cin >> ara[i];
    sort(ara,ara+n);
    for (ll i=0; i<n; i++){
        if(found[i]){
            ll find = ara[i] * k;
            if (bin_srch(ara,n,i+1, find) != -1)
                found[bin_srch(ara, n, i+1, find)] = false;
        }
    }   
    for(int i=0; i<n; i++)if(found[i])cnt++;
    cout <<cnt<<en;
    return 0;
}