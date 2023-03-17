#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,k;
    cin >>n>>k;
    int cnt=0, a[k];
    for (int i=0; i<k; i++)cin >>a[i];
    bool li[n+1];
    memset(li,true,sizeof(li));
    int ans=0;
    for (int i=0; i<k; i++){
        for (int j=a[i]; j<=n; j+=a[i]){
            if (li[j]==false){
                li[j]=true;
                cnt--;
            }
            else {
                li[j]=false;
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    cout <<ans<<en;
    return 0;
}