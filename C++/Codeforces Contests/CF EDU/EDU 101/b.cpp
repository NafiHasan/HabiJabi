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
        int n,m;
        cin >>n;
        int a[n];
        for (int i=0; i<n; i++)cin >>a[i];
        cin >>m;
        int b[m];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        int mx=0,best=0, ind=0;
        for (int i=0; i<n; i++){
            mx+=a[i];
            best=max(best,mx);
        }
        mx=0;
        int bst2=0;
        for (int i=0; i<m; i++){
            mx+=b[i];
            bst2=max(bst2,mx);
        }
        cout<<best+bst2<<en;
    }   
    return 0;
}