#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        int a[n];
        for (int i=0; i<n; i++)cin >>a[i];
        int ind[n];
        memset(ind,-1, sizeof (ind));
        int mx=a[0],j=0, start=0;
        for (int i=1; i<n; i++){
            if (a[i]>mx){
                ind[j++]=i-1;
                mx=a[i];
                start=i;
            }
        }
        ind[j]=n-1;
        // for (int i=0; i<n; i++)cout <<ind[i]<<" ";
        // cout <<en;
        vector<int>v;
        map<int,int>m;
        for (int i=0; i<n ;i++){
            if ((i<n-1 && ind[i+1]==-1) || i==n-1){
                for (int k = ind[i]; k>=0; k--){
                    if (m[a[k]]==0){
                        v.push_back(a[k]);
                        m[a[k]]++;
                    }
                    else break;
                }
                break;
            }
            else {
                for (int k=ind[i]; k>=0; k--){
                    if (m[a[k]]==0){
                        v.push_back(a[k]);
                        m[a[k]]++;
                    }
                    else break;
                }
            }
        }
        for (int i=v.size()-1; i>=0; i--)cout <<v[i]<<" ";
        cout <<en;
    }
    return 0;
}