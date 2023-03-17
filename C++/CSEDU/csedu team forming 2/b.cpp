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
    
    string s1,s2;
    cin >>s1>>s2;
    char best=0;
    for (int i=0; i<s2.size(); i++){
        best=max(best,s2[i]);
    }
    int yes = 0,found=-1,cnt=0;
    string s=s1;
    vector <string>vs;
    sort (s.begin(),s.end());
    char bests1=s[s.size()-1];
    for (int i=0; i<s1.size(); i++){
        if (s1[i]==bests1)found=i;
        if (found>=0 && s1[i]>=best){
            cnt++;
            string tmp;
            tmp = s1.substr(found, cnt);
            vs.push_back(tmp);
        }
        if (found>=0 && s[i]<best){
            string tmp; 
            tmp=s1.substr(found,cnt);
            vs.push_back(tmp);
            cnt=0;
        }
    }
    string mx="a";
    for (int i=0; i<vs.size(); i++){
        mx=max(mx,vs[i]);
    }
    cout <<mx;
    for (int i=0; i<s2.size(); i++){
        if (s2[i]==best)yes=1;
        if (yes==1)cout <<s2[i];
    }
    cout <<endl;
    return 0;
}