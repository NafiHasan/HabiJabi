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
        int n,k;
        cin >>n>>k;
        int ara[n];
        vector<int> v;
        map<int, int> m;
        for (int i=0;i <n;i ++){
            cin >> ara[i];
            if (m[ara[i]]==0){
                v.push_back(ara[i]);
                m[ara[i]]++;
            }
        }
        //for ( int i=0; i<v.size();i++)cout <<v[i]<<" ";
        int best=INT_MAX,cnt=0;
        for( int i=0; i< v.size(); i++){
            cnt=0;
            for(int j=0; j<n; ){
                if (ara[j]!=v[i]){
                    cnt++;
                    //cout << j << " "<<cnt<<en;
                    j+=k;
                    //cout << j << " ";
                }
                else j++;
            }
            best=min(cnt,best);
        }
        cout <<best<<en;
    }   
    return 0;
}