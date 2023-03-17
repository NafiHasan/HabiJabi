#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"

double time(string s){
    double num=10*(s[0]-'0')+(s[1]-'0')*3600;
    num+=((10*(s[3]-'0')+(s[4]-'0'))*60);
    num+=((10*(s[6]-'0')+(s[7]-'0')));
    return num;
}

int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    vector <double>vt;
    double sum=0;
    int ind=0;
    string s;
    double speed=0;
    double curnt_time=0;
    while (getline(cin, s))
    {
        double ti=time(s);
        vt.push_back(ti);
        if (s.size()>8){
            sum+=speed*(ti-curnt_time);
            vector<double>sp;
            for (int i=9; i<s.size(); i++){
                double x=s[i]-'0';
                sp.push_back(x);
            }
            int len=sp.size(),num=0;
            for (int i=0; i<len; i++){
                num+=(double)sp[i]*pow(10,(len-i-1));
            }
            speed=num;
            speed/=3600;
        }
        else {
            cout <<s<<" ";
            sum+=(speed*(ti-vt[ind-1]));
            printf("%.2lf km\n",sum);
        }
        ind++;
        curnt_time=ti;
    }
    return 0;
}