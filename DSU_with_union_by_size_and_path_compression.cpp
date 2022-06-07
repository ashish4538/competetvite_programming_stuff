#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
const int INF = 1e9 + 7;
 
 
 
 
 
 void make_set(ll v,vector<int>&parent,vector<int>&size) {
    parent[v] = v;
    size[v] = 1;
}
 
 
 
 
 
 
 ll get(vector<int>&parent,ll a){
	 
	 return (parent[a]==a)?a:get(parent,parent[a]);
	 
	 
 }
 
 void union(vector<ll>&parent,vector<ll>&rank,ll a,ll b){
	 
	a = get(parent,a);
    b = get(parent,b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
	 
 }
	 
 
 
 
 
 
 
 
 void solve(){
   
   
   int n,m;
   cin>>n>>m;
   vector<ll>parent(n+1);
   vector<ll>rank(n+1,0);
   for(int i=0;i<n;i++){
	   make_set(i,parent,size);
   }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
 }
 
 
 
 
 
 
int main(){
 solve();
   return 0;
}