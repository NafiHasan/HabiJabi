#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n,val;
    cin >>n>>val;
    int coins[n];
    int best[val];
    for (int i=0; i<n; i++){
        cin >> coins[i];
        int x= coins[i];
        best[x]=1;
    }
    best[0]=0;
    for (int i=1; i<=val; i++){
        best[i]=1e9;
        for (int j=0; j<n; j++){
            if (i-coins[j]>=0){
                int x=coins[j];
                best[i]=min(best[i],best[i-x]+1);
            }
        }
    }   
    cout << best[val] << en ;
    return 0;
}