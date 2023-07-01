#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    bool ys[500010];
    memset(ys, true, sizeof(ys));
    for (int i = 2; i * i <= 25000; i++)
    {
        if (ys[i] == true)
        {
            for (int j = i * i; j <= 25000; j += i)
                ys[j] = false;
            //cout <<i<<" ";
        }
    }
    w(t){
        int n;
        cin>>n;
        int ans[4];
        ans[0] = 1;
        for (int i = 2, j = 1 + n, k = 1; k < 4; i++)
        {
            if (i >= j && ys[i] == true)
            {
                ans[k++] = i;
                j = n + ans[k - 1];
            }
        }
        //int prime[500010];
        cout <<ans[2]*ans[1]<<en;
        //cout <<ans[2]<<" "<<ans[1]<<en;
    }   
    return 0;
}