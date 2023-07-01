#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define rep(i,a,n) for (int i=a; i<n; i++)
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    w(t){
        ll r,c,cnt=0;
        cin >>r>>c;
        vector <vector<ll>> v;
        for (ll i=0,k=0; i<r; i++){
            vector <ll>v1;
            for (ll j=0; j<c; j++){
                ll tmp;
                cin >>tmp;
                v1.push_back(tmp);
            }
            v.push_back(v1);
        }
        for (ll i = 0; i < r; i++){
            for (int j=0; j<c; j++){
                vector <ll> a={v[i][j],v[i][c-j-1],v[r-i-1][j],v[r-i-1][c-j-1]};
                sort (a.begin(),a.end());
                ll mid=a[1];
                cnt+=abs(mid-v[i][j]);
                v[i][j]=mid;
                cnt+=abs(mid-v[r-i-1][j]);
                v[r-i-1][j]=mid;
                cnt+=abs(mid-v[r-i-1][c-j-1]);
                v[r-i-1][c-j-1]=mid;
                // cout <<cnt<<" ";
            }
        }  
        cout <<cnt<<endl; 
    }
    return 0;
}