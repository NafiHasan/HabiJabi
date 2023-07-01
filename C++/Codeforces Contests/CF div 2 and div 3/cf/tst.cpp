#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);
#define endl '\n';
int main()
{
    optimize();
    long long int x[1001], n, i, j, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int flag = 0;
        for (i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (x[i] == x[j] && i != j)
                {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 0)
            cout << "NO" << endl;
    }
    return 0;
}