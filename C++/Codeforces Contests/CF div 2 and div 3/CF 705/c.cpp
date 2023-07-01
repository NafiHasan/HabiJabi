#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define dbg(x) cout<<#x<<" = "<<x<<en
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 

int main()
{
    fast_io();
    w(t){
        int n,k;
        cin >>n>>k;
        string s;
        cin >>s;
        if (n%k!=0)cout <<"-1\n";
        else {
            int cnt=0;
            map<char,int>mm;
            for (int i=0; i<s.size(); i++){
                if (mm[s[i]]==0){
                    cnt++;
                    mm[s[i]]++;
                }
            }
            char c1=s[0],c2;
            int pos=0;
            for (int i=1; i<s.size(); i++){
                if (s[i]!=c1){
                    c2=s[i];
                    pos=i;
                    break;
                }
            }
            if (cnt>2){
                for (int i = 1; i < s.size(); i++)
                {
                    if (s[i] != c2 && s[i]!=c1 && s[i]>c2)
                    {
                        c2++;
                        break;
                    }
                }
            }
            if (c1>c2){
                for (int i=0; i<pos; i++)s[i]=c1;
                int done=pos;
                int end=s.size()-1;
                for (int i=s.size()-1; i>pos && done%k; i--){
                    if (done%k==0)break;
                    s[i]=c1;
                    // cout <<s[i] << " " << c1 <<en;
                    done++;
                    end=i;
                }
                for (int i=pos; i<end;  i++)s[i]=c2;
                cout << s << en;
            }
            else {
                int done=k-1,end=s.size()-1;
                for (int i=s.size(); i>pos && done; i--){
                    s[i]=c2;
                    done--;
                    end=i;
                }
                for (int i=0; i<end; i++)if (i!=pos)s[i]=c1;
                cout <<s<<en;
            }
        }
    }
    return 0;
}