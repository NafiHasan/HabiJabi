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
        int n,c0,c1,h;
        cin>>n>>c0>>c1>>h;
        string s;
        cin>>s;
        ll cnt=0;
        for (int i=0; i<n; i++){
            if (s[i]=='0' && h+c1>c0)cnt+=(ll)c0;
            else if (s[i]=='0' && h+c1<=c0)cnt+=(ll)(c1+h);
            else if (h+c0<c1){
                cnt+=(ll)(h+c0);
            }
            else cnt+=(ll)c1;
        }
        cout <<cnt<<en;
    }   
    return 0;
}