#include <bits/stdc++.h>
using namespace std;

#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long int
#define en "\n"
bool ans = false;
int cnt=0;
map<int, int> m;
void chk(int u, int v)
{
    //cout <<u<<" ";
    cnt++;
    if (u > v)
        return;
    if (u == v)
    {
        ans = true;
        return;
    }
    for (int i = 0; i < 31; i++)
    {
        if ((1 << i) > u)
        {
            //cout <<(1<<i) <<" b "<<u<<en;
            break;
        }
        if ((1 << i) & u)
        {
            //cout <<"left " <<(1<<i)<<en;
            if (m[u + (1 << i)] == 0)
            {
                m[u + (1 << i)]++;
                chk(u + (1 << i), v);
            }
            int a = ((1 << i) ^ u);
            //cout << "came " <<a << en;
            if (a != 0)
            {
                if (m[u + a] == 0)
                {
                    m[u + a]++;
                    chk(u + a, v);
                }
                //cout <<"after "<<p<<en;
            }
        }
    }
    if (m[u + u] == 0)
    {
        m[u + u]++;
        chk(u + u, v);
    }
    return;
}

int main()
{
    //ios::sync_with_stdio(false);
    cin.tie(NULL);
    w(t)
    {
        int u, v;
        cin >> u;
        for (int i=1; i<pow(2,15); i++){
            ans = false;
            m.clear();
            chk(u, i);
            if (u <= i && ans)
                cout << i<<" ";
        }
        cout << en;
        // else
        //     cout << "NO\n";
    }
    return 0;
}