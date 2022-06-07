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
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define inputarr loop(i, 0, n) cin >> ar[i];
/*int mod = 1e9 + 7;
ll inf = 1e18;
int mx = -1;
ll mn = 1e18;
*/

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

 
const int N=1e5+1;
 bool prime[N+10];


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
    if(a.ff==b.ff)return a.ss>b.ss;

       return a.ff<b.ff;
}





//ll mul(ll a,ll b,ll m){return (((a%m)*(b%m))%m+m)%m;}
//ll add(ll a,ll b,ll m){return ((a%m)+(b%m))%m;}





void solve(){
    

int m,n;
cin>>m>>n;
string lex="abcdefghijklmnopqrstuvwxyz";
int len=(int)lex.size()
string b;
for(int i=1;i<=m;i++){
   int k=i%len;
   k--;
   b[i-1]=lex[k];
}

string s;
cin>>s;
map<char,set<int>>mp;
for(int i=0;i<n;i++){
    mp[s[i]].insert(i);
}

bool poss=true;
int work=0;
int curr;
if(mp['a'].size()){

curr=*mp['a'].begin();
}

else{
  cout<<-1<<"\n";
    return;
}


for(int i=1;i<m;i++){
   
if(mp[b[i]].size()){
      int it=mp[b[i]].begin();

      while(it!=mp[b[i].end() or (*it) < curr ) {
        it++;
      
      if(it!=mp[b[i]].end()){
        work+=(curr-(*it));
        curr=*it;
      }
      else{
        poss=false;
        break;
      }

   }
   
}

cout<<work<<"\n";


















}










 



  

    







int32_t main(){

init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;

//SieveOfEratosthenes();
while(t--){

solve();

}
   
return 0;

}


















