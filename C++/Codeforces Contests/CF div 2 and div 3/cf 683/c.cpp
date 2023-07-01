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
        int n;
        ll w;
        cin >>n>>w;
        ll lim;
        if (w%(ll)2 ==0)lim=w/2;
        else lim=w/(ll)2+(ll)1;
        vector <pair<ll,int>>vp;
        for (int i=0;i <n; i++){
            ll x;
            cin >>x;
            vp.push_back(make_pair(x,i+1));
        }
        vector<int>ind;
        ll tot=0;
        sort (vp.rbegin(), vp.rend());
        //for (int i=0; i<n; i++)cout <<vp[i].first<<" ";
        for (int i=0; i<n; i++){
            if ((tot+vp[i].first)<=w ){
                tot += vp[i].first;
                ind.push_back(vp[i].second);
                if(tot>=lim){
                    i=n;
                    break;
                }
            }
            //else if ((tot+vp[i].first)>w)break;
        }
        if (ind.size()==0 || tot<lim)cout <<"-1\n";
        else {
            cout<<ind.size()<<en;
            for (int i=0; i<ind.size(); i++)cout <<ind[i]<<" ";
            cout <<en;
        }
    }   
    return 0;
}