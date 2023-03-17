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
    
    int n,cnt=0;
    cin >>n;
    string s1,s2;
    cin >>s1>>s2;
    map<pair<char,char>,int>mp;
    map<char, int> m3;
    for (int i=0; i<n; i++){
        if (s1[i]!=s2[i]){
            pair<char,char> p;
            p=make_pair(s1[i],s2[i]);
            mp[p]++;
            cnt++;
            m3[s1[i]]++;
        }
    }   
    if (cnt==1){
        cout <<"1\n-1 -1\n";
        return 0;
    }
    char c1=0,c2=0;
    int x1,y1;
    for (int i=0; i<n; i++){
        pair<char,char>pp;
        pp=make_pair(s2[i],s1[i]);
        if (mp[pp]>0){
            c1=s1[i];
            c2=s2[i];
            x1=i;
            break;
        }
    }
    if (c1 && c2){
        for (int i=0; i<n; i++){
            if (s1[i]==c2 && i!=x1){
                y1=i;
                break;
            }
        }
        cout << cnt - 2 << en;
        cout << min(x1 + 1, y1 + 1) << " " << max(x1 + 1, y1 + 1) << en;
        return 0;
    }
    int x,y;
    char c=0;
    for (int i=0; i<n; i++){
        if (m3[s2[i]]>0 && s1[i]!=s2[i]){
            x = i;
            c = s2[i];
            //cout <<c<<en;
            break;
        }
    }
    if (c>0){
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == c && i != x && s1[i]!=s2[i])
            {
                y = i;
                //cout <<y<<en;
                break;
            }
        }
        cout <<cnt-1<<en;
        cout <<min(x+1,y+1)<<" "<<max(x+1,y+1)<<en;
        return 0;
    }
    cout << cnt << en;
    cout << "-1 -1"<< en;
    return 0;
}