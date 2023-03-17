#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    ll n,d;
    cin >>n>>d;
    ll a[n];
    for (int i=0; i<n; i++)cin >>a[i];
    if(n==2){
        long double sum=abs(a[0]-a[1]);
        long double ans=abs((long double)d - sum)/2;
        cout <<ans<<en;
        return 0;
    }
    ll cnt[n];
    for (int i=0; i<n; i++)
        cnt[i]=(i*d)-a[i];
    ll mn=*min_element(cnt,cnt+n), mx=*max_element(cnt,cnt+n);
    //cout <<mn<<" "<<mx<<en;
    long double x=(double)(mn+mx)/2.0;
    //cout << x << en;
    long double ans=0,ans2=0;
    for (int i=0; i<n; i++)
        ans=max(ans,abs((long double)a[i]-(x+(long double)i*(long double)d)));
    x*=-1.0;
    for (int i = 0; i < n; i++)
        ans2 = max(ans2, abs((long double)a[i] - (x + (long double)i*(long double)d)));
    for (int i = 0; i < n; i++)
        cnt[i] = -(i * d) - a[i];
    mn = *min_element(cnt, cnt + n), mx = *max_element(cnt, cnt + n);
    x = (double)(mn + mx) / 2.0;
    long double ans3 = 0, ans4 = 0;
    for (int i = 0; i < n; i++)
        ans3 = max(ans3, abs((long double)a[i] - (x - (long double)i * (long double)d)));
    x *= -1.0;
    for (int i = 0; i < n; i++)
        ans4 = max(ans4, abs((long double)a[i] - (x - (long double)i * (long double)d)));
    cout << setprecision(1) <<fixed << min({ans,ans2,ans3,ans4})<<en;
    return 0;
}