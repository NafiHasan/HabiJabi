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
    
    int n;
    cin >>n;
    deque<int>d;
    vector<int>v;
    map<int,int>m;
    for (int i=0; i<n; i++){
        int x;
        d.push_back(x);
        m[x]++;
    }   
    int numm=0;
    for (int i=1; i<=101; i++){
        v.push_back(m[i]);
        numm=max(numm,i);
    }
    sort (v.rbegin(), v.rend());
    if (v.size()==1)cout <<"0\n";
    else {
        int ans=min(v[0],v[1]);
        if (v[1]!=v[0]){
            int cut=v[0]-v[1];
            m.clear();
            int mincut=INT_MAX;
            for (int i=0; i<n; i++){
                m[d[i]]++;
                if (d[i]==numm && m[d[i]]==cut){
                    mincut=min(mincut,i+1);
                    break;
                }
            }
            m.clear();
            for (int i = n-1; i >= 0; i++)
            {
                m[d[i]]++;
                if (d[i] == numm && d[v[i]] == cut){
                    mincut = min(mincut, i + 1);
                    break;
                }
            }
        }
        for (int i=1; i<v.size(); i++)ans+=v[i];
        cout <<ans<<en;
    }
    return 0;
}