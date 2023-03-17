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
        string s;
        cin >>s;
        int f=0,sec=0,cnt=0;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='(')f++;
            else if (s[i]=='[')sec++;
            else if (f>0 && s[i]==')'){
                f--;
                cnt++;
            }
            else if (sec>0 && s[i]==']'){
                cnt++;
                sec--;
            }
        }
        cout <<cnt<<en;
    }   
    return 0;
}