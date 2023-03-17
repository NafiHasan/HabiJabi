#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    // ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        string s;
        cin >>s;
        int a=0,b=0,c=0;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='A')a++;
            else if (s[i]=='B')b++;
            else c++;
        }
            char start=s[0],end=s[s.size()-1];
            string s1;
            for(int i=0; i<s.size(); i++){
                if (s[i]==start)s1+='(';
                else if (s[i]==end)s1+=')';
                else s1+='.';
            }
            bool ans=false,ok=true;
            string s2=s1;
            //cout << s1 << en;
            for (int i=0; i<s.size(); ++i){
                if (s1[i]=='.')s1[i]='(';
            }
            stack<int>st;
            for (int i=0; i<s.size(); i++){
                if (s1[i]=='(')st.push(1);
                else if (st.size())
                    st.pop();
                else ok=0;
            }
            //cout << s2 <<en;
            if (ok && st.empty())ans=true;
            for (int i=0; i<s.size(); i++)
                if (s2[i]=='.')s2[i]=')';
            stack<int>st2;
            ok=1;
            for (int i = 0; i < s2.size(); i++)
            {
                if (s2[i] == '(')
                    st2.push(1);
                else if (st2.size())
                    st2.pop();
                else ok=0;
            }
            if (ok && st2.empty())
                ans = true;
            //cout <<st.size() << " " <<st2.size()<<en;
            if (ans)cout <<"YES\n";
            else cout <<"NO\n";
    }   
    return 0;
}