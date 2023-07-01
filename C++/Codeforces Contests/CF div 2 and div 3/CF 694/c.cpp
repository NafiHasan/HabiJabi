#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n,m;
        cin >> n>> m;
        int a[n];
        int cost[m];
        for(int i=0; i<n; i++)cin >> a[i];
        for (int i=0; i<m; i++)cin >> cost[i];
        ll sum=0;
        sort(a,a+n,greater<int>()); 
        for(int i=0,j=0; i<n; i++){
            if(j<m && cost[j]<cost[a[i]-1]){
                sum+=cost[j];
                j++;
            }
            else sum+=cost[a[i]-1];
        }
        cout << sum<<en;
    }   
    return 0;
}