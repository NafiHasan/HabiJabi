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
        int a,b;
        cin >>a>>b;
        string s;
        cin >>s;
        int start=-1,cnt=0,ans=0;
        for (int i=0; i<s.size(); i++){
            if (start==-1 && s[i]=='1')start=i;
            if (start>-1 && s[i]=='0')cnt++;
            else if (start>-1 && s[i]=='1'){
                if (ans==0){
                    ans+=min(2*a,cnt*b+a);
                }
                else{
                    ans += min(2 * a, cnt * b + a);
                    ans-=a;
                }
                cnt=0;
            }
        }
        cout <<ans<<en;
    }
    return 0;
}