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
  










int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};



const int N=2e5+10;


//int g[N];
void DFS(int root,int par,vector<vector<int>>&adj,vector<int>&depth,vector<int>&height) {

    for (auto child : adj[root]) {
        if (child!=par) {
            depth[child]=depth[root]+1;
            DFS(child,root,adj,depth,height);
            height[root]=max(height[root],height[child]+1);
      
        
        }
    }
    
}




bool isPerfectSquare(long double x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}



map<char,int>sym={{'(',-1},{')',+1}};
int isOk(string s){
    stack<char>st;
    int cnt=0;
    for(char bracket : s){
        if(sym[bracket]<0){
            st.push(bracket);
            cnt++;
        }
        else{
            if(st.empty())return cnt;
            char top=st.top();
            st.pop();
            if(sym[top]+sym[bracket]!=0){
                return cnt;
            }
            cnt++;

        }
    }
    if(!st.empty()){
        int cnt=cnt-(int)st.size();
    }
    return cnt;


}


int LongestPalindromicPrefix(string str)
{
 
    // Create temporary string
    string temp = str + '?';
 
    // Reverse the string str
    reverse(str.begin(), str.end());
 
    // Append string str to temp
    temp += str;
 
    // Find the length of string temp
    int n = temp.length();
 
    // lps[] array for string temp
    int lps[n];
 
    // Initialise every value with zero
    fill(lps, lps + n, 0);
 
    // Iterate the string temp
    for (int i = 1; i < n; i++) {
 
        // Length of longest prefix
        // till less than i
        int len = lps[i - 1];
 
        // Calculate length for i+1
        while (len > 0
               && temp[len] != temp[i]) {
            len = lps[len - 1];
        }
 
        // If character at current index
        // len are same then increment
        // length by 1
        if (temp[i] == temp[len]) {
            len++;
        }
 
        // Update the length at current
        // index to len
        lps[i] = len;
    }
 
    // Print the palindromic string of
    // max_len
    int size=lps[n-1]-0;
    if(size==1){
        return 0;
    }
    return size;
}

int highestPowerof2(int n)
{
   int p = (int)log2(n);
   return p;
}
 






















bool check(int p,int n,int cn){
    if(p==n){
        return true;
     }
    else{
        int non=n-cn;
        if(n>p){
            int mxp=cn/2;
            int dif=n-p;
            int pos=3*mxp;
            if(dif>=3 && pos>=dif && dif%3==0){
              return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }

return true;

}


int dp[200005][2];

void solve(){

int n;
cin>>n;
vector<int>a(n+1);
memset(dp,0,sizeof(dp));
rep(i,1,n+1){
cin>>a[i];
}
int ans=0;

for(int i=1;i<=n;i++)
        dp[i][0]=a[i]>a[i-1]?dp[i-1][0]+1:1,ans=max(ans,dp[i][0]);
    for(int i=n;i;i--)
        dp[i][1]=a[i]<a[i+1]?dp[i+1][1]+1:1;
    for(int i=1;i<=n;i++)
    ans=max(ans,a[i-1]<a[i+1]?dp[i-1][0]+dp[i+1][1]:1);
    cout<<ans<<endl;








}










































 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int32_t main(){
 
init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
t=1;
//SieveOfEratosthenes();
//BFS();

while(t--){
 
solve();
 
}
   
return 0;
 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 