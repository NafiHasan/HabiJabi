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
        int n,d;
        cin >>n>>d;
        int a[n];
        int sum=0;
        bool ans=true;
        for (int i=0; i<n; i++){
            cin >>a[i];
            if (a[i]>d)ans=false;
        }
        if (!ans){
            for (int i=0; i<n-1; i++){
                for (int j=i+1; j<n; j++){
                    if (a[i]+a[j]<=d){
                        i=n;
                        ans=true;
                        break;
                    }
                }
            }
        }
        if (ans)cout <<"yes\n";
        else cout <<"no\n";
    }   
    return 0;
}