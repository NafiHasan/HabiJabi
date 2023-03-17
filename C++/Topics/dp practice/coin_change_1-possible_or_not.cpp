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
    
    int coins[]={3,8,10};
    int x;
    cin >> x;
    bool possible[x+1];
    memset(possible,0,sizeof(possible));
    possible [0]=1;
    for (int i=0; i<=x; i++){
        for (int j=0; j<3; j++){
            if (i>=coins[j])possible[i] |= possible[i-coins[j]];
        }
    }   
    if (possible[x])cout <<"YES\n";
    else cout << "NO\n";
    return 0;
}