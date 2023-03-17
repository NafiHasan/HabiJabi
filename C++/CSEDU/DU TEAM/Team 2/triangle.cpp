#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    double a,b,c ;
    cin >>a>>b>>c;
    double s=(a+b+c)/2.0;
    double ans=sqrt(s*(s-a)*(s-b)*(s-c));
    cout <<ans<<en;
    return 0;
}