#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

vector<pair<int, int>> dp[1000010];

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        vector<int>a(2*n);
        map<int,int>done;
        for (int i=0; i<2*n; i++){
            cin >> a[i];
            done[a[i]]++;
        }
        for (int i=0; i<1000010; i++)dp[i].clear();
        sort (a.begin(),a.end());
        int now=a[2*n-1];
        cout <<now<<en;
        vector <pair<int,int>>vp;
        for (int i=0; i<2*n-1; i++){
            for (int j=i+1; j<2*n; j++){
                int x=a[i],y=a[j];
                dp[x+y].push_back({x,y});
                //cout <<x<<en;
            }
        }
        bool found=true;
        while(found){
            if (dp[now].size()==0)break;
            else {
                found=false;
                for (int i=0; i<dp[now].size(); i++){
                    int x = dp[now][i].first, y = dp[now][i].second; 
                    if ((done[x]>0 && done[y]>0 && x!=y) || ((done[x]>1) && x==y)){
                        vp.push_back({x,y});
                        done[x]--;
                        done[y]--;
                        now=max(x,y);
                        found=true;
                        i=0;
                        cout <<now<<en;
                        continue;
                        //cout <<x<<" "<<y<<" "<<done[x]<<" " <<done[y]<<"\n";
                    }
                }
            }
            //cout <<"a";
        }
        if ((vp.size()+1) != n)cout <<"NO\n";
        else {
            cout <<"YES\n";
            for (int i = 0; i <2*n; i++)
            {
                if (done[a[i]])
                {
                    cout <<a[2*n-1]+a[i]<<en;
                    cout << a[2 * n - 1] << " " << a[i] << "\n";
                    break;
                }
            }
            for (int i = 0; i < vp.size(); i++)
                cout << vp[i].first << " " << vp[i].second << "\n";
        }
    }   
    return 0;
}