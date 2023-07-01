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
        int c;
        cin >>c;
        int lim=sqrt(c)+1;
        int ans=0;
        if (c==2)ans=1;
        else if (c==3)ans=2;
        else if (c%2==0) ans=2;
        else if (c!=1 && c%2==1)ans=3;
        cout <<ans<<en;
    }
    return 0;
}