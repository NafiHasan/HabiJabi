#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >>n;
    while(n--){
        string s; cin >>s;
        bool foundc=0;
        int cnt=0;
        for(int i=2; i<s.size(); i++){
            if(s[i]=='C'){
                foundc = 1;
                cnt=i;
                break;
            }
        }
        if(s[0] =='R' && ((s[1]-'0') <=9) && foundc==1){
            string num;
            for(int i=1; s[i]!='C'; i++){
                num+=s[i];
            }
            int nm= stoi(num);
            //cout <<nm<<en;
            num.clear();
            for(int i=cnt+1; i<s.size(); i++){
                num+=s[i];
            }
            int col=stoi(num);
            string ans;
            //cout<< "col "<<col<<en;
            while (col>0){
                col--;
                int rem = col%26;
                char c;
                c=rem+65;
                //else c='Z';
                ans+=c;
                //cout <<c<<en;
                //if (col==26)break;
                col/=26;
            }
            for(int i=ans.size()-1; i>=0; i--)cout <<ans[i];
            cout <<nm<< en;
        }
        else {
            string ans;
            for(int i=0; (s[i]-'0')>10; i++){
                ans+=s[i];
                cnt=i;
            }
            cout<<'R';
            for(int i=cnt+1; i<s.size(); i++)cout << s[i];
            int sz=ans.size(),num=0;
            int i=0;
            while(sz){
                num+=pow(26,sz-1)*(s[i++]-64);
                sz--;
            }
            cout << 'C' <<num<<en;
        }
    }
    return 0;
}