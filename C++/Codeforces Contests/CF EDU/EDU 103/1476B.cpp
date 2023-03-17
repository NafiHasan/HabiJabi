    #include <bits/stdc++.h>
    using namespace std;

    #define w(t) int t; cin >> t; while (t--)
    #define ll long long int
    #define en "\n"


    int main ()
    {
        ios::sync_with_stdio(false);  cin.tie(NULL);
        w(t){
            int n;
            double k;
            cin >>n>>k;
            long double a[n];
            long double ans=0;
            for (int i=0; i<n; i++)cin >>a[i];
            long double sum=a[0];
            for (int i=1; i<n; i++){
                //cout <<sum<<" " <<a[i] / (k / 100.0)<<" " << ans<<"\n";
                long double p = (a[i]*100.0 /k) -sum; 
                //cout <<p<<" ";
                ans = max (p,ans);
                sum+=a[i];
            }
            ll an=ceil(ans);
            cout <<an<<en;
        }
        return 0;
    }