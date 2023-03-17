#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        int u,v;
        cin >>u>>v;
        if (u>v)cout <<"NO\n";
        else {
            vector<int>cnt1,cnt2;
            for (int i=0; (1<<i)<=u; i++) if ((1<<i)&u)cnt1.push_back(i);
            for (int i = 0; (1 << i) <= v; i++) if ((1 << i) & v) cnt2.push_back(i);
            bool ans=true;
            if (cnt1.size() < cnt2.size())ans=false;
            for (int i=0; i<cnt1.size(); i++){
                int ind=min(i,(int)cnt2.size()-1);
                if (cnt1[i]>cnt2[ind]){
                    ans = false;
                    break;
                }
            } 
            if (ans)cout << "YES\n";
            else cout << "NO\n";
        }
    }   
    return 0;
}