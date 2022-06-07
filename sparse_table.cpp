#include <bits/stdc++.h>
using namespace std;

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
    if(a.second==b.second)return a.first<b.first;

       return a.second<b.second;
}





//ll mul(ll a,ll b,ll m){return (((a%m)*(b%m))%m+m)%m;}
//ll add(ll a,ll b,ll m){return ((a%m)+(b%m))%m;}



void solve(){

int n;
cin>>n;
vector<int>a(n+1);
vector<vector<int>>table(n+1,vector<int>(21));//sparse table 
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){
    cin>>a[i];

}
for(int i=1;i<=n;i++){
    table[i][0]=a[i];
}


 for(int j=1;j<=20;j++){
    for(int i=1;i+(1<<j)<=n+1;i++){
        table[i][j]=__gcd(table[i][j-1],table[i+(1<<(j-1))][j-1]);
    }
 }


vect<pair<int,int>>segs;
for(int i=1;i<=n;i++){
    int l=i,r=n,ans=-1;//[i,mid] is problematic subarray
    //binary search on range gcd 
    // o e|o o |o o|e o o o| o o o
    //if two range are problematic so their gcd=len and if they are overlapping they should be together.
    while(l<=r){//binary search for r value l is fixed
        int mid=(l+r)/2;
        int rangeL=i;
        int rangeR=mid;
        int val=a[rangeL];
         for(int j=20;j>=0;j--){//this loop here is breaking the ranges into power of two and adding them up
            if((1<<j)<=rangeR-rangeL+1){
                val=__gcd(val,table[rangeL][j]);
                rangeL+=(1<<j);
            }
         }
         if(val==mid-i+1){//range GCD= length of subarray=>problematic
            ans=mid;
            break;
         }
         else if(val>mid-i+1){
            l=mid+1;
         }
         else{
            r=mid-1;
         }
    }
    if(ans!=-1){
        segs.push_back({i,ans});
    }
}

sort(segs.begin(),segs.end(),cmp);
vector<int>ans(n+1);
int smallestR=-1;
set<int>incs;

for(int i=0;i<(int)segs.size();i++){
    int l=segs[i].ff;
    int r=segs[i].ss;
    if(l<smallestR && smallestR<=r){
        continue;
    }
    smallestR=r;
    incs.insert(r);
}

for(int i=1;i<=n;i++){
    ans[i]=ans[i-1];
    if(incs.count(i)){
        ans[i]++;
    }
    cout<<ans[i]<<" ";
}
cout<<"\n";















}


















 



  

    







int32_t main(){

init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
//cin>>t;
t=1;
//SieveOfEratosthenes();
while(t--){

solve();

}
   
return 0;

}


















