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
        cin >>n;
        ll a[n], sum=0;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++){
            a[i]+=sum;
            sum=0;
            if(a[i]>(ll)i){
                sum+=a[i]-(ll)i;
                a[i]=i;
            }
        }
        bool ans=true;
        for(int i=1; i<n; i++){
            if (a[i] <= a[i-1]){
                ans=false;
                break;
            }
        }
        if(ans)cout <<"YES\n";
        else cout << "NO\n";
    }
    return 0;
}