#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        int a[n];
        for (int i=0; i<n; i++)cin >>a[i];
        map<int,int>m;
        for (int i=0; i<n; i++){
            if (m[a[i]]==0){
                m[a[i]]++;
            }
            else if (m[a[i]]>0){
                a[i]++;
                m[a[i]]++;
            }
        }
        map<int,int>c;
        int cnt=0;
        for (int i=0; i<n; i++){
            if (c[a[i]]==0){
                c[a[i]]++;
                cnt++;
            }
        }
        cout <<cnt<<en;
    }   
    return 0;
}