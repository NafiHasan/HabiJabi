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
    
    int cs=1;
    w(t){
        int n,m;
        cin >>n;
        vector<char>v1def;
        vector<char>v2def;
        vector<char>v1at;
        vector<char>v2at;
        string s;
        for (int i=0; i<n; i++){
            cin.ignore();
            getline(cin,s);
            v1def.push_back(s[0]);
            v1at.push_back(s[s.size()-1]);
            cout <<s[0]<<" "<<s[s.size()-1]<<en;
        }
        cin >>m;
        for (int i=0; i<m; i++){
            cin.ignore();
            getline(cin,s);
            v2def.push_back(s[0]);
            v2at.push_back(s[s.size()-1]);
        }
        for (int i=0; i<v1def.size(); i++)cout <<v1def[i]<<" ";
        int ans=0;
        map<char,int>m1at;
        map<char,int>m1def;
        map<char,int>m2at;
        map<char,int>m2def;
        int anss=0;
        for (int i = 0; i < v2def.size(); i++)
            m2def[v2def[i]]++;
        for (int i=0; i<v1at.size(); i++){
            m1at[v1at[i]]++;
            if (m2def[v1at[i]]==0){
                ans=1;
                break;
            }
            else if (m2def[v1at[i]]<m1at[v1at[i]])anss=1;
        }
        if (ans==0){
            for (int i = 0; i < v1def.size(); i++)
                m1def[v1def[i]]++;
            for (int i = 0; i < v2at.size(); i++)
            {
                m2at[v2at[i]]++;
                if (m1def[v2at[i]] == 0)
                {
                    ans = 2;
                    break;
                }
                else if (m1def[v2at[i]]<m2at[v2at[i]] && anss==0)anss=2;
            }
        }
        if (ans==1)cout <<"player 1\n";
        else if (ans==2)cout <<"Player 2\n";
        else if (ans==0 && anss==1)cout <<"player1\n";
        else cout <<"plaer 2\n";
    }   
    return 0;
}