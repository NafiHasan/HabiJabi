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
        int n,m;
        cin >>n>>m;
        map<int,int>mp;
        for(int i=0; i<n; i++){
            int x;
            cin >>x;
            mp[x]++;
        }
        int cnt=0;
        for (int i=0; i<m; i++){
            int x;
            cin >>x;
            if (mp[x]>0)cnt++;
        }
        cout <<cnt<<en;
    }
    return 0;
}