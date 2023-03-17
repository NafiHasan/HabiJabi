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
        int cnt=0;
        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                int dis=abs(a[i]-a[j]);
                if (m[dis]==0){
                    cnt++;
                    m[dis]++;
                }
            }
        }
        cout <<cnt<<en;
    }   
    return 0;
}