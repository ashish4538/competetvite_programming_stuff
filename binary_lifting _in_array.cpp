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
   Consider the following string of infinite length: abc...xyzabc...xyz...

Let string B be the prefix of this string of length M. For e.g. if M=6, B= abcdef.

Vedansh calls a string X of length K special if it satisfies the following conditions:

B is a substring of X. Formally, for some 1≤L≤R≤K , X_{L...R}=B1≤L≤R≤K,X 
L...R
​
 =B
Vedansh has string A of length N (consisting of lowercase Latin letters only) and he wants to convert it into a special string. To do so he can perform the following operation:

Pick an i such that 1≤i≤|A|1≤i≤∣A∣ and delete A_iA 
i
​
 . The remaining parts of A are concatenated.
Since Vedansh is lazy, he wants to do this in minimum number of operations or determine if it can not be converted to a special string. Help Vedansh in doing so.
 
            
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
    
int n;cin>>n;
string s;cin>>s;
s="#"+s;//to make it 1 based
int m;cin>>m;
vector<int>occ(26,n+1),par(n+1);
for(int i=n;i>=1;i--){
    int nxt=(s[i]-'a'+1)%26;//a-->b for any char index next char just after greedily
    par[i]=occ[nxt];
    occ[s[i]-'a']=i;
}
int lg=log2(m)+1;
vector<vector<int>>dp(lg+1,vector<int>(n+2,n+1));

for(int i=n;i>=1;i--){
    dp[0][i]=par[i];//for 0 jump it will only its parent
    for(int j=1;j<=lg;j++){
        dp[j][i]=dp[j-1][dp[j-1][i]];//for 2^j jump it will its parent 2^j-1 + 2^j-1 jump
    }// for 2 it will its parent 1 jump or for 4 jump it will its parent j-1 jump + j-1 jump
}

int ans=1e18;
for(int i=1;i<=n;i++){
    if(s[i]!='a')
        continue;

    int u=i,m_copy=m-1;
    for(int j=lg;j>=0;j--){
        if((1<<j)<=m_copy)
            u=dp[j][u],m_copy-=1<<j;
        //breaking m-1 into powers of two
    }
    if(u!=n+1)
        ans=min(ans,u-i+1-m);
}

if(ans==1e18){
    ans=-1;
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
while(t--){

solve();

}
   
return 0;

}


















