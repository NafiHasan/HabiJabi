#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,k;
    cin >>n>>k;
    while(k--){
        if (n%10==0)n/=10;
        else n--;
    }   
    cout <<n<<en;
    return 0;
}