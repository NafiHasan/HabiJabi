#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    // ios::sync_with_stdio(false);  cin.tie(NULL);
    int n,b, h, w;
    while((cin >> n>> b >> h >> w)){
        bool ans = true;
        int sum = 0, mn=INT_MAX;
        while(h--){
            sum=0;
            ans=0;
            int hot;
            cin >> hot;
            int hotels[w];
            for (int i = 0; i < w; i++)
                cin >> hotels[i];
            for (int i = 0; i < w; i++)
            {
                if (hotels[i] >= n)
                    ans = 1;
            }
            sum=n*hot;
            if (ans)
                mn = min(mn, sum);
        }
        if (mn <= b)
            cout << mn << en;
        else
            cout << "stay home\n";
    }
    return 0;
}