#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        bool ans=false;
        for (int i=0; i<=500; i++){
            for (int j=0; j<=500; j++){
                if ((2020*i+2021*j)==n){
                    ans=true;
                    break;
                }
            }
        }
        if (ans)cout <<"YES\n";
        else cout <<"NO\n";
    }   
    return 0;
}