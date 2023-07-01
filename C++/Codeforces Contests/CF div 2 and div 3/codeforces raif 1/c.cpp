#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    w(t){
        string s;
        cin >>s;
        int cnt=0,cntb=0;
        for (int  i=0; i<s.size(); i++){
            if (s[i]=='A')cnt++;
            else if (s[i]=='B' && cnt>0)cnt--;
            else cntb++;
        }
        cout <<(cnt+(cntb%2))<<endl;
    }
    return 0;
}