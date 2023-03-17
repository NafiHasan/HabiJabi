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
        ll k,x,y,z;
        cin >>k>>x>>y>>z;
        ll ans=pow(10,k)*x*y/(z-y);
        string s=to_string(ans);
        int cnt=0;
        for (int i=0; i<s.size(); i++)cnt+=s[i]-'0';
        if (z==y)cnt=0;
        cout << "Winning percentage of Drump is: "<<cnt<<"%"<<en;
    }   
    return 0;
}