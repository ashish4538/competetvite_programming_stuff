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
 
 
int mat[105][5];

int go(vector<int>&v){
   int ans = 1;
    int n = v.size();
    vector < int > d(n, 1);
    for(int i = 1; i < n; ++i) {
        int mmax = -1;
        for(int j = 0; j < i; ++j) {
            if(v[j] < v[i] && (mmax == -1 || d[mmax] < d[j])) {
                mmax = j;
            }
        }
        if(mmax != -1) 
            d[i] += d[mmax];
        ans = max(ans, d[i]);
    }
    return ans;

}







void solve(){

int c,n;
cin>>c>>n;
int t=n*c;
vector<int>color(t),values(t);
rep(i,0,t){
    cin>>color[i];
    cin>>values[i];
}
vector<int>ind;
rep(i,0,c){
    ind.pb(i);
}
int mi=INT_MAX;
vector<int>v(t);
do {
    int cnt=0;
    rep(i,0,c){
        rep(j,0,n){
            mat[ind[i]][j]=cnt++;//assigning the position to differnt colors

        }
    }
    rep(i,0,t){
        v[i]=mat[color[i]-1][values[i]-1];//making the pos array according the permutaion of colors

    }
    mi=min(mi,t-go(v));
}while(next_permutation(ind.begin(),ind.end()));


cout<<mi<<"\n";













 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int32_t main(){
 
init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
//cin>>t;
t=1;
//SieveOfEratosthenes();
//BFS();
 
while(t--){
 
solve();
 
}
   
return 0;
 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 