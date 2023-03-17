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
    
    int  n,m;
    cin >>n >>m;
    int ara[n];
    for(int i=0; i<n; i++)cin >> ara[i];

    int log[n+1];
    log[1]=0;
    for(int i=2; i<=n; i++)log[i]=log[i/2]+1;

    int K=log[n]+1;
    int pos[n+1][K];
    for(int i=1; i<n; i++){
        pos[i][0]=ara[i];
    }
    // for (int i=0; i<n-1; i++){
    //     if (ara[i] <= ara[i + 1])
    //         pos[i][2] = true;
    //     else pos[i][2]=false;
    // }

    for(int i=1; i<=K; i++){
        for (int j=0; (j+(1<<i)) <=n; j++){
            pos[j][i]=max(pos[j][i-1] , pos[j+(1<<(i-1))][i-1]);
        }
    }
    int cnt=0;
    for (int i=0; i<m; i++){
        int L,R;
        cin >>L>>R;
        L--;R-=2;
        int len=log[R-L+1];
        if (ara[L] == max(pos[R - (1 << len) + 1][len],pos[L][len]))
        {
            cnt++;
            //cout <<en<<L+1<<" "<<R+2<<en;
        }
    }
    cout <<cnt<<en;
    return 0;
}