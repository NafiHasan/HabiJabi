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
        ll h,w,n;
        cin >>h>>w>>n;
        ll cnt=0,cnt1=1,cnt2=1, hh=h, ww=w;
        if (h%2==0){
            while (h % 2 == 0)
            {
                h /= 2;
            }
            cnt1 = (hh / h);
        }
        if(w%2==0){
            while (w % 2 == 0)
            {
                w /= 2;
            }
            cnt2 = (ww / w);
        }
        cnt=cnt1*cnt2;
        if (cnt==0)cnt++;
        //cout <<cnt<<en;
        if (cnt>=n)cout <<"yes\n";
        else cout <<"no\n";
    }
    return 0;
}