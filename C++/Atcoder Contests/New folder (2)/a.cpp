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
    
    double s,p;
    cin>>s>>p;
    double n1=(s+sqrt(s*s-4*p))/2;
    double n2=(s-sqrt(s*s-4*p))/2;
    double m1=s-n1;
    double m2=s-n2;
    ll n11=(ll)n1, n22=(ll)n2, m11=(ll)m1, m22=(ll)m2;
    if (m11*n11==p && m11+n11==s)cout <<"Yes\n";
    else if (m22*n22 ==p && m22+n22==s) cout <<"Yes\n";
    else cout <<"No\n";
    return 0;
}