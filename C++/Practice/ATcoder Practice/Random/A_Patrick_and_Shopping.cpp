#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int d1,d2,d3;
    cin >> d1 >> d2 >> d3;
    int sum=0;
    sum+=min(d1,d2);
    sum+=min(d1+d2,d3);
    sum+=min(max(d1,d2), min(d1,d2)+d3);
    cout << sum << "\n";
    return 0;
}