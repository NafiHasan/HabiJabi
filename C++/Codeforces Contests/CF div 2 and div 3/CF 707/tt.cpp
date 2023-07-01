#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
    #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    #endif
}
int n, T, pro, a[5000005], b[5000005], c[5000005];
 
int main(){
    fast_io();
    file_io();
    cin >> n;
    int cnt=0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int pro = a[i] + a[j];
            if(!b[pro]) b[pro] = i, c[pro] = j;
            else{
                if(b[pro] != i && c[pro] != j && b[pro] != j && c[pro] != i){
                    printf("YES\n%d %d %d %d\n", i, j, b[pro], c[pro]);
                    return 0;
                }
            }
            cnt++;
        }
    }
    cout << cnt << en;
    puts("NO");
    return 0;
}