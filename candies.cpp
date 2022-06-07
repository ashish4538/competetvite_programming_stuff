

/*

There are N children, numbered 1,2,…,N.

They have decided to share K candies among themselves. Here, for each i (1≤i≤N), Child i must receive between 0 and ai candies (inclusive). Also, no candies should be left over.

Find the number of ways for them to share candies, modulo 109+7. Here, two ways are said to be different when there exists a child who receives a different number of candies.


*/
























#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n' 
#define int long long
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pii pair<int,int>
#define ff first
#define ss second


const int mod = 1e9+7;
const int inf = 1e17+1; 

int dp[101][100001];

int32_t main()
{
  ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
  #endif

  int n,k;
  cin>>n>>k;

  int a[n];
  for(int i=0;i<n;i++)
      cin>>a[i];
  
  //dp[i][j] = total number of ways to share j candies upto i children 

  //dp[i][0] = 1 number of ways to distribute 0 candies 
  //dp[first][0] = dp[first][1] = ... dp[first][ a[0] ] = 1 =>> no. of ways to share candies to 1st children 
  
  //dp[i][j] = dp[i-1][y] + dp[i-1][y-1] + ...... dp[i-1][y-a[i]] 
                                                 
  // O(n.K^2) => O(n.k)
  // prefix sum => dp[i]  = prefix_sum[y] - prefix_sum[y-a[i]-1]

  //ans => dp[last][k]

for(int i=0;i<=n;i++)
   dp[i][0] = 1;
 
 for(int j=0;j<=a[0];j++)
     dp[0][j] = 1;

 for(int i=1;i<n;i++)
 {
      int prefix_sum[k+1];
      prefix_sum[0] = dp[i-1][0];
     for(int j=1;j<=k;j++)
       prefix_sum[j] = (prefix_sum[j-1]+dp[i-1][j])%mod;
      
     for(int j=1;j<=k;j++)
     {
        if(j>a[i])
       {
       dp[i][j] = (prefix_sum[j] + mod - prefix_sum[j-a[i]-1])%mod;
       }
       else 
         dp[i][j] = prefix_sum[j];

     } 
 }
 cout<<dp[n-1][k]<<endl;

return 0;

}