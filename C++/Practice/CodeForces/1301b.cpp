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
        int n;
        cin >>n; 
        int ara[n];
        int dif=0, ans=0;
        int mn=1e9,mx=0;
        for(int i=0; i<n; i++) cin >> ara[i];
        
        for (int i=0; i<n; i++){
            if (i && i < n - 1 && ara[i] == -1 && ara[i-1]!=-1){
                mn= min(mn, ara[i - 1]);
                mx= max(mx, ara[i - 1]);
            }
            if (i&& i<n-1 &&  ara[i]==-1 && ara[i+1]!=-1){
                mn = min(mn, ara[i + 1]);
                mx = max(mx, ara[i + 1]);
            }
            else if (i==0 && ara[i+1]!=-1 && ara[i]==-1){
                mn=min(mn, ara[i+1]);
                mx=max(mx, ara[i+1]);
            }
            else if (i==n-1 && ara[i-1]!=-1 && ara[i]==-1){
                mn=min(mn,ara[i-1]);
                mx=max(mx, ara[i-1]);
            }
        }
        dif=(mx+mn)/2;
        for (int i=0; i<n; i++){
            if (ara[i]==-1)ara[i]=dif;
        }
        for( int i=1; i<n; i++){
            ans=max(ans,abs(ara[i]-ara[i-1]));
        }
        cout << ans<<" "<< abs(dif)<<en;
    }   
    return 0;
}