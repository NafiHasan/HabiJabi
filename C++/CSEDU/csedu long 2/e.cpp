#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    int n,start=0;
    cin >>n;
    int last=0,l=1,best=n;
    string s;
    cin >>s;
    map <char,int>m;
    map <char,int>m2;
    //m[s[0]]++;
    if (n==1){
        cout <<"1\n";
        return 0;
    }
    for (int i=0; i<n; i++){
        char c=s[i];
        m2[c]++;
    }
    int lim=n-m2.size(),cnt=1;
    while(start<=lim){
        m[s[last]]++;
        if (s[last]==s[start] && last>start){
            m[s[start]]--;
            start++;
        }
        if (m[s[start]]>1){
            while(m[s[start]]>1){
                m[s[start]]--;
                start++;
            }
        }
        if (m.size()==m2.size() && (last-start+1)>=m2.size()){
            best=min(best,(last-start+1));
        }
        if (last!=n-1)last++;
        else if (last==n-1){
            m[s[start]]--;
            if (m[s[start]]>1)start++;
            else break;
        }
    } 
    cout <<best<<endl;
    return 0;
}