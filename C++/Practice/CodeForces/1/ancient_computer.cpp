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
        ll a , b;
        cin>>a>>b;
        ll div=-1;
        if (a>b && a%b==0)div=a/b;
        else if (a<=b && b%a==0) div =b/a;
        ll ans=log2(div);
        if( (ll)pow((ll)2, ans)== div){
            cout << ceil((double)ans/3.0)<<en;
        }
        else cout << "-1\n";
    }   
    return 0;
}