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
int mod = 998244353;
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
 

 
 
 

 
 
 

 

 






   


 





bool IsPowerOfTwo(int x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}
const int maxm=2e5+7;
vector<map<int,int>>fac(maxm);
map<int,int>minpow;
int ans=0;
//fac[3]={3,1}
//fac[12]={3,1},{2,2}

void calc(){
    for(int i=2;i<maxm;i++){
        int temp=i;
        for(int j=2;j*j<maxm;j++){
            while(temp%j==0){
                temp/=j;
                fac[i][j]++;
            }
        }
        if(temp>1)
            fac[i][temp]++;
    }
}


int modInverse(int n){
    return binpow(n,mod-2,mod);
}





























void dfs(int node, vector<vector<pair<int,pair<int,int>>>>&adj,map<int,int>&val,int modval,int par){
    for(auto x : adj[node]){
        int next=x.first;
        pair<int,int>wt=x.second;
        if(next!=par){
            int newmodval=((modval*wt.first)%mod)*modInverse(wt.second)%mod;
            //simple modulo inverse i need add (4/2+4/7....)%mod 
            ans+=newmodval;
            ans%=mod;
            // now factors need not be prime like 4/2 so take lcm i need to consider  minpow for  2^2,2^-1
            for(auto x : fac[wt.first]){
                val[x.first]+=x.second;
            }
            for(auto x : fac[wt.second]){
                val[x.first]-=x.second;
                minpow[x.first]=min(minpow[x.first],val[x.first]);

            }
            dfs(next,adj,val,newmodval,node);
 
            //i need backtrack because for next  node val[c] will be different and i don't want to mix them up
            for(auto x : fac[wt.first]){
                val[x.first]-=x.second;
            }
            for(auto x : fac[wt.second]){
                val[x.first]+=x.second;
                

            }
        }
    }
    return;
}












void solve(){

int n;
cin>>n;
map<int,int>val;
minpow.clear();
vector<vector<pair<int,pair<int,int>>>>adj(n);
for(int i=0;i<n-1;i++){
    int a,b,ra,rb;
    cin>>a>>b>>ra>>rb;
    adj[a-1].pb({b-1,{rb,ra}});
    adj[b-1].pb({a-1,{ra,rb}});
}
ans=1;
dfs(0,adj,val,1,-1);
for(auto x : minpow){
    if(x.second<0){//it must be denominator
      ans*=binpow(x.first,-1*x.second,mod);
      ans%=mod;
    }
}
cout<<ans<<"\n";





}













 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int32_t main(){
 
init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
//SieveOfEratosthenes();
//BFS();
 calc();
while(t--){
 
solve();
 
}
   
return 0;
 
}
 
 
 
 
 
 //D. Potion Brewing Class
 //what did you learn ?
 // I learned that when modulo is involved in lcms we can't just directly write lcm fucntion 
 // be clever about it , how?
 //lcm =max(pow(p1))*max(pow(p2)*... so store their power after keeping prime factorization of all numbers<=n;
 // when there are n-1 connections think of treee
 //taking ratios sequencitially requires just 1:(a/b)^-1;
 
 
 
 
 
 
 
 
 