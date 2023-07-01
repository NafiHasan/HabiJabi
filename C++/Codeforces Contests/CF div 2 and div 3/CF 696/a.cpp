#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    w(t){
        int n;
        cin >>n;
        string s;
        cin >>s;
        int prev=0;
        int a[n];
        for (int i=0; i<s.size(); i++){
            if (i==0){
                a[i] = (s[i] - '0') + 1;
                prev=a[i];
            }
            else if (((s[i]-'0') +1) == prev){
                a[i]=s[i]-'0';
                prev=a[i];
            }
            else {
                a[i]=(s[i]-'0')+1;
                prev=a[i];
            }
        }
        for (int i=0; i<n; i++)cout <<a[i]-(s[i]-'0');
        cout <<"\n";
    }
    return 0;
}