/*
   There are N slimes lining up in a row. Initially, the i-th slime from the left has a size of ai Taro is trying to combine all the slimes into a larger slime. He will perform the following operation repeatedly until there is only one slime:

Choose two adjacent slimes, and combine them into a new slime. The new slime has a size of x+y, where x and y are the sizes of the slimes before combining them. Here, a cost of x+y is incurred. The positional relationship of the slimes does not change while combining slimes.
Find the minimum possible total cost incurred.
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(ll i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x 
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll dp[3001][3001];
ll sum[3001][3001];

ll solve(vector<int>& v, int i, int j)
{
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    ll minCost = inf;
    for(int k = i; k < j; k++)
    {
            minCost = min(minCost, sum[i][j] + solve(v, i, k) + solve(v, k + 1, j));
    }
    return dp[i][j] = minCost;
}

void preprocess(vector<int>& v, int n)
{
    for(int i = 1; i  <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            sum[i][j] = v[j] + ((j == i) ? 0 : sum[i][j-1]);
        }
    }
}
int main() {
   int n;
   cin >> n ;
   memset(dp, -1, sizeof dp);
   vector<int> v(n+1);
   for(int i = 1; i <= n; i++)
        cin>>v[i];
    preprocess(v,n);
   cout<<solve(v, 1, n);
   return 0;
}
