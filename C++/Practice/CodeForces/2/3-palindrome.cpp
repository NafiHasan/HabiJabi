#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >>n;
    int a=0,b=0,c=0;
    for (int i=0; i<n; i++){
        if (a<2 && b!=1){
            cout <<"a";
            a++; b=0;c=0;
        }
        else if (b<2){
            cout <<"b";
            b++;a=0;
        }
    }   
    cout <<en;
    return 0;
}