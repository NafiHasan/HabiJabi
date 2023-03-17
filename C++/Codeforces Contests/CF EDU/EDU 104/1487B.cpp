#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    // ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        int n,k;
        cin >>n>>k;
        int ans;
        int half=n/2;
        if (k<=half){
            cout <<k<<en;
        }
        else if (n%2==0){
            ans=k%n;
            if (ans==0)ans=n;
            cout <<ans<<en;
        }
        else {
            half++;
            int cnt=k/half;
            int x=(k+cnt)/half;
            while(x!=cnt){
                cnt=x;
                x=(k+x)/half;
            }
            ans=(k+cnt)%n;
            if (ans==0)ans=n;
            cout <<ans<<en;
        }
    }
    return 0;
}