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
    
    double x1,y1,x2,y2;
    cin >>x1>>y1>>x2>>y2;
    double ans=(y1*x2+x1*y2)/(y1+y2);
    printf("%.10lf\n",ans);   
    return 0;
}