#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        ll ara[50];
        memset(ara,-1,sizeof (ara));
        if (n>45)cout <<"-1\n";
        else if (n<10)cout <<n<<en;
        else {
            for (int i=1, j=10; j<=17; i++, j++){
                ara[j]=(ll) (i*10+9);
            }
            for (int i = 1, j = 18; j <= 24; i++, j++)
            {
                ara[j] = i * 100 + 89;
            }
            for (int i = 1, j = 25; j <= 30; i++, j++)
            {
                ara[j] = i * 1000 + 789;
            }
            for (int i = 1, j = 31; j <= 35; i++, j++)
            {
                ara[j] = i * 10000 + 6789;
            }
            for (int i = 1, j = 36; j <= 39; i++, j++)
            {
                ara[j] = i * 100000 + 56789;
            }
            for (int i = 1, j = 40; j <= 42; i++, j++)
            {
                ara[j] = i * 1000000 + 456789;
            }
            for (int i = 1, j = 43; j <= 44; i++, j++)
            {
                ara[j] = i * 10000000 + 3456789;
            }
            ara[45]=123456789;
            // for (int i=10 ,j=19; j<29; i++,j++)ara[j]=i*10+9;
            cout <<ara[n]<<en;
        }
    }
    return 0;
}