#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int mon, dep;
    double down, price;
    while(1){
        cin >> mon >> down >> price >> dep;
        if (mon <0)return 0;
        double d[dep];
        int mons[dep];
        map<int, double> m;
        for (int i=0; i<dep; i++){
            cin >> mons[i] >> d[i];
            m[mons[i]]=d[i];
        }
        double prev, val=price, ow=price;
        for (int i=0; i<=mon; i++){
            ow=price-(i*down);
            double r;
            if (m[i]>0.0)r=m[i];
            else r=prev;
            prev=r;
            val+=down;
            double paid=val*r;
            val-=paid;
            cout <<val<<" ";
            if (val>ow){
                string ans="months";
                if (i==1)ans="month";
                cout << i << " " << ans<< en;
                break;
            }
        }
    }
    return 0;
}