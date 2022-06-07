

D - Online games






#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define rep(i, n) for(int i = 0; i < n; ++i)
int main(void) {
	int n;
	int a, b;
	vector<pair<int, int> >x;
	int cnt;
	int ans[N];
	rep(i, N)ans[i] = 0;
	cin >> n;
	rep(i, n) {
		cin >> a >> b;
		x.push_back({ a,1 });
		x.push_back({ a + b,-1 });
	}
	sort(x.begin(), x.end());
	cnt = 0;
	rep(i, (x.size())-1) {
		cnt += x[i].second;
		ans[cnt] += ((x[i + 1].first) - (x[i].first));
	}
	rep(i, n - 1)cout << ans[i + 1] << " ";
	cout << ans[n] << endl;
	return 0;
}

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
int mod = 1e9+7;
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
 

const int N=1e6+10; 
 
 
vector<bool>primes(N+10);
 
 
void SieveOfEratosthenes()
{
  
   
 
    for (int p = 2; p * p <= N; p++)
    {
       
        if (primes[p] == true)
        {
          
            for (int i = p * p; i <= N; i += p)
                primes[i] = false;
        }
    }
 
 
   for(int i=2;i<=N;i++){
     if(primes[i]){
       primes.push_back(i);
 
       }
 
   }
 
            
}
 

 
  
 
 
//ll mul(ll a,ll b,ll m){return (((a%m)*(b%m))%m+m)%m;}
int add(int a,int b,int m){return ((a%m)+(b%m))%m;}
 
 
 

 
 















void solve(){

int n;
cin>>n;
map<int,int>mp;
int x,y;

rep(i,0,n){
    cin>>x>>y;
    mp[x]++;
    mp[x+y]--;
}

vector<int>ans(n+1,0);

int curr_k=0;
for(auto it=mp.begin();it!=mp.end();it++){
    pair<int,int>x=*it;
  // cout<<x.first<<" ";
     curr_k+=x.second;
    auto itn=it;
    itn++;
    if(itn!=mp.end()){
        int dis=(*itn).first;
        dis-=x.first;
        ans[curr_k]+=dis;
    }

}

for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
}





















    
}

























































 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int32_t main(){
 
init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
t=1;
//cin>>t;
//SieveOfEratosthenes();
//BFS();

while(t--){
 
solve();
 
}
   
return 0;
 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 