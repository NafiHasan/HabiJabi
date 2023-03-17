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
    
    string s;
    cin >>s;
    for (int i=0; i<s.size(); i++){
        if (s[i]%8==0){
            cout <<"YES\n"<<s[i]<<en;
            return 0;
        }
    }   
    if (s.size()>1){
        for (int i = 0; i < s.size() - 1; i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if ((s[i] * 10 + s[j]) % 8 == 0)
                {
                    cout << "YES\n"<< s[i] << s[j] << en;
                    return 0;
                }
            }
        }
    }
    if (s.size()>2){
        for (int i = 0; i < s.size() - 2; i++)
        {
            for (int j = i + 1; j < s.size() - 1; j++)
            {
                for (int k = j + 1; k < s.size(); k++)
                {
                    if ((s[i] * 100 + s[j] * 10 + s[k]) % 8 == 0)
                    {
                        cout << "YES\n"<< s[i] << s[j] << s[k] << en;
                        return 0;
                    }
                }
            }
        }
    }
    cout <<"NO\n";
    return 0;
}
