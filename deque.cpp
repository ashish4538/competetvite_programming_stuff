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



int dp[3001][3001][2];

 
int  solve(vector<int>&v,int i,int j,int turn){

 if(i>j){
    return 0;
 }

 if(dp[i][j][turn]!=-1){
    return dp[i][j][turn];
 }

 if(turn ==1){
    return dp[i][j][turn]=max(v[i]+solve(v,i+1,j,0),v[j]+solve(v,i,j-1,0));
 }
 else{
    return dp[i][j][turn]=min(solve(v,i+1,j,1),solve(v,i,j-1,1));
 }




}










void solve(){
    memset(dp,-1,sizeof(dp));
 
    int n;
    cin>>n;
    vector<int>inp(n);
    int sum=0;
    for(int i=0;i<n;i++){
       cin>>inp[i];
       sum+=inp[i];
    }

    int x=solve(inp,0,n-1,1);
    int y=sum-x;
    cout<<(x-y);


}




int main(){

init_code();
ios::sync_with_stdio(0);
cin.tie(0);
int t;
//cin>>t;
t=1;
while(t--){

solve();

}
   
return 0;

}




















//https://www.ideone.com/YV2Zo1
//https://www.ideone.com/1FOyoQ
//https://www.ideone.com/oHbz79