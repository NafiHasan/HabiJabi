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
    
    string s1,s2;
    cin >>s1>>s2;
    int start;
    for (int i=0; i<s1.size(); i++){
        if (s1[i]-'0'<10){
            start=i;
            break;
        }
        if (s1[i]<s2[i]){
            cout <<"<\n";
            return 0;
        }
        else if (s1[i]>s2[i]){
            cout <<">\n";
            return 0;
        }
    }
    //cout <<"start "<<start<<en;
    int num1=0,num2=0;
    int len1=s1.size()-start;
    int len2=s2.size()-start;
    if (len1<len2){
        cout <<"<\n";
        return 0;
    }
    else if (len1>len2){
        cout <<">\n";
        return 0;
    }
    else {
        for (int i=start; i<s1.size(); i++){
            if (s1[i]-'0'<s2[i]-'0'){
                cout << "<\n";
                return 0;
            }
            else if(s1[i]-'0'>s2[i]-'0'){
                cout << ">\n";
                return 0;
            }
        }
    }
    cout <<"=\n";
    return 0;
}