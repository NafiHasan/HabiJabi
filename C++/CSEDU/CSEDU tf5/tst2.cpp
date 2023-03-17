#include <bits/stdc++.h>
using namespace std;

#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    w(t)
    {
        int n, cnt = 0;
        cin >> n;
        int lim4 = n / 4 + 1, lim7 = n / 7 + 1;
        if (n % 4 == 0)
        {
            //cout << "Yes\n";
            cnt = 1;
        }
        else if (n % 7 == 0 && cnt == 0)
        {
            //cout << "Yes\n";
            cnt = 1;
        }
        if (cnt == 0)
        {
            for (int i = 1; i <= lim7; i++)
            {
                for (int j = 1; j <= lim4; j++)
                {
                    if (i * 7 + j * 4 == n)
                    {
                        cnt = 1;
                        cout <<i<<" "<<j<<en;
                        j = lim4 + 1;
                        i = lim7 + 1;
                    }
                    if (i * 7 + j * 4 > n)
                        j = lim4 + 1;
                }
            }

            if (cnt == 0)
                cout << n << " No\n";
        }
    }
    return 0;
}