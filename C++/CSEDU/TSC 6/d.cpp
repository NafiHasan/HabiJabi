#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        string s;
        cin >>s;
        int len;
        cin >>len;
        string make;
        bool ans=true;
        for (int i=0; i<s.size(); i++){
            if ((s[i]-'0')>9)make+=s[i];
            else {
                int hi=0;
                //cout <<"came";
                for (int j=i; (s[j]-'0')<=9; j++){
                    hi=j;
                }
                //cout <<hi<<en;
                string num=s.substr(i,hi-i+1);
                //cout <<num<<en;
                if (num.size()>6){
                    ans=false;
                    break;
                }
                int sl=stoi(num);
                char c=s[hi+1];
                for (int j=0; j<sl; j++)make+=c;
                i+=num.size();
            }
        }
        if (ans){
            if (make.size()<=len)cout << make << en;
            else
                cout << "unfeasible\n";
        }
        else
            cout << "unfeasible\n";
    }   
    return 0;
}