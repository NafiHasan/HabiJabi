#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n;
    cin >> n;
    ll sx,sy,ex,ey;
    cin >> sx >> sy >> ex >> ey;
    string s;
    cin >> s;
    ll no=0, so=0, we=0, ea=0;
    for (int i=0; i<n; i++){
        if (s[i]=='N')no++;
        else if (s[i] == 'S')so++;
        else if (s[i] == 'W') we++;
        else ea++;
    }
    ll x=ex-sx, y=ey-sy,t1=0,t2=0;
    if (x > 0){
        for (int i=0; i<n; i++){
            if (s[i] == 'E')
                x--;
            if (x==0){
                t1 = i+1;
                break;
            }
        }
    }
    else if (x < 0){
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'W')
                x++;
            if (x == 0)
            {
                t1 = i+1;
                break;
            }
        }
    }
    if (y > 0){
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'N')
                y--;
            if (y == 0){
                t2 = i+1;
                break;
            }
        }
    }
    else if (y<0){
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'S')
                y++;
            if (y == 0)
            {
                t2 = i+1;
                break;
            }
        }
    }
    if (x==0 && y==0) cout << max(t1,t2) << en;
    else cout << "-1\n";
    return 0;
}