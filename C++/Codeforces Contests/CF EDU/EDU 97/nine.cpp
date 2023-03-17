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
    
    string s;
    cin >>s;
    ll cnt=1,sum=1;
    for (int i=0; i<s.size(); i++){
        if (i && (s[i]-'0')+(s[i-1]-'0')==9)cnt++;
        else {
            if (cnt>1 && cnt%2==1)sum*=((cnt+1)/2);
            cnt=1;
        }
    }
    if (cnt > 1 && cnt % 2 == 1)
        sum *= ((cnt +1)/2);
    cout <<sum<<en;
    return 0;
}