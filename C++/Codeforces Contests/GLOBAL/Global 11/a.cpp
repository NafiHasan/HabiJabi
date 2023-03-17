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
        int n,ans=0,sum=0,sum1=0;
        cin >>n;
        int ara[n];
        for (int i =0; i<n; i++){
            cin >>ara[i];
            sum1+=ara[i];
            sum+=ara[i];
            if (sum1==0)ans=-1;
        }
       if (sum==0)cout <<"NO\n";
       else if (ans==0){
           cout <<"YES\n";
           for (int i=0; i<n; i++)cout <<ara[i]<<" ";
           cout <<endl;
       }
       else if (sum>0){
           sort (ara,ara+n, greater<int>());
           cout <<"YES\n";
           for (int i=0; i<n; i++){
               cout <<ara[i]<<" ";
           }
           cout <<endl;
       }
       else {
           sort (ara,ara+n);
           cout <<"YES\n";
           for (int i=0; i<n; i++)cout <<ara[i]<<" ";
           cout <<endl;
       }
    }   
    return 0;
}