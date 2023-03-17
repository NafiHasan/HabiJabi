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
    int c=1;
    w(t){
        ll n,k;
        cin >>n>>k;
        if (n<k)cout <<"Case "<<c++<<": "<<"0\n";
        else if (k==0)
            cout << "Case " << c++ << ": "<< "1\n";
        else {
            ll ara[k];
            ara[0]=n*n;
            for (int i=1; i<k; i++){
                ara[i] = ara[i - 1] *pow(n - i, 2) / (i + 1);
            }
            cout <<"Case "<<c++<<": "<<ara[k-1]<<en;
        }
    }   
    return 0;
}