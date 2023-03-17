#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--){
        int n;
        cin >> n;
        long long c[n];
        for(int i=0; i<n; i++) cin >> c[i];
        long long a[n] , b[n];
        for(int i=0; i<n; i++)cin >> a[i];
        for(int i=0; i<n; i++)cin >> b[i];
        long long ans=c[n-1]+1 ,cnt=c[n-1]+1;
        for(int i=n-2; i >=0; i--){
            if(abs (a[i+1]-b[i+1])==0)cnt=0;
            if(i==0){
                cnt+=abs(a[i+1]-b[i+1]);
                ans=max(ans,cnt);
                break;
            }
            ans = max(ans, cnt + abs(a[i + 1] - b[i + 1]));
            long long p=cnt+c[i]-abs(a[i+1]-b[i+1])-1;
            if(c[i]-1 > p){
                cnt = c[i] + 1;
                //cout <<"came" <<i<< en;
                continue;
            }
            cnt+= c[i]-abs(a[i+1]-b[i+1]) +1;
            ans=max(ans,cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}