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
 
  
 
bool cmp2(const pair<int,int> &a,
                   const pair<int,int> &b)
{ 
    if(a.ff==b.ff)return a.ss>b.ss;
 
       return a.ff<b.ff;
}
 

 
 
bool cmp(const pair<int,int> &a,
                   const pair<int,int> &b)
{ 
    if(a.ss==b.ss)return a.ff>b.ff;
 
       return a.ss<b.ss;
}
 
 
 
 
 
//ll mul(ll a,ll b,ll m){return (((a%m)*(b%m))%m+m)%m;}
int add(int a,int b,int m){return ((a%m)+(b%m))%m;}
 
 
 
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
 

bool isPowerofTwo(long long n)
{
    if (n == 0)
        return 0;
    if ((n & (~(n - 1))) == n)
        return 1;
    return 0;
}






   


bool cond(int mid,int mx,int s){
   int reald=s*mid;
   int mmx=mid*(mid-1);
   mmx/=2;
   reald-=mmx;
   //cout<<mid<<" ";
   return reald>=mx;
}



 
// Binary search
int GetCeilIndex(int arr[], vector<int>& T, int l, int r,
                 int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (arr[T[m]] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}
  
void  LongestIncreasingSubsequence(int arr[], int n)
{
    // Add boundary case, when array n is zero
    // Depend on smart pointers
 
    vector<int> tailIndices(n, 0); // Initialized with 0
    vector<int> prevIndices(n, -1); // initialized with -1
 
    int len = 1; // it will always point to empty location
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[tailIndices[0]]) {
            // new smallest value
            tailIndices[0] = i;
        }
        else if (arr[i] > arr[tailIndices[len - 1]]) {
            // arr[i] wants to extend largest subsequence
            prevIndices[i] = tailIndices[len - 1];
            tailIndices[len++] = i;
        }
        else {
            // arr[i] wants to be a potential condidate of
            // future subsequence
            // It will replace ceil value in tailIndices
            int pos = GetCeilIndex(arr, tailIndices, -1,
                                   len - 1, arr[i]);
 
            prevIndices[i] = tailIndices[pos - 1];
            tailIndices[pos] = i;
        }
    }
 
    cout<<len<<"\n";
    for (int i = tailIndices[len - 1]; i >= 0; i = prevIndices[i]){
        cout<<arr[i]<<" ";
    }
 
    return ;
}
 

vector<int> f(int n){
    vector<int>ans;
    while(n>0){
        int k=n%10;
        n/=10;
        ans.push_back(k);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


map<int,int>mp;

bool IsPowerOfTwo(int x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}
void mFactors(int n,int k)
{
    
    while (n % k == 0)
    {
        mp[k]++;
        n = n/k;

    }
    while(n%2==0){
        mp[2]++;
        n=n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            mp[i]++;
            n = n/i;
        }
    }
 

    if (n > 2)
        mp[n]++;
}


bool is_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}







void solve(){

int n;
cin>>n;
multiset<int>s,t;
int sum=0;
rep(i,0,n){
    int x;
    cin>>x;
    s.insert(x);
    sum+=x;
}
t.insert(sum);
bool flag=1;
while(t.size()){
    int x=*t.begin();
    t.erase(t.find(x));
    if(s.count(x)){
        s.erase(s.find(x));
        continue;
    }
    if(x==1){
        flag=0;
        break;
    }
    t.insert(x>>1),t.insert((x+1)>>1);
}
puts(flag?"YES":"NO");










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
 
 
 
 
 
 
 
 
 
 //C. Alice and the Cake
 //what did you learn?
 //Reverse Logic works 
 //multiset is best if you want deltion of elements(having non - distinct) compared  to map
//just do logic in reverse 
 
 
 
 
 