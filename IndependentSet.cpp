/*Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 100 points

Problem Statement
There is a tree with N vertices, numbered 1,2,…,N. For each i (1≤i≤N−1), the i-th edge connects Vertex x 
i and y i
Taro has decided to paint each vertex in white or black. Here, it is not allowed to paint two adjacent vertices both in black.
Find the number of ways in which the vertices can be painted, modulo 10 9+7.

Constraints
All values in input are integers.
1≤N≤10 
5
 
1≤x 
i
​
 ,y 
i
​
 ≤N
The given graph is a tree


*/















#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pr pair<int, int>
#define vect vector
#define pb push_back
#define wgr vector<pair<int, int>>
#define lowestbit(x) __builtin_ffs(x)  //re}turns 1+index of(lowest bit)
#define highestbit(x) __builtin_clz(x) //returns number of 0's to left of MST
#define is(x) cerr << #x << " is " << x << endl;
#define sortv sort(v1.begin(), v1.end());
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define inputarr loop(i, 0, n) cin >> ar[i];
int mod = 1e9 + 7;
ll inf = 1e18;
int mx = -1;
ll mn = 1e18;

void init_code(){
     #ifndef ONLINE_JUDGE
     freopen("input1.txt","r",stdin);
     freopen("output1.txt","w",stdout);
     #endif
}




long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}



const int N=1e5+5;


vector<int>tree[N];

ll dp[N][2];

void dfs(ll v,  ll pa){
    dp[v][0] = 1 ;
    dp[v][1] = 1 ;
    for(auto to : tree[v]){
        if(to != pa){
            dfs(to ,  v) ; 
            dp[v][0] *= (dp[to][0]%mod + dp[to][1]%mod)%mod ;
            //if the parent is white the children can white or black (multiplied for all the children);

            dp[v][1] *= dp[to][0] % mod ;
            //if the parent is black the only optionn is white child and multiplied for all the possibilites
            dp[v][0] %= mod ;
            dp[v][1] %= mod ;
        }
    }
}



void solve(){
  
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++){
    int x,y;
    cin>>x>>y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }

 dfs(1 , -1) ;
 //children must be pressent so multiplication but color can be white "or" black so addition is between them
    cout << (dp[1][0] + dp[1][1]) % mod << "\n";



 



  

    


}




int main(){

init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
t=1;

while(t--){

solve();

}
   
return 0;

}




















//https://www.ideone.com/YV2Zo1
//https://www.ideone.com/1FOyoQ
//https://www.ideone.com/oHbz79