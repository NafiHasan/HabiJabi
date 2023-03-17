#include <bits/stdc++.h>
using namespace std;

#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long int
#define en "\n"

int main()
{
    // ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t)
    {
        int u;
        cin >> u ;
        for (int v=u; v<pow(2,31); v++){
            if (u>v)continue;
            if (u % 2 == 1)
            {
                if (__builtin_popcount(u) >= __builtin_popcount(v))
                    cout << v<<" ";
                else if (__builtin_popcount(v) == 1)
                    cout << v<<" ";
            }
            else if (u % 2 == v % 2 && u % 2 == 0)
            {
                int cnt1 = 0, cnt2 = 0;
                if (__builtin_popcount(u) >= __builtin_popcount(v))
                {
                    for (int i = 0; (1 << i) <= u; i++)
                    {
                        if ((1 << i) & u)
                            break;
                        else
                            cnt1++;
                    }
                    for (int i = 0; (1 << i) <= v; i++)
                    {
                        if ((1 << i) & v)
                            break;
                        else
                            cnt2++;
                    }
                    if (cnt2 >= cnt1 || __builtin_popcount(v) == 1)
                        cout << v<<" ";
                }
            }
        }
    }
    return 0;
}