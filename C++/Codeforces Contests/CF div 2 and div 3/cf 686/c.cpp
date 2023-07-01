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
        int n;cin >>n;
        int ara[n];
        for (int i=0; i<n; i++)cin>>ara[i];
        int crnt=ara[0];
        map<int,int>m;
        for (int i=1; i<n; i++){
            if (ara[i]!=crnt){
                m[ara[i-1]]++;
                if(m[ara[i]]==0) m[ara[i]]++;
            }
            crnt=ara[i];
        }
        int ans=INT_MAX;
        for (int i=0; i<n; i++){
            ans=min(m[ara[i]],ans);
        }
        cout << ans<<en;
    }   
    return 0;
}