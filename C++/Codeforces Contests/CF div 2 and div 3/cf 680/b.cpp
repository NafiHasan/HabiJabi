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
        int a,b,c,d;
        cin >>a>>b>>c>>d;
        cout <<max(a+b,c+d)<<en;
    }
    return 0;
}