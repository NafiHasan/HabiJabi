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
    cin >> n;
    long long a[n], sum[n],suf[n],cnt[n];
    for (int i=0; i<n; i++)cin >> a[i];
    sum[0]=a[0];
    for(int i=1; i<n; i++)sum[i]=a[i]+sum[i-1];
    if(sum[n-1]%3!=0){
        cout << "0\n";
        return 0;
    }
    for(int i=n-1; i>=0; i--){
        if (sum[n - 1] - sum[i - 1] == sum[n - 1] / 3)
            cnt[i] = 1;
        else cnt[i]=0;
    }
    suf[n-1]=cnt[n-1];
    //cout <<suf[n-1]<<" ";
    for(int i=n-2; i>=0; i--){
        suf[i] = suf[i + 1] + cnt[i];
        //cout << suf[i]<< " ";
    }
    long long ans=0;
    for(int i=0; i<n-2; i++){
        if(sum[i]==sum[n-1]/3)ans+=suf[i+2];
    }   
    cout << ans << "\n";
    return 0;
}