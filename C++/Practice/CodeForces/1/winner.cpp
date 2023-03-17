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
    
    int n,best=0;
    cin >>n;
    map<string,int>m;
    string ans;
    vector <string>vs;
    vector <pair<int,string>>vp;
    for (int i=0; i<n; i++){
        string s;
        int x;
        cin >>s>>x;
        m[s]+=x;
        vs.push_back(s);
        vp.push_back(make_pair(m[s],s));
    }  
    for (int i=0; i<vs.size(); i++){
        best=max(best,m[vs[i]]);
    }
    for (int i=0; i<vp.size(); i++){
        if (vp[i].first>=best && m[vp[i].second]==best){
            ans=vp[i].second;
            break;
        }
    }
    cout <<ans<<en;
    return 0;
}