#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

int solve[100000];
int coins[10000];

int dp(int x,int n){
    int best=1e9;
    if (x==0)return 0;
    if (solve[x]>0)return solve[x];
    else {
        for (int i=0; i<n; i++){
            if (coins[i]<=x)best =min(best,dp((x-coins[i]),n)+1);
        }
        //cout<<best<<en;
        solve[x]=best;
        return best;
    }

}
int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n,x;
    cin >>n>>x;
    for (int i = 0; i < x; i++)
        solve[i] = -1;
    for (int i=0; i<n; i++){
        cin >> coins[i];
        solve[coins[i]]=1;
    }
    cout <<dp(x,n)<<en;
    return 0;
}