#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >>n;
    int a[n];
    ll odd=0, even=0;
    for (int i=0; i<n; i++) cin >> a[i];
    int d[n-1];
    for(int i=0; i<n-1; i++){
        d[i]=abs(a[i]-a[i+1]);
        if (i%2==0)even++;
        else odd++;
    }   
    ll sum=0, ans=0;
    int start=0;
    if (odd>even)start=1;
    int ind=start,end=n-2;
    for (int i=start; i<n-2; i+=2){
        if (d[i]<d[i+1] && i<n-2)ind+=2;
    }
    start=ind;
    for (int i=start; i<n-2; i+=2){
        if ((i-start)%2==0)sum+=d[i];
        else sum-=d[i];
    }
    for (int i=n-2; i>=start; i--){
        if ((i-start)%2==0){
            sum-=d[i];
            ans=max(ans,sum);
        }
        else {
            sum+=d[i];
            ans=max(ans,sum);
        }
    }
    cout << ans << en;
    return 0;
}