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
        int j=0;
        vector<pair<int,int>>vp;
        int num = n;
        if (num<=8){
            for (int i = 3; i < num; i++)
            {
                vp.push_back({i, i + 1});
            }
        }
        else {
            for (int i=3; i<7; i++)vp.push_back({i,i+1});
            vp.push_back({7,9});
            for (int i=9; i<n; i++)vp.push_back({i,i+1});
        }
        while (n != 1 && num > 8)
        {
            vp.push_back({num, 8});
            if (n % 8 != 0)
            {
                n /= 8;
                n++;
            }
            else
                n /= 8;
        }
        if (num > 8)
        {
            vp.push_back({8, 2});
            vp.push_back({8, 2});
            vp.push_back({8, 2});
        }
        while(num<=8 && n!=1){
            vp.push_back({num,2});
            if (n%2==0)n/=2;
            else {
                n/=2;
                n++;
            }
        }
        cout <<vp.size()<<en;
        for (int i=0; i<vp.size(); i++)cout <<vp[i].first<<" "<<vp[i].second<<en;
    }   
    return 0;
}