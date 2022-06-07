#include <bits/stdc++.h>
using namespace std;

int main(){
  long long t;
  cin>>t;
  while(t--){
int n,k;
cin>>n>>k;
map<int,vector<int>>adj;
map<int,int>deg;
map<int,int>vis;
for(int i=1;i<=n-1;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    deg[x]++;
    deg[y]++;
}
queue<pair<int,int>>q;
for(int i=1;i<=n;i++){
if(deg[i]<=1){
    q.push({i,0});
    
     }
}
int ans=n;
while(q.size()){
  pair<int,int> p=q.front();
  if(p.second==k)break;
  q.pop();
  vis[p.first]=true;
  ans--;
  for(auto i:adj[p.first]){
    if(!vis[i]){
      if(deg[i]==2){
          q.push({i,p.second+1});
          //It is not sending degrees to pair->second but operations it would be required for it to be removed .
      }
      deg[i]--;
      //  reducing the degrees as the the node it is connected to will be losing the current node.
      
      }
  }
}
cout<<ans<<endl;
 }
 return 0;
}