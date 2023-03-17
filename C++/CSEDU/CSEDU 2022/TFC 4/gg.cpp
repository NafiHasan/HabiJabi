#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define pb push_back
#define PI acos(-1.0)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sdbl(n) scanf("%lf",&n)
#define sstr(s) scanf("%s",s)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define SP(n) cout << fixed << setprecision(n)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define lcm(a,b) (max((a),(b))/__gcd((a),(b)))*min((a),(b))
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
#define gamma 0.5772156649015328606065120
#define dbg(a) cout << "->" << __LINE__ << ": " << #a << " = " << a << endl
#define PY printf("YES\n")
#define PN printf("NO\n")

ll setBit(ll mask, int p){ return (mask | (1 << p)); }
ll resetBit(ll mask, int p){ return (mask & ~(1 << p)); }
ll flipBit(ll mask, int p){ return (mask ^ (1 << p)); }
bool check(ll mask, int p){ return (mask & (1 << p)); }

int msb(long long N){ return N ? 63 - __builtin_clzll(N): -1; }
int lsb(long long N){ return __builtin_ffs(N) - 1;}
int countOn(ll mask){ return __builtin_popcountll(mask); }
int countOff(ll mask){ return msb(mask) - countOn(mask) + 1; }
ll bigmod(ll a, ll b, ll mod)
{
  a %= mod;
  ll ret = 1;
  while(b){
    if(b&1) ret = ret*a%mod;
    a = a*a%mod;
    b >>= 1;
  }
  return ret;
}
ll modInverse(ll a)
{
    return bigmod(a, MOD-2, MOD);
}
mt19937_64 mt_rnd_64(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) {
    return (mt_rnd_64() % (r-l+1)) + l;
}
/* four directions
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};*/
/* eight directions
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};*/
/*knight directions
int fx[]= {1, -1, 1, -1, 2, 2, -2, -2};
int fy[]= {2, 2, -2, -2, 1, -1, 1, -1};*/
/*ordered set stuff
ordered_set os;
how many values are less than x
int n = os.order_of_key(x);
if the numbers are in sorted order, what is the k'th number
int p = *os.find_by_order(k);*/
const int N = 209;
const int K = 2e4 + 9;
int dp[N][K];
int vis[N][K];
string ans;
int f(int n, int k)
{
    if(n<0 or k<0) return dp[n][k] = 0;
    if(!k) return dp[n][k] = 1;
    if(vis[n][k]) return dp[n][k];
    vis[n][k] = 1;
    int ok = 0;
    for(int i = 2; i<=n; i++)
    {
        int totSubstr = i*(i-1)/2;
        if(k<totSubstr) break;
        ok = f(n-i,k-totSubstr);
        if(ok) break;
    }
    return dp[n][k] = ok;
}
void make(int n, int k)
{
    if(!k)
    {
        string op(n,'(');
        string cls(n,')');
        ans = ans + op + cls;
        return;
    }
    for(int i = 2; i<=n; i++)
    {
        int totSubstr = i*(i-1)/2;
        if(k<totSubstr) break;
        if(dp[n-i][k - totSubstr])
        {
            //dbg(n-i);
            // dbg(k-totSubstr);
            string b = "()";
            int add = i-1;
            while(add--) ans+=b;
            ans+='(';
            make(n-i,k-i*(i-1)/2);
            ans+=')';
            //dbg(ans);
            return;
        }
    }
}
int main()
{
    int t, n, k;
    si(t);
    while(t--)
    {
        si(n);
        si(k);
        if(n%2 or ((n*(n-1))/2)<k)
        {
            printf("impossible\n");
            continue;
        }
        if(f(n/2,k-n/2)==1)
        {
            make(n/2,k-n/2);
            printf("%s\n",ans.c_str());
            int sz = ans.size();
            assert(sz==n);
            ans = "";
        }
        else
        {
            printf("impossible\n");
        }
    }
}
