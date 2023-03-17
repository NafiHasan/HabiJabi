#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

int dp[201][500];
int fun(int a[], int i, int x, int n){
    if (x > 2 * n)
        return 10000000;
    if (i == n)
        return 0;
    if (dp[i][x] != 10000000)
        return dp[i][x];
   
    
    int ans = 10000000;
    for (int t = x; t < 2 * n; t++){
        int v= abs(t-a[i]);
        ans= min(ans,v+fun(a,i+1,t+1,n));
    }
    dp[i][x]=ans;
    return dp[i][x];
}
int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int a[n];
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=2*n;j++)
                dp[i][j]=10000000;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        //cout<<"ans:";
        cout << fun(a, 0, 1, n);
        cout<<"\n";
    }
    
    return 0;
}