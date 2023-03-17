#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int x;
    cin >>x;
    for (int i=0; (1<<i)<=31; i++){
        if ((1<<i) & x){
            int a = ((1 << i) ^ x);
            cout <<a<<en;
        }
    } 
    return 0;
}