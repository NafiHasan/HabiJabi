#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;  cin>>n;
    int ara[n];
    for(int i=0; i<n; i++)cin>> ara[i];
    int q;  cin>>q;
    
    //precompute the queries
    //for faster log calculation
    int log[n+1];
    log[1]=0;
    for(int i=2; i<=n; i++){
        log[i]=log[i/2] + 1;
    }
    int K=log[n]+1;
    int st[n+1][K];
    for(int i=0; i<n; i++) st[i][0]=ara[i]; //for(range of 2^0)

    for(int i=1; i<=K; i++){
        for(int j=0; (j+(1<<i)) <= n; j++)
            st[j][i] = min(st[j][i - 1], st[j+ (1 << (i-1))][i-1]);
    }

    for(int l=0; l<q; l++){
        int i,j;
        cin>> i >> j;
        int len= log[j-i+1];
        cout << min (st[i][len], st[j-(1 << len)+1][len]) << en;
        cout <<st[0][2]<<en;
    }   
    return 0;
}