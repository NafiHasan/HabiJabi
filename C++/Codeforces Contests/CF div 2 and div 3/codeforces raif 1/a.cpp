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
        int n;
        cin >>n;
        string s;
        cin >>s;
        map<char,int>m;
        map<int,int>m1;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='-'){
                m1[i]++;
                int next=(i+1)%n;
                m1[next]++;
            }
            m[s[i]]++;
        }
        if (m['<']==0 || m['>']==0){
            cout <<n<<endl;
        }
        else {
            cout <<m1.size()<<endl;
        }
    }
    return 0;
}