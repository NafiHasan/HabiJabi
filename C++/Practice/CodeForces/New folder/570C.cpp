#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int m, t;
    string s;
    cin>>m>>t>>s;
    int cnt=0;
    vector<pair<int,int>>vp;
    for(int i=0; i<m-1; i++)if(s[i]=='.' && s[i+1]=='.')cnt++;
    for(int i=0,j=0,k=0; i<m; i++){
        if(s[i]=='.' && s[i-1]!='.' && i<m-1) j=i;
        if (s[i]!='.' || (s[i]=='.' && i==m-1)) k = i - 1;
        if (j <= k) vp.push_back({j, k});
    }
    while(t--){
        int n; char c;
        cin >>n>>c;
        n--;
        if(s[n]=='.' && c=='.'){
            s[n]=c;
            cout <<cnt<<en;
            continue;
        }       
        else if (s[n]!='.' && c!='.'){
            s[n]=c;
            cout <<cnt<<en;
            continue;
        }
        else if(s[n]=='.'){
            int m1=-1,m2=-1;
            if (s[n - 1] == '.' && n>0){
                int mid, lo = 0, hi = vp.size() - 1;
                while (lo <= hi){
                    mid = (lo + hi) / 2;
                    if (vp[mid].first >= n - 1 && vp[mid].second <= n - 1) break;
                    else if (vp[mid].first <= n - 1) lo = mid + 1;
                    else hi = mid - 1;
                }
                m1 = mid;
                cnt--;
                vp[mid].second = n-1;
            }
            if (n < m - 1 && s[n + 1] == '.' && m1 != -1){
                int mid, lo = 0, hi = vp.size() - 1;
                while (lo <= hi){
                    mid = (lo + hi) / 2;
                    if (vp[mid].first >= n + 1 && vp[mid].second <= n + 1)   break;
                    else if (vp[mid].first <= n + 1) lo = mid + 1;
                    else hi = mid - 1;
                }
                cnt--;
                m2 = mid;
                vp.push_back({n+1,vp[mid].second});
            }
            else if (n < m - 1 && s[n + 1] == '.' && m1==-1){
                int mid, lo = 0, hi = vp.size() - 1;
                while (lo <= hi) {
                    mid = (lo + hi) / 2;
                    if (vp[mid].first >= n + 1 && vp[mid].second <= n + 1) break;
                    else if (vp[mid].first <= n + 1) lo = mid + 1;
                    else hi = mid - 1;
                }
                cnt--;
                m2 = mid;
                vp[mid].first=n;
            }
            s[n]=c;
            cout <<cnt<<en;
        }
        else {
            int m1=-1,m2=-1;
            if(s[n-1]=='.'){
                int mid, lo = 0, hi = vp.size() - 1;
                while (lo <= hi){
                    mid = (lo + hi) / 2;
                    if (vp[mid].first >= n-1 && vp[mid].second <= n-1) break;
                    else if (vp[mid].first <= n-1) lo = mid + 1;
                    else hi = mid - 1;
                }
                m1=mid;
                cnt++;
                vp[mid].second=n;
            }
            if(s[n+1]=='.'){
                int mid, lo = 0, hi = vp.size() - 1;
                while (lo <= hi){
                    mid = (lo + hi) / 2;
                    if (vp[mid].first >= n + 1 && vp[mid].second <= n + 1) break;
                    else if (vp[mid].first <= n + 1) lo = mid + 1;
                    else hi = mid - 1;
                }
                cnt++;
                m2=mid;
                vp[mid].first=n;
            }
            if (m1==m2 && m1!=-1){
                vp[m1].second=vp[m2].second;
                vp[m2].first=vp[m2].second=-1;
            }
            s[n]=c;
            cout <<cnt<<en;
        }
    }
    return 0;
}