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
        int a,b;
        cin >>a>>b;
        // if (a==b)cout <<a-1<<" "<<b<<en;
        // else if (a<b){
        //     int ansa=a-1;
        //     int ansb=b;
        //     cout <<ansa<<" "<<ansb<<en;
        // }
        // else {
        //     cout <<a-1<<" "<<b<<en;
        // }
        cout <<a-1<<" "<<b<<en;
    }
    return 0;
}