#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n; cin >> n;
    vector<string>v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    vector<char>a[26];
    for(int i = 1; i < n; i++){
        if(v[i]<v[i-1]){
            for(int j=0; j<v[i-1].size(); j++){
                if(v[i-1][j]<v[i][j])break;
                else{
                    int ind=v[i][j]-97;
                    a[ind].push_back(v[i-1][j]);
                }
            }
        }
    }
    return 0;
}