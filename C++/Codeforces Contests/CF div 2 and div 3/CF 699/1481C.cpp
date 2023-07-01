#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        int n,m;
        cin >>n>>m;
        int a[n],b[n],c[m], cnt=0;
        priority_queue<int>des[n];
        vector<int>have(n,-1);
        for (int i=0; i<n; i++){
            cin >> a[i];
            a[i]--;
        }
        for (int i=0; i<n; i++){
            cin >> b[i];
            b[i]--;
            have[b[i]] = i;
            if (a[i]!=b[i]){
                cnt++;
                des[b[i]].push(i);
            }
        }
        for (int i=0; i<m; i++){
            cin >> c[i];
            c[i]--;
        }
        vector<int>ans(m,-1);
        if (cnt>m || (have[c[m-1]]==-1 && des[c[m-1]].size()==0))cout <<"NO\n";
        else {
            for (int i=m-1; i>=0; i--){
                if (des[c[i]].size()==0){
                    if (have[c[i]]!=-1)ans[i]=have[c[i]]+1;
                    else ans[i]=0;
                    //cout <<ans[i]<<" "<<i<<en;                
                }
                else {
                    int top=des[c[i]].top();
                    //cout << top<<en;
                    des[c[i]].pop();
                    ans[i]=top+1;
                    a[top]=c[i];
                }
            }
            // cout <<ans[0]<<" a";
            for (int i=0; i<m-1; i++)if (ans[i]==0)ans[i]=ans[m-1];
            bool f=true;
            for (int i=0; i<n; i++){
                if (a[i]!=b[i]){
                     //cout << a[i] << " " << b[i] << en;
                    f=false;
                    break;
                }
            }
            for (int i=0; i<m; i++){
                if (ans[i]==-1){
                    f=false;
                    // cout <<"s" <<i<<" ";
                    break;
                }
            }
            if(f){
                cout <<"YES\n";
                for (int i=0; i<m; i++)cout <<ans[i]<<" ";
                cout <<en;
            }
            else cout <<"NO\n";
        }
    }   
    return 0;
}