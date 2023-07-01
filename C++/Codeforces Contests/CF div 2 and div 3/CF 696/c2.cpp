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
        int n;
        cin >>n;
        vector<int>a(2*n);
        for(int i= 0; i<2*n; i++)cin >>a[i];
        sort (a.begin(), a.end());
        bool done=false;
        for(int i=0; i< 2*n-1; i++){
            multiset<int>s;
            bool found=true;
            vector<pair<int, int>> ans;
            for (int k=0; k<2*n; k++)s.insert(a[k]);
            int now = a[2*n-1];
            s.erase(s.find(now));
            s.erase(s.find(a[i]));
            for (int j=1; j<n; j++){
                int last=*prev(s.end());
                int fin=now-last;
                //cout <<last<<" ";
                s.erase(s.find(last));
                if (s.find(fin)!=s.end()){
                    s.erase(s.find(fin));
                    ans.push_back({last,fin});
                    now=max(last,fin);
                    //cout<<now<<" ";
                }
                else {
                    found=false;
                    break;
                }
            }
            if (found){
                cout <<"YES\n";
                cout <<a[i]+a[2*n-1]<<en;
                cout <<a[i]<<" "<<a[2*n-1]<<en;
                for (int k=0; k<ans.size(); k++)cout <<ans[k].first<<" "<<ans[k].second<<en;
                done=true;
                break;
            }
        }
        if (!done)cout <<"NO\n";
    }   
    return 0;
}