#include <bits/stdc++.h>
using namespace std;
#define int long long int

#define ff first
#define ss second
#define vect vector
#define pb push_back
#define wgr vector<pair<int, int>>
#define lowestbit(x) __builtin_ffs(x)  //returns 1+index of(lowest bit)
#define highestbit(x) __builtin_clz(x) //returns number of 0's to left of MST
#define is(x) cerr << #x << " is " << x << endl;
#define sortv sort(v1.begin(), v1.end());
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define inputarr loop(i, 0, n) cin >> ar[i];
int md = 998244353;
int inf = 1e18;

void init_code(){
     #ifndef ONLINE_JUDGE
     freopen("input1.txt","r",stdin);
     freopen("output1.txt","w",stdout);
     #endif
}
 
 
 
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
long long binpow1(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 





 
 
//ll mul(ll a,ll b,ll m){return (((a%m)*(b%m))%m+m)%m;}
int add(int a,int b,int m){return ((a%m)+(b%m))%m;}




int lent(int num){
    int cnt=0;
    while(num){
        num/=10;
        cnt++;
    }
    return cnt;
}

set <int>dig(int num){
    set<int>v;
    while(num){
        int k=num%10;
        v.insert(k);
        num/=10;
      
    }
    return v;

}

int n,m,K,S,t,X;

vector<vector<int>>adj;
int dp[2002][2002][2];
int rec(int level,int node,int mod)
{
  if(level==K)
  {  
    if(node==t && mod==0)
    {
      return 1;
    }
    else return 0;
  }
 
  if(dp[level][node][mod]!=-1) return dp[level][node][mod];
  int ans=0;
 
  for(auto u: adj[node])
  {
    ans=(ans+rec(level+1,u,(mod+(u==X))%2))%md;
  }
 
  return dp[level][node][mod]=ans;
}













 

void solve(){


cin>>n>>m>>K>>S>>t>>X;
adj.resize(n+1);
  memset(dp,-1,sizeof(dp));
rep(i,0,m){
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
}
int ans=0;

    ans=rec(0,S,0);

cout<<ans<<"\n";










}






 
int32_t main(){
 
init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
t=1;



while(t--){
 
solve();
 
}
   
return 0;
 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 








 




 
 
 
 
 
 
 
 
 
 
 
 
 