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
        vector<int> v(n);
        for (int &a :v) cin >>a;
        sort (v.rbegin() ,v.rend());
        int sum=0, f=1;
        for (int i=0; i<n; i++){
            sum+=v[i];
            if (sum==0)f=0;
        }
        reverse(v.begin(), v.end());
        sum=0;
        int f1=1;
        for (int i=0; i<n; i++){
            sum+=v[i];
            if (sum==0) f1=0;
        }
        if (f1==0 && f==0)cout <<"NO\n";
        else {
            cout <<"YES\n";
            if (f){
                for (int i=n-1; i>=0; i--)cout <<v[i]<<" ";
            }
            else {
                for (int a:v)cout <<a<<" ";
            }
            cout <<endl;
        }
    }   
    return 0;
}