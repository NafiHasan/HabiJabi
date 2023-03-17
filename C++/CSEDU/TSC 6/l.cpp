#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >>n;
    vector<string>v(n);
    for (int i=0; i<n; i++)cin >>v[i];   
    int cnt=1;
    for (int i=1; i<n; i++){
        string a=v[i];
        bool found=false;
        for (int j=0; j<i && !found; j++){
            string cop = v[j];
            if (cop.size() == a.size()){
                for (int k = 0; k < cop.size(); k++)
                {
                    string b;
                    for (int l = k+1, cn = 1; cn <= cop.size(); cn++, l++)
                        b += a[l % cop.size()];
                    //cout << b << en;
                    if (b == cop)
                    {
                        found = true;
                        break;
                    }
                }
            }
        }
        if (!found)
            cnt++;
    }
    cout <<cnt<<en;
    return 0;
}