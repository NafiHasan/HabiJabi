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
    
    w(t){
        int n,m,minus=0,mnm=INT_MAX,sum=0;
        cin >>n>>m;
        int ara[n][m];
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >>ara[i][j];
                if(ara[i][j]<0)minus++;
                mnm=min(mnm,abs(ara[i][j]));
                sum+=abs(ara[i][j]);
            }
        }
        int ans;
        if (minus%2==1)ans=sum-(2*mnm);
        else ans=sum;
        cout <<ans<<en;
    }
    return 0;
}