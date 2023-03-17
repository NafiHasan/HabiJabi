#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    int c=1;
    w(t) {
        ll n;
        cin >>n;
        vector<vector<ll>>v;
        vector<vector<ll>>best;
        for (ll i=0; i<n; i++){
            vector<ll>v1;
            for (ll j=0; j<=i; j++){
                int x;
                cin >>x;
                v1.push_back(x);
            }
            v.push_back(v1);
            best.push_back(v1);
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<=i; j++){
                if (j==0 && i>0)best[i][j]=v[i][j]+best[i-1][j];
                else if (j==i && i>0 && j>0)best[i][j]=v[i][j]+best[i-1][j-1];
                else if (i>0 && j>0){
                    best[i][j]=v[i][j]+max(best[i-1][j],best[i-1][j-1]);
                }
            }
        }
        for (int i=n,k=n-1; i<2*n-1;k--, i++){
            vector <ll>v1;
            for (int j=0; j<k; j++){
                int x;
                cin >>x;
                v1.push_back(x);
            }
            v.push_back(v1);
            best.push_back(v1);
        }
        for (int i = n, k = n - 1; i < 2 * n - 1; k--, i++){
            for (int j = 0; j < k; j++){
                best[i][j]=v[i][j]+max(best[i-1][j],best[i-1][j+1]);
            }
        }
        cout <<"Case "<<c++<<": "<<best[2*n-2][0]<<en;
    }  
    return 0;
} 