#include <bits/stdc++.h>

using namespace std;


vector<vector<int>>adj;
vector<int>ing,ans;


bool check(int mid,int n){
    queue<int>q;
    vector<int>in=ing;
    vector<int>node(n+1);
    int cur=n;
    for(int i=1;i<=n;i++){
        if(in[i]<=mid){
            node[i]=cur;
            cur--;
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            in[v]--;
            if(node[v]!=0)continue;
            if(in[v]<=mid){
				//only nodes with indegree <=mid are allowed to participate
                node[v]=cur;
                cur--;
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(node[i]==0){
			//checking if all nodes has been assigned if started from indegree mid;
			//if not increase indegree and increase degreee and binary search again;
            return false;
        }
    }
    ans=node;
    return true;
    
}






int main()
{
    int tc;
    cin>>tc;
    while(tc--){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    ing.resize(n+1);
    for(int i=0;i<=n;i++)adj[i].clear(),ing[i]=0;
   ans.resize(n+1);
   
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ing[u]++,ing[v]++;
    }
    
    int l=0,r=n,opt=n;
     while(l<=r){
		 // basic binary search with predicate function
         int mid=(l+r)/2;
         if(check(mid,n)){
             opt=mid;
             r=mid-1;
         }
         else{
             l=mid+1;
         }
     }
        
        
    cout<<opt<<"\n";        
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }    
    cout<<"\n";
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
   
   return 0;
}