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
        int r,c;
        string s;
        cin >>r>>c>>s;
        int right=0,left=0,down=0,up=0,hor=0,ver=0;
        int ans=0;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='>') {
                hor++;
                if (hor==0)hor++;
            }
            else if (s[i]=='<'){
                hor--;
                if (hor==0)hor--;
            }            
            else if (s[i]=='v'){
                ver--;
                if (ver==0)ver--;
            }
            else if (s[i]=='^') {
                ver++;
                if (ver==0)ver++;
            }
            if (abs(hor)==c){
                ans++;
                if (hor>0)hor--;
                else if (hor<0)hor++;
                //cout <<i<<en;
            }
            else if (abs(ver)==r){
                ans++;
                if (ver<0)ver++;
                else if (ver>0)ver--;
                //cout <<i<<en;
            }
            if (hor < 0)
                left = max(left, abs(hor));
            if (hor > 0)
                right = max(right, abs(hor));
            if (ver > 0)
                up = max(up, abs(ver));
            if (ver < 0)
                down = max(down, abs(ver));
        }
        int max_vert=up+down, max_hori=left+right;
        //cout <<max_vert<<" "<<max_hori<<en;
        if (max_vert>r)ans+=(max_vert-r);
        if (max_hori>c)ans+=(max_hori-c);
        cout <<ans<<en;
    }   
    return 0;
}