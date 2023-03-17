#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define dbg(x) cout<<#x<<" = "<<x<<en
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 

int main()
{
    fast_io();
    int n, m;
    cin >> n >> m;
    long long a[n] , add=0;
    for (int i=0; i<n; i++)cin >> a[i];
    int cnt=0;
    long long adc[n];
    memset(adc,0LL, sizeof(0));
    map<int,int>changed;
    while(m--){
        int t;
        cin >> t;
        if (t==1){
            int ind;
            long long val;
            cin >> ind >> val;
            a[ind-1] = val;
            changed[ind-1]++;
            adc[ind-1]=add;
        }
        else if (t==2){
            long long val;
            cin >> val;
            add+=val;
            cnt++;
        }
        else {
            int ind;
            cin >> ind;
            if (changed[ind-1]==0)cout << a[ind-1]+add << en;
            else cout << a[ind-1]+add-(adc[ind-1]) << en;
        }
    }
    return 0;
}