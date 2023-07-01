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
        int n;
        map<int,int>m;
        cin >>n;
        bool ans=false;
        int ara[n];
        for (int i=0; i<n; i++){
            cin >> ara[i];
            m[ara[i]]++;
            if (m[ara[i]]>1)ans=true;
        }
        if (ans==true)cout <<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}