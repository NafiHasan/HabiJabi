#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

int way[100005];
int coins[3]={2,3,5};

int solve(int x){
    way[0]=1;
    for (int i=1; i<=x; i++){
        for (int j=0; j<3; j++){
            if (coins[j]<=i){
                way[i]+=way[i-coins[j]];
            }
        }
    }
    return way[x];
}
int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int ans=solve(5);
    cout <<ans<<en;
    return 0;
}