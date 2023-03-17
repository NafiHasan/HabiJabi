#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define rep(i,a,n) for (int i=a; i<n; i++)
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    w(t){
        int n;
        cin >>n;
        int p=n;
        cout <<"2\n";
        cout <<n<< " "<<n-1<<endl;
        if (n>2){
            for (int i=n,j=n-2; i>=3,j>=1; i--,j--){
                cout <<i<<" "<<j<<endl;
            }
        }
    }   
    return 0;
}