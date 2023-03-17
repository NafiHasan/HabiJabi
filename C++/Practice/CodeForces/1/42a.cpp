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
    
    int n,v;
    cin >>n>>v;
    double a[n],b[n],suma=0;
    for (int i=0; i<n; i++){
        cin >>a[i];
        suma+=a[i];
    }   
    for (int i=0; i<n; i++)cin >>b[i];
    double c[n];
    for (int i=0; i<n; i++)c[i]=b[i]/a[i];
    double lo=*min_element(c,c+n);
    double ans=suma*lo;
    if (ans>v)ans=v;
    printf("%.6lf\n",ans);
    return 0;
}