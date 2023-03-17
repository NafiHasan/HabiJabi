#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int a[5][5];
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++)cin >> a[i][j];
    }
    int ans=0;
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (i==j) continue;
            for (int k=0; k<5; k++){
                if (k==i || k==j)continue;
                for (int l=0; l<5; l++){
                    if (l==k || l==j || l==i)continue;
                    for (int m=0; m<5; m++){
                        if (m==l || m==i || m== j|| m==k) continue;
                        int tmp=2*(a[l][k]+a[k][l]) + 2*(a[l][m]+a[m][l]);;
                        tmp+=a[j][k]+a[k][j];
                        tmp+=a[i][j]+a[j][i];
                        ans=max(ans,tmp);
                    }
                }
            }
        }
    }
    cout << ans<< en;
    return 0;
}