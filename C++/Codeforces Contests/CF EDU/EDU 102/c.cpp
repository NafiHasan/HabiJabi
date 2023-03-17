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
        int n,k;
        cin >>n>>k;
        int dif=n-k+1;
        for (int i=1; i<=(k-dif); i++)cout <<i<<" ";
        for (int i=k, j=1;j<=dif; i--,j++ )cout <<i<<" ";
        cout <<en;
    }
    return 0;
}