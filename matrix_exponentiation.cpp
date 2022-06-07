/*
    author: kartik8800
	
	
	There is a simple directed graph G with N vertices, numbered 1,2,…,N.

For each i and j (1≤i,j≤N), you are given an integer a 
i,j
​
  that represents whether there is a directed edge from Vertex i to j. If a 
i,j
​
 =1, there is a directed edge from Vertex i to j; if a 
i,j
​
 =0, there is not.

Find the number of different directed paths of length K in G, modulo 10 
9
 +7. We will also count a path that traverses the same edge multiple times.
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
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

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B)
{
    int n = A.size();
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int x = 0; x < n; x++)
                res[i][j] = (res[i][j] + A[i][x]*B[x][j]) % mod;
        }
    }
    return res;
}
vector<vector<ll>> power(vector<vector<ll>> mat, ll exp)
{
    if(exp == 1)
        return mat;
    vector<vector<ll>> res = power(mat, exp/2);
    if(exp&1)
        return multiply(multiply(mat,res),res);
    else return multiply(res,res);
}

ll solve(vector<vector<ll>>& adj, ll k, int n)
{
    vector<vector<ll>> ak = power(adj, k);
    ll ans = 0;
    for(int i = 0; i <n; i++)
        for(int j = 0; j <n; j++)
            ans = (ans + ak[i][j]) % mod;
    return ans;
}

int main() {
   int n; 
   ll k;
   cin >> n >> k;
   vector<vector<ll>> adj(n, vector<ll>(n));
   for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];
   cout << solve(adj, k, n);
   return 0;
}
