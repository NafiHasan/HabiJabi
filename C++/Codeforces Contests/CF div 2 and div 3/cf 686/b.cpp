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
    
    w(y){
        int n;
        cin >>n;
        int ara[n];
        map<int, int> m;
        for (int i=0; i<n; i++){
            cin >> ara[i];
            m[ara[i]]++;
        }
        int ans=INT_MAX,ind=-1;
        for (int i=0; i<n; i++){
            if (m[ara[i]]==1){
                if (ara[i]<ans){
                    ind=i+1;
                    ans=min(ans,ara[i]);
                }
            }
        }
        cout <<ind<<en;
    }   
    return 0;
}