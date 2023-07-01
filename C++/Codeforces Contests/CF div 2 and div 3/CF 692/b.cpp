#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    w(t){
        string s;
        cin >>s;
        ll num=stoll(s);
        bool found=false;
        int dig[10];
        while(!found){
            memset(dig, 0, sizeof(dig));
            int got = 1;
            for (int i=0; i<s.size(); i++){
                dig[s[i]-'0']=1;
            }
            for(ll i=2; i<=9; i++){
                if (num%i!=0 && dig[i]==1){
                    num++;
                    s=to_string(num);
                    got=0;
                    break;
                }
            }
            if (got==1)found=true;
        }
        cout <<num<<en;
    }
    return 0;
}