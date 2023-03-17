#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    w(t){
        int n;
        cin >>n;
        int ara[n];
        for (int i=0; i<n; i++)cin >>ara[i];

        int log[n + 1];
        log[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            log[i] = log[i / 2] + 1;
        }
        int K = log[n] + 1;
        int st[n + 1][K];
        for (int i = 0; i < n; i++)
            st[i][0] = ara[i]; 

        for (int i = 1; i <= K; i++)
        {
            for (int j = 0; (j + (1 << i)) <= n; j++)
                st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        }
        vector<char>ch;
        for (int L = 0; L < n; L++)
        {
            vector<int>v;
            for (int R=0; (R+L)< n; R++){
                int i = R, j=i+L;
                int len = log[j - i + 1];
                v.push_back(min(st[i][len], st[j - (1 << len) + 1][len])); 
                //cout <<min(st[i][len], st[j - (1 << len) + 1][len])<<en;
            }
            sort(v.begin(), v.end());
            bool found=true;
            for (int i=0; i<v.size(); i++){
                if (v[i]!=i+1)found=false;
            }
            if (found)ch.push_back('1');
            else ch.push_back('0');
        }
        for (int i=0; i<ch.size(); i++)cout <<ch[i];
        cout <<en;
    }   
    return 0;
}