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
int mod = 1e9 + 7;
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
 
 
 
 
 
int countOdd(int L, int R){
 
    int N = (R - L) / 2;
 
    // if either R or L is odd
    if (R % 2 != 0 || L % 2 != 0)
        N += 1;
 
    return N;
}
 
 
 map<pair<int,int>,int>dp;

int f(int curr,vector<int>a,int i){
    if(i==-1){
        if(curr==1)
            return 1;
        return 0;
    }
    pair<int,int> key={i,curr};
    if(dp.find(key)!=dp.end())return dp[key];
    return dp[key]=f(curr,a,i-1)+f(__gcd(curr,a[i]),a,i-1);
}




void solve(){
 int n;
 cin>>n;
 vector<int>a(n+1);
 rep(i,0,n){
    cin>>a[i];
 }
 dp.clear();
 cout<<f(0,a,n-1)<<"\n";
 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int32_t main(){
 
init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;

//SieveOfEratosthenes();
//BFS();
 
while(t--){
 
solve();
 
}
   
return 0;
 
}
 
 //AMSGAME2
 
 
 
 
 
 
 
 
 
 
 
 
 