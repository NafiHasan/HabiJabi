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
    
    w(t){
        int n,q;
        cin >>n>>q;
        string s;
        cin>>s;
        for(int i=0; i<q; i++){
            int l,r;
            cin >>l>>r;
            l--;
            r--;
            int len=r-l+1;
            bool ans=false;
            if (l>0){
                for (int j = 0; j < l; j++)
                {
                    if (s[j] == s[l])
                    {
                        ans = true;
                        break;
                    }
                }
            }
            for (int j=r+1; j<n; j++){
                if (s[j]==s[r]){
                    ans=true;
                    break;
                }
            }
            if (ans)cout <<"YES\n";
            else cout <<"NO\n";
        }
    }    
    return 0;
}