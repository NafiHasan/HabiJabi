#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

struct points
{
    int  ans;
    pair<int,int>minx;
    pair<int,int>miny;
    pair<int,int>maxx;
    pair<int,int>maxy;
    ;
};

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    w(t){
        int n;
        cin >>n;
        int ara[n][n];
        struct points p[10];
        map<int,int>mp;
        for (int i=0; i<10; i++){
            p[i].minx={INT_MAX,INT_MAX};
            p[i].maxx={0,0};
            p[i].miny={INT_MAX,INT_MAX};
            p[i].maxy={0,0};
        }
        for (int i=0; i<n; i++){
            string s;
            cin >>s;
            for (int j=0; j<n; j++){
                int x=s[j]-'0';
                mp[x]++;
                if (i<p[x].minx.first)p[x].minx={i,j};
                if (j<p[x].miny.second)p[x].miny={i,j};
                if (i>p[x].maxx.first)p[x].maxx={i,j};
                if (j>p[x].maxy.second)p[x].maxy={i,j};
            }
        }
        for (int i = 0; i < 10; i++)
        {
            int b=0,h=0;
            if (abs(p[i].minx.first-p[i].maxx.first)>abs(p[i].miny.second-p[i].maxy.second)){
                b = abs(p[i].minx.first - p[i].maxx.first);
                h = max(max(abs(p[i].minx.second-0),abs(p[i].minx.second-n+1)),max(abs(p[i].maxx.second-0),abs(p[i].maxx.second-n+1)));
                p[i].ans=b*h;
            }
            else {
                b = abs(p[i].miny.first - p[i].maxy.first);
                h = max(max(abs(p[i].miny.second - 0), abs(p[i].miny.second - n + 1)), max(abs(p[i].maxy.second - 0), abs(p[i].maxy.second - n + 1)));
                p[i].ans = b*h;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (mp[i]>1)cout << p[i].ans << " ";
            else cout <<"0 ";
            if (i==9){
                cout <<en<<p[i].minx.second<<" "<<p[i].miny.second<<" " <<p[i].maxx.second<<" "<<p[i].maxy.second<<en;
            }
        }
        cout << en;
    }   
    return 0;
}