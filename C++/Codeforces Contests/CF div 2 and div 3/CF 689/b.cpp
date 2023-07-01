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
        cin >>n>>m;
        char ara[n][m];
        ll ans=0;
        for (int i=0; i<n; i++){
            for (int j= 0; j<m; j++){
                cin >>ara[i][j];
                if (ara[i][j]=='*')ans++;
            }
        }
        for (int i=0; i<n-1; i++){
            for (int j=0; j<m; j++){
                if (ara[i][j]=='*'){
                    int cnt=0;
                    //cout << en;
                    for (int k=i+1; k<n; k++){
                        int found=0;
                        if (j - cnt - 1>=0)
                        {
                            int l;
                            for (l = j - cnt - 1; l <= j + cnt + 1; l++)
                            {
                                //cout << k << " " << l << en;
                                if (ara[k][l] != '*' || l < 0 ||(j+cnt+1)>=m)
                                {
                                    //cout <<k<<" "<<l<<" ";
                                    k = n;
                                    ans += cnt;
                                    cnt = 0;
                                    found = 1;
                                    break;
                                }
                            }
                            if (found == 0 && l<=m){
                                cnt++;
                                //cout <<i<<" "<<j<<" "<<cnt<<en;
                            }
                        }
                        else {
                            ans+=cnt;
                            cnt=0;
                            k=n;
                            break;
                        }
                    }
                    ans+=cnt;
                }
            }
        }
        cout <<ans<<en;
    }
    return 0;
}