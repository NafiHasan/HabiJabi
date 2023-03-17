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
        int n, x;
        cin >> n >> x;
        priority_queue<pair<int,pair<int,int>>>v;
        priority_queue<pair<int,int>>dam;
        for(int i=0; i<n; i++){
            int a,b;
            cin >> a>> b;
            v.push({a-b,{a,b}});
            dam.push({a,b});
        }
        int cnt=0;
        while(v.size()){
            pair<int,pair<int,int>>p = v.top();
            pair<int,int>d= dam.top();
            if(p.first > x || d.first > x){
                cnt ++;
                break;
            }
            else {
                int a=
            }
        }
        if(x)cout << "-1\n";
        else cout << cnt<< "\n";
    }   
    return 0;
}