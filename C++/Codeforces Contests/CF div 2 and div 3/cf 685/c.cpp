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
        string a,b;
        cin>>a>>b;
        sort (a.begin(), a.end());
        sort (b.begin(), b.end());
        bool ans=true;
        map<char, int> ma;
        map<char, int> mb;
        for (int i=0; i<n; i++){
            if (a[i]>b[i]){
                ans=false;
                break;
            }
            ma[a[i]]++;
            mb[b[i]]++;
        }
        //for(int i=0; i<v.size(); i++)cout <<v[i]<<" ";
        if(ans){
            for(char i='a'; i<= 'z'; i++){
                if ((mb[i]-ma[i])%k!=0){
                    ans=false;
                    break;
                }
            }
        }
        if (ans)cout <<"Yes\n";
        else cout <<"No\n";
    }   
    return 0;
}