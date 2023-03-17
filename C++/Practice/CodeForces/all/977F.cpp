#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n;
    cin >> n;
    vector<int>v;
    vector<int> ind[100005];
    map<int,int>m;
    for(int i=0 ; i<n; i++){
        int x;
        cin >> x;
        ind[x].push_back(i+1);
        if(m[x] == 0){
            m[x]++;
            v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    int cnt=1, best=1, start=v[0], cur=v[0];
    for(int i=1; i<v.size(); i++){
        if(v[i]== v[i-1]+1){
            for(int j=0; j<ind[v[i-1]].size(); j++){
                for(int k=0; k<ind[v[i]].size(); k++){
                    if(ind[i-1][j]<ind[i][k]){
                        j=ind[v[i-1]].size();
                        cnt++;
                        break;
                    }
                }
            }
        }
        else {
            cnt=1;
            //cout << m[v[i]]<< "t ";
            cur=v[i];
        }
        if(cnt>best){
            best=cnt;
            start = cur;
        }
    }
    //cout << start<< en;
    cout << best << "\n" ;
    //for(int i=start , j=1; j<=best; i++,j++)cout << m[i]<< " ";
    cout << "\n";
    return 0;
}