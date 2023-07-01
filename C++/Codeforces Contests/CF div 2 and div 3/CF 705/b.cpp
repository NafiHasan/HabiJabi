#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define dbg(x) cout<<#x<<" = "<<x<<en
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
int mir(int t){
    int s=t%10;
    t/=10;
    int f=t%10;
    if (f==3 || f==4  || f==6 || f==7 || f==9)return -1;
    if (s==3 || s==4  || s==6 || s==7 || s==9)return -1;
    if (s==2)s=5;
    else if (s==5)s=2;
    if (f == 2)
        f = 5;
    else if (f == 5)
        f = 2;
    int ans=(s*10)+f;
    return ans;
}
int main()
{
    fast_io();
    w(t){
        int h, m;
        cin >> h>>m;
        string s;
        cin >>s;
        int hoo=s[0]-'0';
        hoo*=10;
        hoo+=s[1]-'0';
        int moo=s[3]-'0';
        moo*=10;
        moo+=s[4]-'0';
        bool ok=false;
        // cout << hoo <<" "<<moo<<en;
        int num=0;
        for (int i=moo; i<m; i++){
            if (mir(i)<h && mir(i)!=-1){
                ok=1;
                num = i;
                break;
            }
        }
        if (!ok)hoo++;
        int hour=0;
        ok=0;
        for (int i=hoo; i<h; i++){
            if (mir(i) < m && mir(i)!=-1)
            {
                ok = 1;
                hour=i;
                //cout << mir(i) << en;
                break;
            }
        }
        if (hoo!=hour)num=0;
        if (hour <=9)cout <<"0"<<hour<<":";
        else cout <<hour<<":";
        if (num <= 9)
            cout << "0" << num;
        else
            cout << num;
        cout <<en;
    }
    return 0;
}