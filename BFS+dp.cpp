#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pr pair<int,int>
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
/*int mod = 1e9 + 7;

int mx = -1;
ll mn = 1e18;
*/
int INF = 1e18;
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




vector<int>primes;


/*void SieveOfEratosthenes()
{
   memset(prime, true, sizeof(prime));
   
 
    for (int p = 2; p * p <= N; p++)
    {
       
        if (prime[p] == true)
        {
          
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }


   for(int i=2;i<=N;i++){
     if(prime[i]){
       primes.push_back(i);
 
       }

   }
 
            
}

*/




bool cmp(const pair<int,int> &a,
                   const pair<int,int> &b)
{ 
    if(a.ss==b.ss)return a.ff<b.ff;

       return a.ss>b.ss;
}





//ll mul(ll a,ll b,ll m){return (((a%m)*(b%m))%m+m)%m;}
//ll add(ll a,ll b,ll m){return ((a%m)+(b%m))%m;}



int digits(int n){
    int cnt=0;
    while(n>0){
     cnt++;
     n/=10;
    }
    return cnt;
}


int ceil1(int x,int y){
   
   return (x+y-1)/y;
}



unsigned int countS(int n)
{
    unsigned int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}


const int N=1e3+10;
vector<int> dis(N);
int mx = 0;
void BFS(){
dis[1] = 0;
    for(int i = 2; i < N; i++){
        dis[i] = INF;
    }
    
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int x = 1; x < N; x++){
            // cur -> cur + cur / x
            int nex = cur + cur / x;
            if(nex >= N) continue;
            int ndis = dis[cur] + 1;
            if(dis[nex] == INF){
                dis[nex] = ndis;
                q.push(nex);
            }
        }
    }
    
    rep(i,1,N){
        mx=max(mx,dis[i]);
    }
    


}



int dp[1005][1005];

void solve(){
    
int n,k;
    cin >> n >> k;
    
    if(k > mx * n) k = mx * n;
    
    vector<int> b(n),v(n);
    vector<int> w(n);
    
    rep(i,0,n){
        cin >> b[i];
        w[i] = dis[b[i]];
    }
    rep(i,0,n){
        cin >> v[i];
    }
    
    // k -> capacity
    // dp[ind][weight]
    vector<vector<int>> dp(n,vector<int>(k+1));
    
    dp[0][0] = 0;
    if(w[0] <= k){
        dp[0][w[0]] = v[0];
    }
    
    rep(i,1,n){
        rep(j,0,k+1){
            dp[i][j] = dp[i-1][j];
            if(j >= w[i]){
                dp[i][j]=max(dp[i][j] , v[i] + dp[i-1][j - w[i]]);
            }
        }
    }
    
    int ans = 0;
    rep(j,0,k+1){
        ans=max(ans, dp[n-1][j]);
    }
    
    cout << ans << "\n";










}






int32_t main(){

init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;

//SieveOfEratosthenes();
BFS();
while(t--){

solve();

}
   
return 0;

}


















