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
    string s;
    cin >>s;
    ll ans=n/3;
    if (n%3>0)ans++;
    ans--;
    ans=1e10-ans;
    int cnt1=0,cnt0=0;
    for (int i=0; i<s.size(); i++){
        if (s[i]=='0' && cnt1<2 && i>2)ans=0;
        else if (s[i]=='0'){
            cnt0++;
            cnt1=0;
        }
        else {
            cnt1++;
            cnt0=0;
        }
        if (cnt1>2 || cnt0>1)ans=0;
    }   
    cout <<ans<<en;
    return 0;
}