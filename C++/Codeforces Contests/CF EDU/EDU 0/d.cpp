#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define rep(i,a,n) for (int i=a; i<n; i++)
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    w(t){
        int n,cnt=0;
        cin >>n;
        string s;
        cin >>s;
        while(s.size()>0){
                int l=s.size(),done=0;
                if (l>=2 && s[0]!=s[1]){
                    for (int i=1; i<s.size(); i++){
                        if (s[i]==s[i-1]){
                            s.erase(s.begin()+i);
                            done=1;
                            i=s.size();
                        }
                    }
                    if (done==0)s.erase(s.begin()+(l-1));
                    s.erase(s.begin()+0);
                    cnt++;
                }
                else if (l>=2 && s[0]==s[1]){
                    char c=s[0];
                    cnt++;
                    int j=0;
                    while(s[j]==c){
                        s.erase(s.begin()+0);
                        if (s.size()==0)break;
                    }
                    // for (int i=0; i<v.size(); i++) cout <<v[i];
                    // cout <<endl;
                }
                else {
                    s.empty();
                    cnt++;
                    break;
                }
        }
        cout <<cnt<<endl;
    }
    return 0;
}