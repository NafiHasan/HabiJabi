#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n;
    cin  >> n;
    vector<pair<int,int>>v(n);
    for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    //for(int i=0; i<n; i++)cout << v[i].first<< " " << v[i].second<<en;
    if(n==1){
        cout << "Poor Alex";
        return 0;
    }
    bool ans=false;
    for(int i=1; i<n; i++){
        if(v[i].second < v[i-1].second){
            ans=true;
            //cout << v[i].second << " " << v[i-1].second << en;
            break;
        }
    }
    if (ans)
        cout << "Happy Alex";
    else
        cout << "Poor Alex" ;
    return 0;
}